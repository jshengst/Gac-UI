/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:Ast
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "JsonAst_Json.h"

namespace vl::glr::json::json_visitor
{
	void AstVisitor::PrintFields(JsonArray* node)
	{
		BeginField(vl::WString::Unmanaged(L"items"));
		BeginArray();
		for (auto&& listItem : node->items)
		{
			BeginArrayItem();
			Print(listItem.Obj());
			EndArrayItem();
		}
		EndArray();
		EndField();
	}
	void AstVisitor::PrintFields(JsonLiteral* node)
	{
		BeginField(vl::WString::Unmanaged(L"value"));
		switch (node->value)
		{
		case vl::glr::json::JsonLiteralValue::False:
			WriteString(vl::WString::Unmanaged(L"False"));
			break;
		case vl::glr::json::JsonLiteralValue::Null:
			WriteString(vl::WString::Unmanaged(L"Null"));
			break;
		case vl::glr::json::JsonLiteralValue::True:
			WriteString(vl::WString::Unmanaged(L"True"));
			break;
		default:
			WriteNull();
		}
		EndField();
	}
	void AstVisitor::PrintFields(JsonNode* node)
	{
	}
	void AstVisitor::PrintFields(JsonNumber* node)
	{
		BeginField(vl::WString::Unmanaged(L"content"));
		WriteToken(node->content);
		EndField();
	}
	void AstVisitor::PrintFields(JsonObject* node)
	{
		BeginField(vl::WString::Unmanaged(L"fields"));
		BeginArray();
		for (auto&& listItem : node->fields)
		{
			BeginArrayItem();
			Print(listItem.Obj());
			EndArrayItem();
		}
		EndArray();
		EndField();
	}
	void AstVisitor::PrintFields(JsonObjectField* node)
	{
		BeginField(vl::WString::Unmanaged(L"name"));
		WriteToken(node->name);
		EndField();
		BeginField(vl::WString::Unmanaged(L"value"));
		Print(node->value.Obj());
		EndField();
	}
	void AstVisitor::PrintFields(JsonString* node)
	{
		BeginField(vl::WString::Unmanaged(L"content"));
		WriteToken(node->content);
		EndField();
	}

	void AstVisitor::Visit(JsonLiteral* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"Literal"), node);
		PrintFields(static_cast<JsonNode*>(node));
		PrintFields(static_cast<JsonLiteral*>(node));
		EndObject();
	}

	void AstVisitor::Visit(JsonString* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"String"), node);
		PrintFields(static_cast<JsonNode*>(node));
		PrintFields(static_cast<JsonString*>(node));
		EndObject();
	}

	void AstVisitor::Visit(JsonNumber* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"Number"), node);
		PrintFields(static_cast<JsonNode*>(node));
		PrintFields(static_cast<JsonNumber*>(node));
		EndObject();
	}

	void AstVisitor::Visit(JsonArray* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"Array"), node);
		PrintFields(static_cast<JsonNode*>(node));
		PrintFields(static_cast<JsonArray*>(node));
		EndObject();
	}

	void AstVisitor::Visit(JsonObject* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"Object"), node);
		PrintFields(static_cast<JsonNode*>(node));
		PrintFields(static_cast<JsonObject*>(node));
		EndObject();
	}

	AstVisitor::AstVisitor(vl::stream::StreamWriter& _writer)
		: vl::glr::JsonVisitorBase(_writer)
	{
	}

	void AstVisitor::Print(JsonNode* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		node->Accept(static_cast<JsonNode::IVisitor*>(this));
	}

	void AstVisitor::Print(JsonObjectField* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"ObjectField"), node);
		PrintFields(static_cast<JsonObjectField*>(node));
		EndObject();
	}

}
