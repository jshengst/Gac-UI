#include "WfEmitter.h"

namespace vl
{
	namespace workflow
	{
		namespace emitter
		{
			using namespace collections;
			using namespace reflection;
			using namespace reflection::description;
			using namespace analyzer;
			using namespace runtime;

			typedef WfInstruction Ins;

#define INSTRUCTION(X) context.AddInstruction(node, X)
#define FILL_LABEL_TO_INS(LABEL, INS) context.assembly->instructions[LABEL].indexParameter = INS
#define FILL_LABEL_TO_CURRENT(LABEL) FILL_LABEL_TO_INS(LABEL, context.assembly->instructions.Count())
#define EXIT_CODE(X) context.AddExitInstruction(node, X)

/***********************************************************************
GenerateInstructions(Statement)
***********************************************************************/

			class GenerateStatementInstructionsVisitor : public Object, public WfStatement::IVisitor
			{
			public:
				WfCodegenContext&						context;

				GenerateStatementInstructionsVisitor(WfCodegenContext& _context)
					:context(_context)
				{
				}

				void ApplyExitCode(Ptr<WfCodegenScopeContext> scopeContext)
				{
					context.ApplyExitInstructions(scopeContext);
					if (scopeContext->exitStatement)
					{
						GenerateStatementInstructions(context, scopeContext->exitStatement);
					}
				}

				void ApplyCurrentScopeExitCode()
				{
					auto scopeContext = context.functionContext->GetCurrentScopeContext();
					ApplyExitCode(scopeContext);
				}

				void InlineScopeExitCode(WfCodegenScopeType untilScopeType, bool exclusive, const WString& name = WString::Empty)
				{
					vint index = context.functionContext->scopeContextStack.Count() - 1;
					while (index >= 0)
					{
						auto scopeContext = context.functionContext->scopeContextStack[index];
						bool found = false;
						if (scopeContext->type == untilScopeType)
						{
							if (name == L"" || scopeContext->name == name)
							{
								found = true;
							}
						}

						if (exclusive && found) break;
						ApplyExitCode(scopeContext);
						if (!exclusive && found) break;
						index--;
					}
				}

				void Visit(WfBreakStatement* node)override
				{
					InlineScopeExitCode(WfCodegenScopeType::Loop, false);
					context.functionContext->GetCurrentScopeContext(WfCodegenScopeType::Loop)->breakInstructions.Add(INSTRUCTION(Ins::Jump(-1)));
				}

				void Visit(WfContinueStatement* node)override
				{
					InlineScopeExitCode(WfCodegenScopeType::Loop, true);
					context.functionContext->GetCurrentScopeContext(WfCodegenScopeType::Loop)->continueInstructions.Add(INSTRUCTION(Ins::Jump(-1)));
				}

				void Visit(WfReturnStatement* node)override
				{
					InlineScopeExitCode(WfCodegenScopeType::Function, false);
					if (node->expression)
					{
						GenerateExpressionInstructions(context, node->expression);
					}
					else
					{
						INSTRUCTION(Ins::LoadValue({}));
					}
					INSTRUCTION(Ins::Return());
				}

				void Visit(WfDeleteStatement* node)override
				{
					GenerateExpressionInstructions(context, node->expression);
					INSTRUCTION(Ins::DeleteRawPtr());
				}

				void Visit(WfRaiseExceptionStatement* node)override
				{
					if (node->expression)
					{
						GenerateExpressionInstructions(context, node->expression);
					}
					else
					{
						auto scope = context.manager->nodeScopes[node];
						while (scope)
						{
							if (auto tryCatch = scope->ownerNode.Cast<WfTryStatement>())
							{
								if (tryCatch->name.value != L"")
								{
									auto symbol = scope->symbols[tryCatch->name.value][0].Obj();
									vint index = context.functionContext->localVariables[symbol];
									INSTRUCTION(Ins::LoadLocalVar(index));
									break;
								}
							}
							scope = scope->parentScope;
						}
					}
					INSTRUCTION(Ins::RaiseException());
				}

				void Visit(WfIfStatement* node)override
				{
					vint variableIndex = -1;

					GenerateExpressionInstructions(context, node->expression);
					if (node->name.value != L"")
					{
						auto scope = context.manager->nodeScopes[node];
						auto symbol = scope->symbols[node->name.value][0];
						auto function = context.functionContext->function;
						variableIndex = function->argumentNames.Count() + function->localVariableNames.Add(L"<if>" + node->name.value);
						context.functionContext->localVariables.Add(symbol.Obj(), variableIndex);

						GenerateTypeCastInstructions(context, symbol->typeInfo, false, node->expression.Obj());
						INSTRUCTION(Ins::StoreLocalVar(variableIndex));
						INSTRUCTION(Ins::LoadLocalVar(variableIndex));
						INSTRUCTION(Ins::LoadValue({}));
						INSTRUCTION(Ins::CompareReference());
					}
					else
					{
						INSTRUCTION(Ins::OpNot(WfInsType::Bool));
					}
					vint fillElseIndex = INSTRUCTION(Ins::JumpIf(-1));

					GenerateStatementInstructions(context, node->trueBranch);
					if (variableIndex != -1)
					{
						INSTRUCTION(Ins::LoadValue({}));
						INSTRUCTION(Ins::StoreLocalVar(variableIndex));
					}
					vint fillEndIndex = INSTRUCTION(Ins::Jump(-1));
					FILL_LABEL_TO_CURRENT(fillElseIndex);

					if (node->falseBranch)
					{
						GenerateStatementInstructions(context, node->falseBranch);
					}
					FILL_LABEL_TO_CURRENT(fillEndIndex);
				}

				void Visit(WfWhileStatement* node)override
				{
					vint continueLabelIndex = -1;
					vint breakLabelIndex = -1;
					vint loopLabelIndex = -1;
					auto loopContext = context.functionContext->PushScopeContext(WfCodegenScopeType::Loop);

					loopLabelIndex = context.assembly->instructions.Count();
					continueLabelIndex = context.assembly->instructions.Count();
					GenerateExpressionInstructions(context, node->condition);
					INSTRUCTION(Ins::OpNot(WfInsType::Bool));
					loopContext->breakInstructions.Add(INSTRUCTION(Ins::JumpIf(-1)));
					GenerateStatementInstructions(context, node->statement);
					INSTRUCTION(Ins::Jump(loopLabelIndex));
					breakLabelIndex = context.assembly->instructions.Count();

					for (auto index : loopContext->continueInstructions)
					{
						FILL_LABEL_TO_INS(index, continueLabelIndex);
					}
					for (auto index : loopContext->breakInstructions)
					{
						FILL_LABEL_TO_INS(index, breakLabelIndex);
					}
					context.functionContext->PopScopeContext();
				}

				Pair<vint, vint> GenerateTryProtected(WfStatement* node, Ptr<WfStatement> protectedStatement, Ptr<WfStatement> finallyStatement)
				{
					auto catchContext = context.functionContext->PushScopeContext(WfCodegenScopeType::TryCatch);
					EXIT_CODE(Ins::UninstallTry(0));
					catchContext->exitStatement = finallyStatement;

					vint trap = INSTRUCTION(Ins::InstallTry(-1));
					GenerateStatementInstructions(context, protectedStatement);
					context.functionContext->PopScopeContext();
					INSTRUCTION(Ins::UninstallTry(0));
					vint finish = INSTRUCTION(Ins::Jump(-1));

					return{ trap,finish };
				}

				vint GenerateExceptionVariable(WfTryStatement* node)
				{
					WfLexicalSymbol* exceptionSymbol = nullptr;
					WString exceptionName;
					if (node->catchStatement)
					{
						auto scope = context.manager->nodeScopes[node].Obj();
						exceptionSymbol = scope->symbols[node->name.value][0].Obj();
						exceptionName = L"<catch>" + node->name.value;
					}
					else
					{
						exceptionName = L"<try-finally-exception>";
					}

					auto function = context.functionContext->function;
					vint variableIndex = function->argumentNames.Count() + function->localVariableNames.Add(L"<catch>" + node->name.value);
					if (exceptionSymbol)
					{
						context.functionContext->localVariables.Add(exceptionSymbol, variableIndex);
					}

					return variableIndex;
				}

				void GenerateTrap(WfTryStatement* node, vint variableIndex, Pair<vint, vint> trap)
				{
					FILL_LABEL_TO_CURRENT(trap.key);
					INSTRUCTION(Ins::LoadException());
					INSTRUCTION(Ins::StoreLocalVar(variableIndex));
				}

				void GenerateFinallyAndRaise(WfTryStatement* node, vint variableIndex)
				{
					GenerateStatementInstructions(context, node->finallyStatement);
					INSTRUCTION(Ins::LoadLocalVar(variableIndex));
					INSTRUCTION(Ins::RaiseException());
				}

				void Visit(WfTryStatement* node)override
				{
					// try
					auto trap1 = GenerateTryProtected(node, node->protectedStatement, node->finallyStatement);
					Pair<vint, vint> trap2 = { -1,-1 };
					auto variableIndex = GenerateExceptionVariable(node);

					// catch
					{
						GenerateTrap(node, variableIndex, trap1);
						if (node->catchStatement)
						{
							if (node->finallyStatement)
							{
								trap2 = GenerateTryProtected(node, node->catchStatement, node->finallyStatement);
								GenerateTrap(node, variableIndex, trap2);
								GenerateFinallyAndRaise(node, variableIndex);
							}
							else
							{
								GenerateStatementInstructions(context, node->catchStatement);
							}
						}
						else
						{
							GenerateFinallyAndRaise(node, variableIndex);
						}
					}

					// finally
					FILL_LABEL_TO_CURRENT(trap1.value);
					if (trap2.value != -1)
					{
						FILL_LABEL_TO_CURRENT(trap2.value);
					}
					if (node->finallyStatement)
					{
						GenerateStatementInstructions(context, node->finallyStatement);
					}
				}

				void Visit(WfBlockStatement* node)override
				{
					Ptr<WfCodegenScopeContext> blockContext;
					if (node->endLabel.value != L"")
					{
						blockContext = context.functionContext->PushScopeContext(WfCodegenScopeType::Block, node->endLabel.value);
					}

					for (auto statement : node->statements)
					{
						GenerateStatementInstructions(context, statement);
					}

					if (blockContext)
					{
						vint breakLabelIndex = context.assembly->instructions.Count();
						for (auto index : blockContext->breakInstructions)
						{
							FILL_LABEL_TO_INS(index, breakLabelIndex);
						}
						context.functionContext->PopScopeContext();
					}
				}

				void Visit(WfGotoStatement* node)override
				{
					InlineScopeExitCode(WfCodegenScopeType::Block, false, node->label.value);
					context.functionContext->GetCurrentScopeContext(WfCodegenScopeType::Block, node->label.value)->breakInstructions.Add(INSTRUCTION(Ins::Jump(-1)));
				}

				void Visit(WfExpressionStatement* node)override
				{
					GenerateExpressionInstructions(context, node->expression);
					INSTRUCTION(Ins::Pop());
				}

				void Visit(WfVariableStatement* node)override
				{
					auto manager = context.manager;
					auto scope = manager->nodeScopes[node->variable.Obj()];
					auto symbol = scope->symbols[node->variable->name.value][0].Obj();
					auto function = context.functionContext->function;
					vint index = function->argumentNames.Count() + function->localVariableNames.Add(node->variable->name.value);
					context.functionContext->localVariables.Add(symbol, index);

					GenerateExpressionInstructions(context, node->variable->expression);
					INSTRUCTION(Ins::StoreLocalVar(index));
				}

				void Visit(WfVirtualCseStatement* node)override
				{
					GenerateStatementInstructions(context, node->expandedStatement);
				}

				void Visit(WfCoroutineStatement* node)override
				{
					CHECK_FAIL(L"GenerateStatementInstructionsVisitor::Visit(WfCoroutineStatement*)#Internal error, All coroutine statements do not emit instructions.");
				}

				void Visit(WfStateMachineStatement* node)override
				{
					CHECK_FAIL(L"GenerateStatementInstructionsVisitor::Visit(WfStateMachineStatement*)#Internal error, All state machine statements do not emit instructions.");
				}
			};

#undef EXIT_CODE
#undef FILL_LABEL_TO_CURRENT
#undef FILL_LABEL_TO_INS
#undef INSTRUCTION

			void GenerateStatementInstructions(WfCodegenContext& context, Ptr<WfStatement> statement)
			{
				GenerateStatementInstructionsVisitor visitor(context);
				statement->Accept(&visitor);
			}
		}
	}
}