/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:FeatureAst
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_FEATURETEST_FEATUREAST_AST_COPY_VISITOR
#define VCZH_PARSER2_UNITTEST_FEATURETEST_FEATUREAST_AST_COPY_VISITOR

#include "FeatureTestFeatureAst.h"

namespace featuretest::copy_visitor
{
	/// <summary>A copy visitor, overriding all abstract methods with AST copying code.</summary>
	class FeatureAstVisitor
		: public virtual vl::glr::CopyVisitorBase
		, protected virtual Feature::IVisitor
	{
	protected:
		void CopyFields(BranchedOptionalFeature* from, BranchedOptionalFeature* to);
		void CopyFields(ClFeature* from, ClFeature* to);
		void CopyFields(FaFeature* from, FaFeature* to);
		void CopyFields(Feature* from, Feature* to);
		void CopyFields(FeatureToResolve* from, FeatureToResolve* to);
		void CopyFields(Gt* from, Gt* to);
		void CopyFields(Lt* from, Lt* to);
		void CopyFields(NestedOptionalFeature* from, NestedOptionalFeature* to);
		void CopyFields(OptionalFeature* from, OptionalFeature* to);
		void CopyFields(PbaFeature* from, PbaFeature* to);
		void CopyFields(Plus* from, Plus* to);
		void CopyFields(Pwa1Feature* from, Pwa1Feature* to);
		void CopyFields(PwlFeature* from, PwlFeature* to);

	protected:
		virtual void Visit(Plus* node);
		virtual void Visit(Lt* node);
		virtual void Visit(Gt* node);

		void Visit(FeatureToResolve* node) override;
		void Visit(OptionalFeature* node) override;
		void Visit(NestedOptionalFeature* node) override;
		void Visit(BranchedOptionalFeature* node) override;
		void Visit(PbaFeature* node) override;
		void Visit(Pwa1Feature* node) override;
		void Visit(PwlFeature* node) override;
		void Visit(ClFeature* node) override;
		void Visit(FaFeature* node) override;

	public:
		virtual vl::Ptr<Feature> CopyNode(Feature* node);
		virtual vl::Ptr<Plus> CopyNode(Plus* node);
		virtual vl::Ptr<Lt> CopyNode(Lt* node);
		virtual vl::Ptr<Gt> CopyNode(Gt* node);

		vl::Ptr<BranchedOptionalFeature> CopyNode(BranchedOptionalFeature* node);
		vl::Ptr<ClFeature> CopyNode(ClFeature* node);
		vl::Ptr<FaFeature> CopyNode(FaFeature* node);
		vl::Ptr<FeatureToResolve> CopyNode(FeatureToResolve* node);
		vl::Ptr<NestedOptionalFeature> CopyNode(NestedOptionalFeature* node);
		vl::Ptr<OptionalFeature> CopyNode(OptionalFeature* node);
		vl::Ptr<PbaFeature> CopyNode(PbaFeature* node);
		vl::Ptr<Pwa1Feature> CopyNode(Pwa1Feature* node);
		vl::Ptr<PwlFeature> CopyNode(PwlFeature* node);
	};
}
#endif