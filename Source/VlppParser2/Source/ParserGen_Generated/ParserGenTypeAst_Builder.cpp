/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeAst
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "ParserGenTypeAst_Builder.h"

namespace vl::glr::parsergen::builder
{

/***********************************************************************
MakeAstFile
***********************************************************************/

	MakeAstFile& MakeAstFile::types(const vl::Ptr<GlrType>& value)
	{
		node->types.Add(value);
		return *this;
	}

/***********************************************************************
MakeClass
***********************************************************************/

	MakeClass& MakeClass::attAmbiguous(const vl::WString& value)
	{
		node->attAmbiguous.value = value;
		return *this;
	}

	MakeClass& MakeClass::baseClass(const vl::WString& value)
	{
		node->baseClass.value = value;
		return *this;
	}

	MakeClass& MakeClass::props(const vl::Ptr<GlrClassProp>& value)
	{
		node->props.Add(value);
		return *this;
	}

	MakeClass& MakeClass::attPublic(const vl::WString& value)
	{
		node->attPublic.value = value;
		return *this;
	}

	MakeClass& MakeClass::name(const vl::WString& value)
	{
		node->name.value = value;
		return *this;
	}

/***********************************************************************
MakeClassProp
***********************************************************************/

	MakeClassProp& MakeClassProp::name(const vl::WString& value)
	{
		node->name.value = value;
		return *this;
	}

	MakeClassProp& MakeClassProp::propType(GlrPropType value)
	{
		node->propType = value;
		return *this;
	}

	MakeClassProp& MakeClassProp::propTypeName(const vl::WString& value)
	{
		node->propTypeName.value = value;
		return *this;
	}

/***********************************************************************
MakeEnum
***********************************************************************/

	MakeEnum& MakeEnum::items(const vl::Ptr<GlrEnumItem>& value)
	{
		node->items.Add(value);
		return *this;
	}

	MakeEnum& MakeEnum::attPublic(const vl::WString& value)
	{
		node->attPublic.value = value;
		return *this;
	}

	MakeEnum& MakeEnum::name(const vl::WString& value)
	{
		node->name.value = value;
		return *this;
	}

/***********************************************************************
MakeEnumItem
***********************************************************************/

	MakeEnumItem& MakeEnumItem::name(const vl::WString& value)
	{
		node->name.value = value;
		return *this;
	}

/***********************************************************************
MakeType
***********************************************************************/

	MakeType& MakeType::attPublic(const vl::WString& value)
	{
		node->attPublic.value = value;
		return *this;
	}

	MakeType& MakeType::name(const vl::WString& value)
	{
		node->name.value = value;
		return *this;
	}
}