/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeOrExpr
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_PREFIXMERGE7_PMSWITCH_TYPEOREXPR_AST
#define VCZH_PARSER2_UNITTEST_PREFIXMERGE7_PMSWITCH_TYPEOREXPR_AST

#include "../../../../Source/AstBase.h"
#include "../../../../Source/SyntaxBase.h"

namespace prefixmerge7_pmswitch
{
	class CallExpr;
	class CommaExpr;
	class ConstType;
	class CtorExpr;
	class FunctionType;
	class GenericMemberName;
	class GenericName;
	class GenericQualifiedName;
	class GtExpr;
	class LtExpr;
	class MemberName;
	class MulExpr;
	class Name;
	class PointerType;
	class QualifiedName;
	class ThrowExpr;
	class TypeOrExpr;
	class TypeOrExprToResolve;

	class TypeOrExpr abstract : public vl::glr::ParsingAstBase, vl::reflection::Description<TypeOrExpr>
	{
	public:
		class IVisitor : public virtual vl::reflection::IDescriptable, vl::reflection::Description<IVisitor>
		{
		public:
			virtual void Visit(TypeOrExprToResolve* node) = 0;
			virtual void Visit(QualifiedName* node) = 0;
			virtual void Visit(CallExpr* node) = 0;
			virtual void Visit(CtorExpr* node) = 0;
			virtual void Visit(MulExpr* node) = 0;
			virtual void Visit(LtExpr* node) = 0;
			virtual void Visit(GtExpr* node) = 0;
			virtual void Visit(ThrowExpr* node) = 0;
			virtual void Visit(CommaExpr* node) = 0;
			virtual void Visit(ConstType* node) = 0;
			virtual void Visit(PointerType* node) = 0;
			virtual void Visit(FunctionType* node) = 0;
		};

		virtual void Accept(TypeOrExpr::IVisitor* visitor) = 0;

	};

	class TypeOrExprToResolve : public TypeOrExpr, vl::reflection::Description<TypeOrExprToResolve>
	{
	public:
		vl::collections::List<vl::Ptr<TypeOrExpr>> candidates;

		void Accept(TypeOrExpr::IVisitor* visitor) override;
	};

	class QualifiedName abstract : public TypeOrExpr, vl::reflection::Description<QualifiedName>
	{
	public:
		class IVisitor : public virtual vl::reflection::IDescriptable, vl::reflection::Description<IVisitor>
		{
		public:
			virtual void Visit(Name* node) = 0;
			virtual void Visit(MemberName* node) = 0;
			virtual void Visit(GenericQualifiedName* node) = 0;
		};

		virtual void Accept(QualifiedName::IVisitor* visitor) = 0;


		void Accept(TypeOrExpr::IVisitor* visitor) override;
	};

	class Name : public QualifiedName, vl::reflection::Description<Name>
	{
	public:
		vl::glr::ParsingToken name;

		void Accept(QualifiedName::IVisitor* visitor) override;
	};

	class MemberName : public QualifiedName, vl::reflection::Description<MemberName>
	{
	public:
		vl::Ptr<QualifiedName> parent;
		vl::glr::ParsingToken member;

		void Accept(QualifiedName::IVisitor* visitor) override;
	};

	class GenericQualifiedName abstract : public QualifiedName, vl::reflection::Description<GenericQualifiedName>
	{
	public:
		class IVisitor : public virtual vl::reflection::IDescriptable, vl::reflection::Description<IVisitor>
		{
		public:
			virtual void Visit(GenericName* node) = 0;
			virtual void Visit(GenericMemberName* node) = 0;
		};

		virtual void Accept(GenericQualifiedName::IVisitor* visitor) = 0;

		vl::collections::List<vl::Ptr<TypeOrExpr>> args;

		void Accept(QualifiedName::IVisitor* visitor) override;
	};

	class GenericName : public GenericQualifiedName, vl::reflection::Description<GenericName>
	{
	public:
		vl::glr::ParsingToken name;

		void Accept(GenericQualifiedName::IVisitor* visitor) override;
	};

	class GenericMemberName : public GenericQualifiedName, vl::reflection::Description<GenericMemberName>
	{
	public:
		vl::Ptr<QualifiedName> parent;
		vl::glr::ParsingToken member;

		void Accept(GenericQualifiedName::IVisitor* visitor) override;
	};

	class CallExpr : public TypeOrExpr, vl::reflection::Description<CallExpr>
	{
	public:
		vl::Ptr<TypeOrExpr> func;
		vl::collections::List<vl::Ptr<TypeOrExpr>> args;

		void Accept(TypeOrExpr::IVisitor* visitor) override;
	};

	class CtorExpr : public TypeOrExpr, vl::reflection::Description<CtorExpr>
	{
	public:
		vl::Ptr<TypeOrExpr> type;
		vl::collections::List<vl::Ptr<TypeOrExpr>> args;

		void Accept(TypeOrExpr::IVisitor* visitor) override;
	};

	class MulExpr : public TypeOrExpr, vl::reflection::Description<MulExpr>
	{
	public:
		vl::Ptr<TypeOrExpr> first;
		vl::Ptr<TypeOrExpr> second;

		void Accept(TypeOrExpr::IVisitor* visitor) override;
	};

	class LtExpr : public TypeOrExpr, vl::reflection::Description<LtExpr>
	{
	public:
		vl::Ptr<TypeOrExpr> first;
		vl::Ptr<TypeOrExpr> second;

		void Accept(TypeOrExpr::IVisitor* visitor) override;
	};

	class GtExpr : public TypeOrExpr, vl::reflection::Description<GtExpr>
	{
	public:
		vl::Ptr<TypeOrExpr> first;
		vl::Ptr<TypeOrExpr> second;

		void Accept(TypeOrExpr::IVisitor* visitor) override;
	};

	class ThrowExpr : public TypeOrExpr, vl::reflection::Description<ThrowExpr>
	{
	public:
		vl::collections::List<vl::Ptr<TypeOrExpr>> arg;

		void Accept(TypeOrExpr::IVisitor* visitor) override;
	};

	class CommaExpr : public TypeOrExpr, vl::reflection::Description<CommaExpr>
	{
	public:
		vl::Ptr<TypeOrExpr> first;
		vl::Ptr<TypeOrExpr> second;

		void Accept(TypeOrExpr::IVisitor* visitor) override;
	};

	class ConstType : public TypeOrExpr, vl::reflection::Description<ConstType>
	{
	public:
		vl::Ptr<TypeOrExpr> type;

		void Accept(TypeOrExpr::IVisitor* visitor) override;
	};

	class PointerType : public TypeOrExpr, vl::reflection::Description<PointerType>
	{
	public:
		vl::Ptr<TypeOrExpr> type;

		void Accept(TypeOrExpr::IVisitor* visitor) override;
	};

	class FunctionType : public TypeOrExpr, vl::reflection::Description<FunctionType>
	{
	public:
		vl::Ptr<TypeOrExpr> returnType;
		vl::collections::List<vl::Ptr<TypeOrExpr>> args;

		void Accept(TypeOrExpr::IVisitor* visitor) override;
	};
}
namespace vl::reflection::description
{
#ifndef VCZH_DEBUG_NO_REFLECTION
	DECL_TYPE_INFO(prefixmerge7_pmswitch::TypeOrExpr)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::TypeOrExpr::IVisitor)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::TypeOrExprToResolve)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::QualifiedName)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::QualifiedName::IVisitor)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::Name)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::MemberName)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::GenericQualifiedName)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::GenericQualifiedName::IVisitor)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::GenericName)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::GenericMemberName)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::CallExpr)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::CtorExpr)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::MulExpr)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::LtExpr)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::GtExpr)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::ThrowExpr)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::CommaExpr)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::ConstType)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::PointerType)
	DECL_TYPE_INFO(prefixmerge7_pmswitch::FunctionType)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA

	BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(prefixmerge7_pmswitch::TypeOrExpr::IVisitor)
		void Visit(prefixmerge7_pmswitch::TypeOrExprToResolve* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::QualifiedName* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::CallExpr* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::CtorExpr* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::MulExpr* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::LtExpr* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::GtExpr* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::ThrowExpr* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::CommaExpr* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::ConstType* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::PointerType* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::FunctionType* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

	END_INTERFACE_PROXY(prefixmerge7_pmswitch::TypeOrExpr::IVisitor)

	BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(prefixmerge7_pmswitch::QualifiedName::IVisitor)
		void Visit(prefixmerge7_pmswitch::Name* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::MemberName* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::GenericQualifiedName* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

	END_INTERFACE_PROXY(prefixmerge7_pmswitch::QualifiedName::IVisitor)

	BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(prefixmerge7_pmswitch::GenericQualifiedName::IVisitor)
		void Visit(prefixmerge7_pmswitch::GenericName* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

		void Visit(prefixmerge7_pmswitch::GenericMemberName* node) override
		{
			INVOKE_INTERFACE_PROXY(Visit, node);
		}

	END_INTERFACE_PROXY(prefixmerge7_pmswitch::GenericQualifiedName::IVisitor)

#endif
#endif
	/// <summary>Load all reflectable AST types, only available when <b>VCZH_DEBUG_NO_REFLECTION</b> is off.</summary>
	/// <returns>Returns true if this operation succeeded.</returns>
	extern bool PrefixMerge7_PmSwitchTypeOrExprLoadTypes();
}
#endif