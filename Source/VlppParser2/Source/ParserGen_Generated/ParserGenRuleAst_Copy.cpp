/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:RuleAst
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "ParserGenRuleAst_Copy.h"

namespace vl::glr::parsergen::copy_visitor
{
	void RuleAstVisitor::CopyFields(GlrAlternativeSyntax* from, GlrAlternativeSyntax* to)
	{
		CopyFields(static_cast<GlrSyntax*>(from), static_cast<GlrSyntax*>(to));
		to->first = CopyNode(from->first.Obj());
		to->second = CopyNode(from->second.Obj());
	}

	void RuleAstVisitor::CopyFields(GlrAndCondition* from, GlrAndCondition* to)
	{
		CopyFields(static_cast<GlrCondition*>(from), static_cast<GlrCondition*>(to));
		to->first = CopyNode(from->first.Obj());
		to->second = CopyNode(from->second.Obj());
	}

	void RuleAstVisitor::CopyFields(GlrAssignment* from, GlrAssignment* to)
	{
		to->field = from->field;
		to->type = from->type;
		to->value = from->value;
	}

	void RuleAstVisitor::CopyFields(GlrClause* from, GlrClause* to)
	{
	}

	void RuleAstVisitor::CopyFields(GlrCondition* from, GlrCondition* to)
	{
	}

	void RuleAstVisitor::CopyFields(GlrCreateClause* from, GlrCreateClause* to)
	{
		CopyFields(static_cast<GlrClause*>(from), static_cast<GlrClause*>(to));
		for (auto&& listItem : from->assignments)
		{
			to->assignments.Add(CopyNode(listItem.Obj()));
		}
		to->syntax = CopyNode(from->syntax.Obj());
		to->type = from->type;
	}

	void RuleAstVisitor::CopyFields(GlrLeftRecursionInjectClause* from, GlrLeftRecursionInjectClause* to)
	{
		CopyFields(static_cast<GlrClause*>(from), static_cast<GlrClause*>(to));
		to->continuation = CopyNode(from->continuation.Obj());
		to->rule = CopyNode(from->rule.Obj());
	}

	void RuleAstVisitor::CopyFields(GlrLeftRecursionInjectContinuation* from, GlrLeftRecursionInjectContinuation* to)
	{
		to->configuration = from->configuration;
		for (auto&& listItem : from->flags)
		{
			to->flags.Add(CopyNode(listItem.Obj()));
		}
		for (auto&& listItem : from->injectionTargets)
		{
			to->injectionTargets.Add(CopyNode(listItem.Obj()));
		}
		to->type = from->type;
	}

	void RuleAstVisitor::CopyFields(GlrLeftRecursionPlaceholder* from, GlrLeftRecursionPlaceholder* to)
	{
		to->flag = from->flag;
	}

	void RuleAstVisitor::CopyFields(GlrLeftRecursionPlaceholderClause* from, GlrLeftRecursionPlaceholderClause* to)
	{
		CopyFields(static_cast<GlrClause*>(from), static_cast<GlrClause*>(to));
		for (auto&& listItem : from->flags)
		{
			to->flags.Add(CopyNode(listItem.Obj()));
		}
	}

	void RuleAstVisitor::CopyFields(GlrLoopSyntax* from, GlrLoopSyntax* to)
	{
		CopyFields(static_cast<GlrSyntax*>(from), static_cast<GlrSyntax*>(to));
		to->delimiter = CopyNode(from->delimiter.Obj());
		to->syntax = CopyNode(from->syntax.Obj());
	}

	void RuleAstVisitor::CopyFields(GlrNotCondition* from, GlrNotCondition* to)
	{
		CopyFields(static_cast<GlrCondition*>(from), static_cast<GlrCondition*>(to));
		to->condition = CopyNode(from->condition.Obj());
	}

	void RuleAstVisitor::CopyFields(GlrOptionalSyntax* from, GlrOptionalSyntax* to)
	{
		CopyFields(static_cast<GlrSyntax*>(from), static_cast<GlrSyntax*>(to));
		to->priority = from->priority;
		to->syntax = CopyNode(from->syntax.Obj());
	}

	void RuleAstVisitor::CopyFields(GlrOrCondition* from, GlrOrCondition* to)
	{
		CopyFields(static_cast<GlrCondition*>(from), static_cast<GlrCondition*>(to));
		to->first = CopyNode(from->first.Obj());
		to->second = CopyNode(from->second.Obj());
	}

	void RuleAstVisitor::CopyFields(GlrPartialClause* from, GlrPartialClause* to)
	{
		CopyFields(static_cast<GlrClause*>(from), static_cast<GlrClause*>(to));
		for (auto&& listItem : from->assignments)
		{
			to->assignments.Add(CopyNode(listItem.Obj()));
		}
		to->syntax = CopyNode(from->syntax.Obj());
		to->type = from->type;
	}

	void RuleAstVisitor::CopyFields(GlrPrefixMergeClause* from, GlrPrefixMergeClause* to)
	{
		CopyFields(static_cast<GlrClause*>(from), static_cast<GlrClause*>(to));
		to->rule = CopyNode(from->rule.Obj());
	}

	void RuleAstVisitor::CopyFields(GlrPushConditionSyntax* from, GlrPushConditionSyntax* to)
	{
		CopyFields(static_cast<GlrSyntax*>(from), static_cast<GlrSyntax*>(to));
		for (auto&& listItem : from->switches)
		{
			to->switches.Add(CopyNode(listItem.Obj()));
		}
		to->syntax = CopyNode(from->syntax.Obj());
	}

	void RuleAstVisitor::CopyFields(GlrRefCondition* from, GlrRefCondition* to)
	{
		CopyFields(static_cast<GlrCondition*>(from), static_cast<GlrCondition*>(to));
		to->name = from->name;
	}

	void RuleAstVisitor::CopyFields(GlrRefSyntax* from, GlrRefSyntax* to)
	{
		CopyFields(static_cast<GlrSyntax*>(from), static_cast<GlrSyntax*>(to));
		to->field = from->field;
		to->literal = from->literal;
		to->refType = from->refType;
	}

	void RuleAstVisitor::CopyFields(GlrReuseClause* from, GlrReuseClause* to)
	{
		CopyFields(static_cast<GlrClause*>(from), static_cast<GlrClause*>(to));
		for (auto&& listItem : from->assignments)
		{
			to->assignments.Add(CopyNode(listItem.Obj()));
		}
		to->syntax = CopyNode(from->syntax.Obj());
	}

	void RuleAstVisitor::CopyFields(GlrRule* from, GlrRule* to)
	{
		to->attParser = from->attParser;
		to->attPublic = from->attPublic;
		for (auto&& listItem : from->clauses)
		{
			to->clauses.Add(CopyNode(listItem.Obj()));
		}
		to->name = from->name;
		to->type = from->type;
	}

	void RuleAstVisitor::CopyFields(GlrSequenceSyntax* from, GlrSequenceSyntax* to)
	{
		CopyFields(static_cast<GlrSyntax*>(from), static_cast<GlrSyntax*>(to));
		to->first = CopyNode(from->first.Obj());
		to->second = CopyNode(from->second.Obj());
	}

	void RuleAstVisitor::CopyFields(GlrSwitchItem* from, GlrSwitchItem* to)
	{
		to->name = from->name;
		to->value = from->value;
	}

	void RuleAstVisitor::CopyFields(GlrSyntax* from, GlrSyntax* to)
	{
	}

	void RuleAstVisitor::CopyFields(GlrSyntaxFile* from, GlrSyntaxFile* to)
	{
		for (auto&& listItem : from->rules)
		{
			to->rules.Add(CopyNode(listItem.Obj()));
		}
		for (auto&& listItem : from->switches)
		{
			to->switches.Add(CopyNode(listItem.Obj()));
		}
	}

	void RuleAstVisitor::CopyFields(GlrTestConditionBranch* from, GlrTestConditionBranch* to)
	{
		to->condition = CopyNode(from->condition.Obj());
		to->syntax = CopyNode(from->syntax.Obj());
	}

	void RuleAstVisitor::CopyFields(GlrTestConditionSyntax* from, GlrTestConditionSyntax* to)
	{
		CopyFields(static_cast<GlrSyntax*>(from), static_cast<GlrSyntax*>(to));
		for (auto&& listItem : from->branches)
		{
			to->branches.Add(CopyNode(listItem.Obj()));
		}
	}

	void RuleAstVisitor::CopyFields(GlrUseSyntax* from, GlrUseSyntax* to)
	{
		CopyFields(static_cast<GlrSyntax*>(from), static_cast<GlrSyntax*>(to));
		to->name = from->name;
	}

	void RuleAstVisitor::Visit(GlrSwitchItem* node)
	{
		auto newNode = vl::Ptr(new GlrSwitchItem);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrTestConditionBranch* node)
	{
		auto newNode = vl::Ptr(new GlrTestConditionBranch);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrAssignment* node)
	{
		auto newNode = vl::Ptr(new GlrAssignment);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrLeftRecursionPlaceholder* node)
	{
		auto newNode = vl::Ptr(new GlrLeftRecursionPlaceholder);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrLeftRecursionInjectContinuation* node)
	{
		auto newNode = vl::Ptr(new GlrLeftRecursionInjectContinuation);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrRule* node)
	{
		auto newNode = vl::Ptr(new GlrRule);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrSyntaxFile* node)
	{
		auto newNode = vl::Ptr(new GlrSyntaxFile);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrRefCondition* node)
	{
		auto newNode = vl::Ptr(new GlrRefCondition);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrNotCondition* node)
	{
		auto newNode = vl::Ptr(new GlrNotCondition);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrAndCondition* node)
	{
		auto newNode = vl::Ptr(new GlrAndCondition);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrOrCondition* node)
	{
		auto newNode = vl::Ptr(new GlrOrCondition);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrRefSyntax* node)
	{
		auto newNode = vl::Ptr(new GlrRefSyntax);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrUseSyntax* node)
	{
		auto newNode = vl::Ptr(new GlrUseSyntax);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrLoopSyntax* node)
	{
		auto newNode = vl::Ptr(new GlrLoopSyntax);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrOptionalSyntax* node)
	{
		auto newNode = vl::Ptr(new GlrOptionalSyntax);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrSequenceSyntax* node)
	{
		auto newNode = vl::Ptr(new GlrSequenceSyntax);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrAlternativeSyntax* node)
	{
		auto newNode = vl::Ptr(new GlrAlternativeSyntax);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrPushConditionSyntax* node)
	{
		auto newNode = vl::Ptr(new GlrPushConditionSyntax);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrTestConditionSyntax* node)
	{
		auto newNode = vl::Ptr(new GlrTestConditionSyntax);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrCreateClause* node)
	{
		auto newNode = vl::Ptr(new GlrCreateClause);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrPartialClause* node)
	{
		auto newNode = vl::Ptr(new GlrPartialClause);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrReuseClause* node)
	{
		auto newNode = vl::Ptr(new GlrReuseClause);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrLeftRecursionPlaceholderClause* node)
	{
		auto newNode = vl::Ptr(new GlrLeftRecursionPlaceholderClause);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrLeftRecursionInjectClause* node)
	{
		auto newNode = vl::Ptr(new GlrLeftRecursionInjectClause);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void RuleAstVisitor::Visit(GlrPrefixMergeClause* node)
	{
		auto newNode = vl::Ptr(new GlrPrefixMergeClause);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	vl::Ptr<GlrCondition> RuleAstVisitor::CopyNode(GlrCondition* node)
	{
		if (!node) return nullptr;
		node->Accept(static_cast<GlrCondition::IVisitor*>(this));
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrCondition>();
	}

	vl::Ptr<GlrSyntax> RuleAstVisitor::CopyNode(GlrSyntax* node)
	{
		if (!node) return nullptr;
		node->Accept(static_cast<GlrSyntax::IVisitor*>(this));
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrSyntax>();
	}

	vl::Ptr<GlrClause> RuleAstVisitor::CopyNode(GlrClause* node)
	{
		if (!node) return nullptr;
		node->Accept(static_cast<GlrClause::IVisitor*>(this));
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrClause>();
	}

	vl::Ptr<GlrSwitchItem> RuleAstVisitor::CopyNode(GlrSwitchItem* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrSwitchItem>();
	}

	vl::Ptr<GlrTestConditionBranch> RuleAstVisitor::CopyNode(GlrTestConditionBranch* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrTestConditionBranch>();
	}

	vl::Ptr<GlrAssignment> RuleAstVisitor::CopyNode(GlrAssignment* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrAssignment>();
	}

	vl::Ptr<GlrLeftRecursionPlaceholder> RuleAstVisitor::CopyNode(GlrLeftRecursionPlaceholder* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrLeftRecursionPlaceholder>();
	}

	vl::Ptr<GlrLeftRecursionInjectContinuation> RuleAstVisitor::CopyNode(GlrLeftRecursionInjectContinuation* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrLeftRecursionInjectContinuation>();
	}

	vl::Ptr<GlrRule> RuleAstVisitor::CopyNode(GlrRule* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrRule>();
	}

	vl::Ptr<GlrSyntaxFile> RuleAstVisitor::CopyNode(GlrSyntaxFile* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrSyntaxFile>();
	}

	vl::Ptr<GlrAlternativeSyntax> RuleAstVisitor::CopyNode(GlrAlternativeSyntax* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrSyntax*>(node)).Cast<GlrAlternativeSyntax>();
	}

	vl::Ptr<GlrAndCondition> RuleAstVisitor::CopyNode(GlrAndCondition* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrCondition*>(node)).Cast<GlrAndCondition>();
	}

	vl::Ptr<GlrCreateClause> RuleAstVisitor::CopyNode(GlrCreateClause* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrClause*>(node)).Cast<GlrCreateClause>();
	}

	vl::Ptr<GlrLeftRecursionInjectClause> RuleAstVisitor::CopyNode(GlrLeftRecursionInjectClause* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrClause*>(node)).Cast<GlrLeftRecursionInjectClause>();
	}

	vl::Ptr<GlrLeftRecursionPlaceholderClause> RuleAstVisitor::CopyNode(GlrLeftRecursionPlaceholderClause* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrClause*>(node)).Cast<GlrLeftRecursionPlaceholderClause>();
	}

	vl::Ptr<GlrLoopSyntax> RuleAstVisitor::CopyNode(GlrLoopSyntax* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrSyntax*>(node)).Cast<GlrLoopSyntax>();
	}

	vl::Ptr<GlrNotCondition> RuleAstVisitor::CopyNode(GlrNotCondition* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrCondition*>(node)).Cast<GlrNotCondition>();
	}

	vl::Ptr<GlrOptionalSyntax> RuleAstVisitor::CopyNode(GlrOptionalSyntax* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrSyntax*>(node)).Cast<GlrOptionalSyntax>();
	}

	vl::Ptr<GlrOrCondition> RuleAstVisitor::CopyNode(GlrOrCondition* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrCondition*>(node)).Cast<GlrOrCondition>();
	}

	vl::Ptr<GlrPartialClause> RuleAstVisitor::CopyNode(GlrPartialClause* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrClause*>(node)).Cast<GlrPartialClause>();
	}

	vl::Ptr<GlrPrefixMergeClause> RuleAstVisitor::CopyNode(GlrPrefixMergeClause* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrClause*>(node)).Cast<GlrPrefixMergeClause>();
	}

	vl::Ptr<GlrPushConditionSyntax> RuleAstVisitor::CopyNode(GlrPushConditionSyntax* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrSyntax*>(node)).Cast<GlrPushConditionSyntax>();
	}

	vl::Ptr<GlrRefCondition> RuleAstVisitor::CopyNode(GlrRefCondition* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrCondition*>(node)).Cast<GlrRefCondition>();
	}

	vl::Ptr<GlrRefSyntax> RuleAstVisitor::CopyNode(GlrRefSyntax* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrSyntax*>(node)).Cast<GlrRefSyntax>();
	}

	vl::Ptr<GlrReuseClause> RuleAstVisitor::CopyNode(GlrReuseClause* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrClause*>(node)).Cast<GlrReuseClause>();
	}

	vl::Ptr<GlrSequenceSyntax> RuleAstVisitor::CopyNode(GlrSequenceSyntax* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrSyntax*>(node)).Cast<GlrSequenceSyntax>();
	}

	vl::Ptr<GlrTestConditionSyntax> RuleAstVisitor::CopyNode(GlrTestConditionSyntax* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrSyntax*>(node)).Cast<GlrTestConditionSyntax>();
	}

	vl::Ptr<GlrUseSyntax> RuleAstVisitor::CopyNode(GlrUseSyntax* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrSyntax*>(node)).Cast<GlrUseSyntax>();
	}

}
