/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeAst
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "ParserGenTypeAst_Json.h"

namespace vl::glr::parsergen::json_visitor
{
	void TypeAstVisitor::PrintFields(GlrAstFile* node)
	{
		BeginField(vl::WString::Unmanaged(L"types"));
		BeginArray();
		for (auto&& listItem : node->types)
		{
			BeginArrayItem();
			Print(listItem.Obj());
			EndArrayItem();
		}
		EndArray();
		EndField();
	}
	void TypeAstVisitor::PrintFields(GlrClass* node)
	{
		BeginField(vl::WString::Unmanaged(L"attAmbiguous"));
		WriteToken(node->attAmbiguous);
		EndField();
		BeginField(vl::WString::Unmanaged(L"baseClass"));
		WriteToken(node->baseClass);
		EndField();
		BeginField(vl::WString::Unmanaged(L"props"));
		BeginArray();
		for (auto&& listItem : node->props)
		{
			BeginArrayItem();
			Print(listItem.Obj());
			EndArrayItem();
		}
		EndArray();
		EndField();
	}
	void TypeAstVisitor::PrintFields(GlrClassProp* node)
	{
		BeginField(vl::WString::Unmanaged(L"name"));
		WriteToken(node->name);
		EndField();
		BeginField(vl::WString::Unmanaged(L"propType"));
		switch (node->propType)
		{
		case vl::glr::parsergen::GlrPropType::Array:
			WriteString(vl::WString::Unmanaged(L"Array"));
			break;
		case vl::glr::parsergen::GlrPropType::Token:
			WriteString(vl::WString::Unmanaged(L"Token"));
			break;
		case vl::glr::parsergen::GlrPropType::Type:
			WriteString(vl::WString::Unmanaged(L"Type"));
			break;
		default:
			WriteNull();
		}
		EndField();
		BeginField(vl::WString::Unmanaged(L"propTypeName"));
		WriteToken(node->propTypeName);
		EndField();
	}
	void TypeAstVisitor::PrintFields(GlrEnum* node)
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
	void TypeAstVisitor::PrintFields(GlrEnumItem* node)
	{
		BeginField(vl::WString::Unmanaged(L"name"));
		WriteToken(node->name);
		EndField();
	}
	void TypeAstVisitor::PrintFields(GlrType* node)
	{
		BeginField(vl::WString::Unmanaged(L"attPublic"));
		WriteToken(node->attPublic);
		EndField();
		BeginField(vl::WString::Unmanaged(L"name"));
		WriteToken(node->name);
		EndField();
	}

	void TypeAstVisitor::Visit(GlrEnum* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"Enum"), node);
		PrintFields(static_cast<GlrType*>(node));
		PrintFields(static_cast<GlrEnum*>(node));
		EndObject();
	}

	void TypeAstVisitor::Visit(GlrClass* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"Class"), node);
		PrintFields(static_cast<GlrType*>(node));
		PrintFields(static_cast<GlrClass*>(node));
		EndObject();
	}

	TypeAstVisitor::TypeAstVisitor(vl::stream::StreamWriter& _writer)
		: vl::glr::JsonVisitorBase(_writer)
	{
	}

	void TypeAstVisitor::Print(GlrType* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		node->Accept(static_cast<GlrType::IVisitor*>(this));
	}

	void TypeAstVisitor::Print(GlrEnumItem* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"EnumItem"), node);
		PrintFields(static_cast<GlrEnumItem*>(node));
		EndObject();
	}

	void TypeAstVisitor::Print(GlrClassProp* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"ClassProp"), node);
		PrintFields(static_cast<GlrClassProp*>(node));
		EndObject();
	}

	void TypeAstVisitor::Print(GlrAstFile* node)
	{
		if (!node)
		{
			WriteNull();
			return;
		}
		BeginObject();
		WriteType(vl::WString::Unmanaged(L"AstFile"), node);
		PrintFields(static_cast<GlrAstFile*>(node));
		EndObject();
	}

}