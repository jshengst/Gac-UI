/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:Ast
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_BUILTIN_JSON_AST_AST_TRAVERSE_VISITOR
#define VCZH_PARSER2_BUILTIN_JSON_AST_AST_TRAVERSE_VISITOR

#include "JsonAst.h"

namespace vl::glr::json::traverse_visitor
{
	/// <summary>A traverse visitor, overriding all abstract methods with AST visiting code.</summary>
	class AstVisitor
		: public vl::Object
		, protected virtual JsonNode::IVisitor
	{
	protected:
		virtual void Traverse(vl::glr::ParsingToken& token);
		virtual void Traverse(vl::glr::ParsingAstBase* node);
		virtual void Traverse(JsonArray* node);
		virtual void Traverse(JsonLiteral* node);
		virtual void Traverse(JsonNode* node);
		virtual void Traverse(JsonNumber* node);
		virtual void Traverse(JsonObject* node);
		virtual void Traverse(JsonObjectField* node);
		virtual void Traverse(JsonString* node);

	protected:
		virtual void Finishing(vl::glr::ParsingAstBase* node);
		virtual void Finishing(JsonArray* node);
		virtual void Finishing(JsonLiteral* node);
		virtual void Finishing(JsonNode* node);
		virtual void Finishing(JsonNumber* node);
		virtual void Finishing(JsonObject* node);
		virtual void Finishing(JsonObjectField* node);
		virtual void Finishing(JsonString* node);

	protected:
		void Visit(JsonLiteral* node) override;
		void Visit(JsonString* node) override;
		void Visit(JsonNumber* node) override;
		void Visit(JsonArray* node) override;
		void Visit(JsonObject* node) override;

	public:
		void InspectInto(JsonNode* node);
		void InspectInto(JsonObjectField* node);
	};
}
#endif