/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:File
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_PREFIXMERGE9_PMLOOP_FILE_AST_TRAVERSE_VISITOR
#define VCZH_PARSER2_UNITTEST_PREFIXMERGE9_PMLOOP_FILE_AST_TRAVERSE_VISITOR

#include "PrefixMerge9_PmLoopFile.h"

namespace prefixmerge9_pmloop::traverse_visitor
{
	/// <summary>A traverse visitor, overriding all abstract methods with AST visiting code.</summary>
	class FileVisitor
		: public vl::Object
		, protected virtual Item::IVisitor
	{
	protected:
		virtual void Traverse(vl::glr::ParsingToken& token);
		virtual void Traverse(vl::glr::ParsingAstBase* node);
		virtual void Traverse(ClassItem* node);
		virtual void Traverse(ClassQuestionItem* node);
		virtual void Traverse(File* node);
		virtual void Traverse(IntCommaItem* node);
		virtual void Traverse(IntDotItem* node);
		virtual void Traverse(IntItem* node);
		virtual void Traverse(IntQuestionItem* node);
		virtual void Traverse(Item* node);
		virtual void Traverse(ItemToResolve* node);
		virtual void Traverse(QuestionItem* node);

	protected:
		virtual void Finishing(vl::glr::ParsingAstBase* node);
		virtual void Finishing(ClassItem* node);
		virtual void Finishing(ClassQuestionItem* node);
		virtual void Finishing(File* node);
		virtual void Finishing(IntCommaItem* node);
		virtual void Finishing(IntDotItem* node);
		virtual void Finishing(IntItem* node);
		virtual void Finishing(IntQuestionItem* node);
		virtual void Finishing(Item* node);
		virtual void Finishing(ItemToResolve* node);
		virtual void Finishing(QuestionItem* node);

	protected:
		void Visit(ItemToResolve* node) override;
		void Visit(IntItem* node) override;
		void Visit(IntCommaItem* node) override;
		void Visit(IntDotItem* node) override;
		void Visit(IntQuestionItem* node) override;
		void Visit(ClassItem* node) override;
		void Visit(ClassQuestionItem* node) override;
		void Visit(QuestionItem* node) override;

	public:
		void InspectInto(Item* node);
		void InspectInto(File* node);
	};
}
#endif