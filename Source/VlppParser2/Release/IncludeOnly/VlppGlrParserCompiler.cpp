﻿/***********************************************************************
THIS FILE IS AUTOMATICALLY GENERATED. DO NOT MODIFY
DEVELOPER: Zihan Chen(vczh)
***********************************************************************/
#include "VlppGlrParserCompiler.h"

#include "..\..\Source\Ast\AstCppGen.cpp"
#include "..\..\Source\Ast\AstCppGen_Assembler.cpp"
#include "..\..\Source\Ast\AstCppGen_Builder.cpp"
#include "..\..\Source\Ast\AstCppGen_Classes.cpp"
#include "..\..\Source\Ast\AstCppGen_CopyVisitor.cpp"
#include "..\..\Source\Ast\AstCppGen_EmptyVisitor.cpp"
#include "..\..\Source\Ast\AstCppGen_JsonVisitor.cpp"
#include "..\..\Source\Ast\AstCppGen_TraverseVisitor.cpp"
#include "..\..\Source\Ast\AstSymbol.cpp"
#include "..\..\Source\Ast\AstSymbol_CreateParserGenRuleAst.cpp"
#include "..\..\Source\Ast\AstSymbol_CreateParserGenTypeAst.cpp"
#include "..\..\Source\Lexer\LexerCppGen.cpp"
#include "..\..\Source\Lexer\LexerSymbol.cpp"
#include "..\..\Source\Lexer\LexerSymbol_CreateParserGenLexer.cpp"
#include "..\..\Source\ParserGen\CompileAst.cpp"
#include "..\..\Source\ParserGen\CompileLexer.cpp"
#include "..\..\Source\ParserGen\CompileSyntax.cpp"
#include "..\..\Source\ParserGen\CompileSyntax_CalculateFirstSet.cpp"
#include "..\..\Source\ParserGen\CompileSyntax_CalculateTypes.cpp"
#include "..\..\Source\ParserGen\CompileSyntax_CompileSyntax.cpp"
#include "..\..\Source\ParserGen\CompileSyntax_ResolveName.cpp"
#include "..\..\Source\ParserGen\CompileSyntax_RewriteSyntax_PrefixMerge.cpp"
#include "..\..\Source\ParserGen\CompileSyntax_RewriteSyntax_Switch.cpp"
#include "..\..\Source\ParserGen\CompileSyntax_ValidatePrefixMerge.cpp"
#include "..\..\Source\ParserGen\CompileSyntax_ValidateStructure.cpp"
#include "..\..\Source\ParserGen\CompileSyntax_ValidateSwitchesAndConditions.cpp"
#include "..\..\Source\ParserGen\CompileSyntax_ValidateTypes.cpp"
#include "..\..\Source\ParserGen_Global\ParserCppGen.cpp"
#include "..\..\Source\ParserGen_Global\ParserSymbol.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenRuleAst.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenRuleAst_Builder.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenRuleAst_Copy.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenRuleAst_Empty.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenRuleAst_Json.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenRuleAst_Traverse.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenRuleParser.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenTypeAst.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenTypeAst_Builder.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenTypeAst_Copy.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenTypeAst_Empty.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenTypeAst_Json.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenTypeAst_Traverse.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGenTypeParser.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGen_Assembler.cpp"
#include "..\..\Source\ParserGen_Generated\ParserGen_Lexer.cpp"
#include "..\..\Source\ParserGen_Printer\SyntaxAstToCode.cpp"
#include "..\..\Source\ParserGen_Printer\TypeAstToCode.cpp"
#include "..\..\Source\ParserGen_Printer\TypeSymbolToAst.cpp"
#include "..\..\Source\Syntax\SyntaxCppGen.cpp"
#include "..\..\Source\Syntax\SyntaxSymbol.cpp"
#include "..\..\Source\Syntax\SyntaxSymbolWriter.cpp"
#include "..\..\Source\Syntax\SyntaxSymbol_Automaton.cpp"
#include "..\..\Source\Syntax\SyntaxSymbol_CreateParserGenRuleSyntax.cpp"
#include "..\..\Source\Syntax\SyntaxSymbol_CreateParserGenTypeSyntax.cpp"
#include "..\..\Source\Syntax\SyntaxSymbol_CreateParserGenUtility.cpp"
#include "..\..\Source\Syntax\SyntaxSymbol_NFACompact.cpp"
#include "..\..\Source\Syntax\SyntaxSymbol_NFACrossReferenced.cpp"