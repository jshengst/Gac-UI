/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:File
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "PrefixMerge9_PmLoopFile_Copy.h"

namespace prefixmerge9_pmloop::copy_visitor
{
	void FileVisitor::CopyFields(ClassItem* from, ClassItem* to)
	{
		CopyFields(static_cast<Item*>(from), static_cast<Item*>(to));
	}

	void FileVisitor::CopyFields(ClassQuestionItem* from, ClassQuestionItem* to)
	{
		CopyFields(static_cast<Item*>(from), static_cast<Item*>(to));
	}

	void FileVisitor::CopyFields(File* from, File* to)
	{
		for (auto&& listItem : from->items)
		{
			to->items.Add(CopyNode(listItem.Obj()));
		}
	}

	void FileVisitor::CopyFields(IntCommaItem* from, IntCommaItem* to)
	{
		CopyFields(static_cast<Item*>(from), static_cast<Item*>(to));
	}

	void FileVisitor::CopyFields(IntDotItem* from, IntDotItem* to)
	{
		CopyFields(static_cast<Item*>(from), static_cast<Item*>(to));
	}

	void FileVisitor::CopyFields(IntItem* from, IntItem* to)
	{
		CopyFields(static_cast<Item*>(from), static_cast<Item*>(to));
	}

	void FileVisitor::CopyFields(IntQuestionItem* from, IntQuestionItem* to)
	{
		CopyFields(static_cast<Item*>(from), static_cast<Item*>(to));
	}

	void FileVisitor::CopyFields(Item* from, Item* to)
	{
	}

	void FileVisitor::CopyFields(ItemToResolve* from, ItemToResolve* to)
	{
		CopyFields(static_cast<Item*>(from), static_cast<Item*>(to));
		for (auto&& listItem : from->candidates)
		{
			to->candidates.Add(CopyNode(listItem.Obj()));
		}
	}

	void FileVisitor::CopyFields(QuestionItem* from, QuestionItem* to)
	{
		CopyFields(static_cast<Item*>(from), static_cast<Item*>(to));
		to->item = CopyNode(from->item.Obj());
	}

	void FileVisitor::Visit(File* node)
	{
		auto newNode = vl::Ptr(new File);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FileVisitor::Visit(ItemToResolve* node)
	{
		auto newNode = vl::Ptr(new ItemToResolve);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FileVisitor::Visit(IntItem* node)
	{
		auto newNode = vl::Ptr(new IntItem);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FileVisitor::Visit(IntCommaItem* node)
	{
		auto newNode = vl::Ptr(new IntCommaItem);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FileVisitor::Visit(IntDotItem* node)
	{
		auto newNode = vl::Ptr(new IntDotItem);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FileVisitor::Visit(IntQuestionItem* node)
	{
		auto newNode = vl::Ptr(new IntQuestionItem);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FileVisitor::Visit(ClassItem* node)
	{
		auto newNode = vl::Ptr(new ClassItem);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FileVisitor::Visit(ClassQuestionItem* node)
	{
		auto newNode = vl::Ptr(new ClassQuestionItem);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	void FileVisitor::Visit(QuestionItem* node)
	{
		auto newNode = vl::Ptr(new QuestionItem);
		CopyFields(node, newNode.Obj());
		this->result = newNode;
	}

	vl::Ptr<Item> FileVisitor::CopyNode(Item* node)
	{
		if (!node) return nullptr;
		node->Accept(static_cast<Item::IVisitor*>(this));
		this->result->codeRange = node->codeRange;
		return this->result.Cast<Item>();
	}

	vl::Ptr<File> FileVisitor::CopyNode(File* node)
	{
		if (!node) return nullptr;
		Visit(node);
		this->result->codeRange = node->codeRange;
		return this->result.Cast<File>();
	}

	vl::Ptr<ClassItem> FileVisitor::CopyNode(ClassItem* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Item*>(node)).Cast<ClassItem>();
	}

	vl::Ptr<ClassQuestionItem> FileVisitor::CopyNode(ClassQuestionItem* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Item*>(node)).Cast<ClassQuestionItem>();
	}

	vl::Ptr<IntCommaItem> FileVisitor::CopyNode(IntCommaItem* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Item*>(node)).Cast<IntCommaItem>();
	}

	vl::Ptr<IntDotItem> FileVisitor::CopyNode(IntDotItem* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Item*>(node)).Cast<IntDotItem>();
	}

	vl::Ptr<IntItem> FileVisitor::CopyNode(IntItem* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Item*>(node)).Cast<IntItem>();
	}

	vl::Ptr<IntQuestionItem> FileVisitor::CopyNode(IntQuestionItem* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Item*>(node)).Cast<IntQuestionItem>();
	}

	vl::Ptr<ItemToResolve> FileVisitor::CopyNode(ItemToResolve* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Item*>(node)).Cast<ItemToResolve>();
	}

	vl::Ptr<QuestionItem> FileVisitor::CopyNode(QuestionItem* node)
	{
		if (!node) return nullptr;
		return CopyNode(static_cast<Item*>(node)).Cast<QuestionItem>();
	}

}