/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:FeatureAst
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "FeatureTestFeatureAst_Copy.h"

namespace featuretest::copy_visitor
{
	void FeatureAstVisitor::CopyFields(BranchedOptionalFeature* from, BranchedOptionalFeature* to)
	{
		CopyFields(static_cast<Feature*>(from), static_cast<Feature*>(to));
		to->optional = CopyNode(from->optional.Obj());
		for (auto&& listItem : from->tails)
		{
			to->tails.Add(CopyNode(listItem.Obj()));
		}
		to->type = from->type;
	}

	void FeatureAstVisitor::CopyFields(ClFeature* from, ClFeature* to)
	{
		CopyFields(static_cast<Feature*>(from), static_cast<Feature*>(to));
		to->id = from->id;
	}

	void FeatureAstVisitor::CopyFields(FaFeature* from, FaFeature* to)
	{
		CopyFields(static_cast<Feature*>(from), static_cast<Feature*>(to));
		to->fa = from->fa;
	}

	void FeatureAstVisitor::CopyFields(Feature* from, Feature* to)
	{
	}

	void FeatureAstVisitor::CopyFields(FeatureToResolve* from, FeatureToResolve* to)
	{
		CopyFields(static_cast<Feature*>(from), static_cast<Feature*>(to));
		for (auto&& listItem : from->candidates)
		{
			to->candidates.Add(CopyNode(listItem.Obj()));
		}
	}

	void FeatureAstVisitor::CopyFields(Gt* from, Gt* to)
	{
	}

	void FeatureAstVisitor::CopyFields(Lt* from, Lt* to)
	{
	}

	void FeatureAstVisitor::CopyFields(NestedOptionalFeature* from, NestedOptionalFeature* to)
	{
		CopyFields(static_cast<Feature*>(from), static_cast<Feature*>(to));
		to->optional = CopyNode(from->optional.Obj());
		to->tail1 = CopyNode(from->tail1.Obj());
		to->tail2 = CopyNode(from->tail2.Obj());
		to->tail3 = CopyNode(from->tail3.Obj());
		for (auto&& listItem : from->tails)
		{
			to->tails.Add(CopyNode(listItem.Obj()));
		}
	}

	void FeatureAstVisitor::CopyFields(OptionalFeature* from, OptionalFeature* to)
	{
		CopyFields(static_cast<Feature*>(from), static_cast<Feature*>(to));
		for (auto&& listItem : from->loop)
		{
			to->loop.Add(CopyNode(listItem.Obj()));
		}
		to->optional = CopyNode(from->optional.Obj());
		to->priority = from->priority;
	}

	void FeatureAstVisitor::CopyFields(PbaFeature* from, PbaFeature* to)
	{
		CopyFields(static_cast<Feature*>(from), static_cast<Feature*>(to));
		for (auto&& listItem : from->gts)
		{
			to->gts.Add(CopyNode(listItem.Obj()));
		}
		for (auto&& listItem : from->lts)
		{
			to->lts.Add(CopyNode(listItem.Obj()));
		}
		to->optional = CopyNode(from->optional.Obj());
		to->tail = CopyNode(from->tail.Obj());
		for (auto&& listItem : from->tails)
		{
			to->tails.Add(CopyNode(listItem.Obj()));
		}
	}

	void FeatureAstVisitor::CopyFields(Plus* from, Plus* to)
	{
	}

	void FeatureAstVisitor::CopyFields(Pwa1Feature* from, Pwa1Feature* to)
	{
		CopyFields(static_cast<Feature*>(from), static_cast<Feature*>(to));
		for (auto&& listItem : from->gts)
		{
			to->gts.Add(CopyNode(listItem.Obj()));
		}
		for (auto&& listItem : from->lts)
		{
			to->lts.Add(CopyNode(listItem.Obj()));
		}
		to->pba = CopyNode(from->pba.Obj());
	}

	void FeatureAstVisitor::CopyFields(PwlFeature* from, PwlFeature* to)
	{
		CopyFields(static_cast<Feature*>(from), static_cast<Feature*>(to));
		for (auto&& listItem : from->one)
		{
			to->one.Add(CopyNode(listItem.Obj()));
		}
		for (auto&& listItem : from->prefix)
		{
			to->prefix.Add(CopyNode(listItem.Obj()));
		}
		to->prev = CopyNode(from->prev.Obj());
		for (auto&& listItem : from->two)
		{
			to->two.Add(CopyNode(listItem.Obj()));
		}
	}

	void FeatureAstVisitor::Visit(Plus* node)
	{
		auto newNode = vl::Ptr(new Plus);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FeatureAstVisitor::Visit(Lt* node)
	{
		auto newNode = vl::Ptr(new Lt);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FeatureAstVisitor::Visit(Gt* node)
	{
		auto newNode = vl::Ptr(new Gt);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FeatureAstVisitor::Visit(FeatureToResolve* node)
	{
		auto newNode = vl::Ptr(new FeatureToResolve);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FeatureAstVisitor::Visit(OptionalFeature* node)
	{
		auto newNode = vl::Ptr(new OptionalFeature);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FeatureAstVisitor::Visit(NestedOptionalFeature* node)
	{
		auto newNode = vl::Ptr(new NestedOptionalFeature);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FeatureAstVisitor::Visit(BranchedOptionalFeature* node)
	{
		auto newNode = vl::Ptr(new BranchedOptionalFeature);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FeatureAstVisitor::Visit(PbaFeature* node)
	{
		auto newNode = vl::Ptr(new PbaFeature);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FeatureAstVisitor::Visit(Pwa1Feature* node)
	{
		auto newNode = vl::Ptr(new Pwa1Feature);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FeatureAstVisitor::Visit(PwlFeature* node)
	{
		auto newNode = vl::Ptr(new PwlFeature);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FeatureAstVisitor::Visit(ClFeature* node)
	{
		auto newNode = vl::Ptr(new ClFeature);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FeatureAstVisitor::Visit(FaFeature* node)
	{
		auto newNode = vl::Ptr(new FaFeature);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	vl::Ptr<Feature> FeatureAstVisitor::CopyNode(Feature* node)
	{
		if (!node) return nullptr;
		node->Accept(static_cast<Feature::IVisitor*>(this));
		this->result->codeRange = node->codeRange;
		return this->result.Cast<Feature>();
	}

	vl::Ptr<Plus> FeatureAstVisitor::CopyNode(Plus* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<Plus>();
	}

	vl::Ptr<Lt> FeatureAstVisitor::CopyNode(Lt* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<Lt>();
	}

	vl::Ptr<Gt> FeatureAstVisitor::CopyNode(Gt* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<Gt>();
	}

	vl::Ptr<BranchedOptionalFeature> FeatureAstVisitor::CopyNode(BranchedOptionalFeature* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Feature*>(node)).Cast<BranchedOptionalFeature>();
	}

	vl::Ptr<ClFeature> FeatureAstVisitor::CopyNode(ClFeature* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Feature*>(node)).Cast<ClFeature>();
	}

	vl::Ptr<FaFeature> FeatureAstVisitor::CopyNode(FaFeature* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Feature*>(node)).Cast<FaFeature>();
	}

	vl::Ptr<FeatureToResolve> FeatureAstVisitor::CopyNode(FeatureToResolve* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Feature*>(node)).Cast<FeatureToResolve>();
	}

	vl::Ptr<NestedOptionalFeature> FeatureAstVisitor::CopyNode(NestedOptionalFeature* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Feature*>(node)).Cast<NestedOptionalFeature>();
	}

	vl::Ptr<OptionalFeature> FeatureAstVisitor::CopyNode(OptionalFeature* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Feature*>(node)).Cast<OptionalFeature>();
	}

	vl::Ptr<PbaFeature> FeatureAstVisitor::CopyNode(PbaFeature* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Feature*>(node)).Cast<PbaFeature>();
	}

	vl::Ptr<Pwa1Feature> FeatureAstVisitor::CopyNode(Pwa1Feature* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Feature*>(node)).Cast<Pwa1Feature>();
	}

	vl::Ptr<PwlFeature> FeatureAstVisitor::CopyNode(PwlFeature* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Feature*>(node)).Cast<PwlFeature>();
	}

}