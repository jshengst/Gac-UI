/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeAst
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "ParserGenTypeAst_Copy.h"

namespace vl::glr::parsergen::copy_visitor
{
	void TypeAstVisitor::CopyFields(GlrAstFile* from, GlrAstFile* to)
	{
		for (auto&& listItem : from->types)
		{
			to->types.Add(CopyNode(listItem.Obj()));
		}
	}

	void TypeAstVisitor::CopyFields(GlrClass* from, GlrClass* to)
	{
		CopyFields(static_cast<GlrType*>(from), static_cast<GlrType*>(to));
		to->attAmbiguous = from->attAmbiguous;
		to->baseClass = from->baseClass;
		for (auto&& listItem : from->props)
		{
			to->props.Add(CopyNode(listItem.Obj()));
		}
	}

	void TypeAstVisitor::CopyFields(GlrClassProp* from, GlrClassProp* to)
	{
		to->name = from->name;
		to->propType = from->propType;
		to->propTypeName = from->propTypeName;
	}

	void TypeAstVisitor::CopyFields(GlrEnum* from, GlrEnum* to)
	{
		CopyFields(static_cast<GlrType*>(from), static_cast<GlrType*>(to));
		for (auto&& listItem : from->items)
		{
			to->items.Add(CopyNode(listItem.Obj()));
		}
	}

	void TypeAstVisitor::CopyFields(GlrEnumItem* from, GlrEnumItem* to)
	{
		to->name = from->name;
	}

	void TypeAstVisitor::CopyFields(GlrType* from, GlrType* to)
	{
		to->attPublic = from->attPublic;
		to->name = from->name;
	}

	void TypeAstVisitor::Visit(GlrEnumItem* node)
	{
		auto newNode = vl::Ptr(new GlrEnumItem);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void TypeAstVisitor::Visit(GlrClassProp* node)
	{
		auto newNode = vl::Ptr(new GlrClassProp);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void TypeAstVisitor::Visit(GlrAstFile* node)
	{
		auto newNode = vl::Ptr(new GlrAstFile);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void TypeAstVisitor::Visit(GlrEnum* node)
	{
		auto newNode = vl::Ptr(new GlrEnum);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void TypeAstVisitor::Visit(GlrClass* node)
	{
		auto newNode = vl::Ptr(new GlrClass);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	vl::Ptr<GlrType> TypeAstVisitor::CopyNode(GlrType* node)
	{
		if (!node) return nullptr;
		node->Accept(static_cast<GlrType::IVisitor*>(this));
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrType>();
	}

	vl::Ptr<GlrEnumItem> TypeAstVisitor::CopyNode(GlrEnumItem* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrEnumItem>();
	}

	vl::Ptr<GlrClassProp> TypeAstVisitor::CopyNode(GlrClassProp* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrClassProp>();
	}

	vl::Ptr<GlrAstFile> TypeAstVisitor::CopyNode(GlrAstFile* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<GlrAstFile>();
	}

	vl::Ptr<GlrClass> TypeAstVisitor::CopyNode(GlrClass* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrType*>(node)).Cast<GlrClass>();
	}

	vl::Ptr<GlrEnum> TypeAstVisitor::CopyNode(GlrEnum* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<GlrType*>(node)).Cast<GlrEnum>();
	}

}
