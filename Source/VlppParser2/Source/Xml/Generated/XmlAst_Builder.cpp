/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:Ast
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "XmlAst_Builder.h"

namespace vl::glr::xml::builder
{

/***********************************************************************
MakeAttribute
***********************************************************************/

	MakeAttribute& MakeAttribute::name(const vl::WString& value)
	{
		node->name.value = value;
		return *this;
	}

	MakeAttribute& MakeAttribute::value(const vl::WString& value)
	{
		node->value.value = value;
		return *this;
	}

/***********************************************************************
MakeCData
***********************************************************************/

	MakeCData& MakeCData::content(const vl::WString& value)
	{
		node->content.value = value;
		return *this;
	}

/***********************************************************************
MakeComment
***********************************************************************/

	MakeComment& MakeComment::content(const vl::WString& value)
	{
		node->content.value = value;
		return *this;
	}

/***********************************************************************
MakeDocument
***********************************************************************/

	MakeDocument& MakeDocument::prologs(const vl::Ptr<XmlNode>& value)
	{
		node->prologs.Add(value);
		return *this;
	}

	MakeDocument& MakeDocument::rootElement(const vl::Ptr<XmlElement>& value)
	{
		node->rootElement = value;
		return *this;
	}

/***********************************************************************
MakeElement
***********************************************************************/

	MakeElement& MakeElement::attributes(const vl::Ptr<XmlAttribute>& value)
	{
		node->attributes.Add(value);
		return *this;
	}

	MakeElement& MakeElement::closingName(const vl::WString& value)
	{
		node->closingName.value = value;
		return *this;
	}

	MakeElement& MakeElement::name(const vl::WString& value)
	{
		node->name.value = value;
		return *this;
	}

	MakeElement& MakeElement::subNodes(const vl::Ptr<XmlNode>& value)
	{
		node->subNodes.Add(value);
		return *this;
	}

/***********************************************************************
MakeInstruction
***********************************************************************/

	MakeInstruction& MakeInstruction::attributes(const vl::Ptr<XmlAttribute>& value)
	{
		node->attributes.Add(value);
		return *this;
	}

	MakeInstruction& MakeInstruction::name(const vl::WString& value)
	{
		node->name.value = value;
		return *this;
	}

/***********************************************************************
MakeText
***********************************************************************/

	MakeText& MakeText::content(const vl::WString& value)
	{
		node->content.value = value;
		return *this;
	}
}