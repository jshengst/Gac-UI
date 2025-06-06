#include "AssertCollection.h"

namespace TestLinq_TestObjects
{
	vint Minus(vint a)
	{
		return -a;
	}

	vint Square(vint a)
	{
		return a * a;
	}

	vint Double(vint a)
	{
		return a * 2;
	}

	bool Odd(vint a)
	{
		return a % 2 == 1;
	}

	vint Add(vint a, vint b)
	{
		return a + b;
	}

	bool And(bool a, bool b)
	{
		return a && b;
	}

	bool Or(bool a, bool b)
	{
		return a || b;
	}

	bool dividable(vint a, vint b)
	{
		return b % a == 0;
	}

	auto dividableConverter(vint a)
	{
		return Func([=](vint b) {return dividable(a, b); });
	}

	auto dividableCombiner(Func<bool(vint)> a, Func<bool(vint)> b)
	{
		return Func([=](vint c) { return And(a(c), b(c)); });
	}

	std::strong_ordering Compare(vint a, vint b)
	{
		return a <=> b;
	}

	std::strong_ordering ReverseCompare(vint a, vint b)
	{
		return b <=> a;
	}
}

using namespace TestLinq_TestObjects;

TEST_FILE
{
	TEST_CASE(L"Test Select()")
	{
		List<vint> src;
		List<vint> dst;
		for (vint i = 1; i <= 10; i++)
		{
			src.Add(i);
		}
		CopyFrom(dst, From(src).Select(Square).Select(Double));
		CHECK_LIST_ITEMS(dst, {2 _ 8 _ 18 _ 32 _ 50 _ 72 _ 98 _ 128 _ 162 _ 200});
		CompareEnumerable(dst, From(src).Select(Square).Select(Double));
	});

	TEST_CASE(L"Test SelectMany()")
	{
		vint src[] = {1,2,3};
		List<vint> dst;

		CopyFrom(dst, From(src).SelectMany([](vint i)
		{
			auto xs = Ptr(new List<vint>());
			xs->Add(i);
			xs->Add(i * 2);
			xs->Add(i * 3);
			return LazyList<vint>(xs);
		}));
		CHECK_LIST_ITEMS(dst, {1 _ 2 _ 3 _ 2 _ 4 _ 6 _ 3 _ 6 _ 9});
	});

	TEST_CASE(L"Test Where()")
	{
		List<vint> src;
		List<vint> dst;
		for (vint i = 1; i <= 10; i++)
		{
			src.Add(i);
		}
		CopyFrom(dst, From(src).Where(Odd).Select(Square));
		CHECK_LIST_ITEMS(dst, {1 _ 9 _ 25 _ 49 _ 81});
		CopyFrom(dst, From(src).Where(Odd));
		CHECK_LIST_ITEMS(dst, {1 _ 3 _ 5 _ 7 _ 9});
		CompareEnumerable(dst, From(src).Where(Odd));
	});

	TEST_CASE(L"Test Aggregate()")
	{
		List<vint> src;
		for (vint i = 1; i <= 10; i++)
		{
			src.Add(i);
		}
		TEST_ASSERT(From(src).Aggregate((vint)45, Add) == 100);
		TEST_ASSERT(From(src).Aggregate(Add) == 55);
		TEST_ASSERT(From(src).All(Odd) == false);
		TEST_ASSERT(From(src).Any(Odd) == true);
		TEST_ASSERT(From(src).Max() == 10);
		TEST_ASSERT(From(src).Min() == 1);
	});

	TEST_CASE(L"Test Pairwise()")
	{
		List<vint> src;
		Group<bool, vint> dst;
		List<Pair<bool, vint>> pair;
		for (vint i = 1; i <= 10; i++)
		{
			src.Add(i);
		}
		CopyFrom(dst, From(src).Select(Odd).Pairwise(From(src).Select(Square)));
		TEST_ASSERT(dst.Count() == 2);
		TEST_ASSERT(dst.Keys()[0] == false);
		TEST_ASSERT(dst.Keys()[1] == true);
		CHECK_LIST_ITEMS(dst.Get(true), {1 _ 9 _ 25 _ 49 _ 81});
		CHECK_LIST_ITEMS(dst.Get(false), {4 _ 16 _ 36 _ 64 _ 100});
		CopyFrom(pair, From(src).Select(Odd).Pairwise(From(src).Select(Square)));
		CompareEnumerable(pair, From(src).Select(Odd).Pairwise(From(src).Select(Square)));
	});

	TEST_CASE(L"Test Linq with List<Nullable<T>>")
	{
		List<Nullable<vint>> src;
		src.Add(1);
		src.Add(Nullable<vint>());
		src.Add(2);
		src.Add(Nullable<vint>());
		src.Add(3);

		List<vint> dst;
		CopyFrom(dst, From(src)
			.Select([](Nullable<vint> i) {return i ? i.Value() : -1; })
			);
		CHECK_LIST_ITEMS(dst, {1 _ - 1 _ 2 _ - 1 _ 3});

		CopyFrom(dst, From(src)
			.Where([](Nullable<vint> i) {return i; })
			.Select([](Nullable<vint> i) {return i.Value(); })
			);
		CHECK_LIST_ITEMS(dst, {1 _ 2 _ 3});
	});

	TEST_CASE(L"Test Linq with List<Tuple<T, U>>")
	{
		List<Tuple<vint, WString>> src;
		src.Add({1, WString::Unmanaged(L"c")});
		src.Add({2, WString::Unmanaged(L"b")});
		src.Add({3, WString::Unmanaged(L"a")});

		List<vint> dst;
		CopyFrom(dst, From(src)
			.OrderByKey([](Tuple<vint, WString> t)->decltype(auto) { return t.template get<1>(); })
			.Select([](Tuple<vint, WString> t) { auto&& [x, y] = t; return x; })
		);
		CHECK_LIST_ITEMS(dst, { 3 _ 2 _ 1 });
	});

	TEST_CASE(L"Test Linq with functions")
	{
		vint divider[] = {2,3,5};
		Func<bool(vint)> selector =
			From(divider)
			.Select(dividableConverter)
			.Aggregate(dividableCombiner);

		List<vint> src;
		List<vint> dst;
		for (vint i = 1; i <= 100; i++)
		{
			src.Add(i);
		}
		CopyFrom(dst, From(src).Where(selector));
		CHECK_LIST_ITEMS(dst, {30 _ 60 _ 90});
	});

	TEST_CASE(L"Test OrderBy(Compare)")
	{
		vint numbers[] = { 7, 1, 12, 2, 8, 3, 11, 4, 9, 5, 13, 6, 10 };
		List<vint> list;
		CopyFrom(list, From(numbers).OrderBy(Compare));
		CHECK_LIST_ITEMS(list, { 1 _ 2 _ 3 _ 4 _ 5 _ 6 _ 7 _ 8 _ 9 _ 10 _ 11 _ 12 _ 13 });
	});

	TEST_CASE(L"Test OrderBy(ReverseCompare)")
	{
		vint numbers[] = { 7, 1, 12, 2, 8, 3, 11, 4, 9, 5, 13, 6, 10 };
		List<vint> list;
		CopyFrom(list, From(numbers).OrderBy(ReverseCompare));
		CHECK_LIST_ITEMS(list, { 13 _ 12 _ 11 _ 10 _ 9 _ 8 _ 7 _ 6 _ 5 _ 4 _ 3 _ 2 _ 1 });
	});

	TEST_CASE(L"Test OrderBySelf()")
	{
		vint numbers[] = { 7, 1, 12, 2, 8, 3, 11, 4, 9, 5, 13, 6, 10 };
		List<vint> list;
		CopyFrom(list, From(numbers).OrderBySelf());
		CHECK_LIST_ITEMS(list, { 1 _ 2 _ 3 _ 4 _ 5 _ 6 _ 7 _ 8 _ 9 _ 10 _ 11 _ 12 _ 13 });
	});

	TEST_CASE(L"Test OrderByKey()")
	{
		vint numbers[] = { 7, 1, 12, 2, 8, 3, 11, 4, 9, 5, 13, 6, 10 };
		List<vint> list;
		CopyFrom(list, From(numbers).OrderByKey(Minus));
		CHECK_LIST_ITEMS(list, { 13 _ 12 _ 11 _ 10 _ 9 _ 8 _ 7 _ 6 _ 5 _ 4 _ 3 _ 2 _ 1 });
	});

	TEST_CASE(L"Test GroupBy()")
	{
		Dictionary<WString, LazyList<vint>> groups;
		List<vint> keys;
		CopyFrom(groups, Range<vint>(1, 10).GroupBy([](vint i) {return itow(i % 3); }));

		CopyFrom(keys, From(groups.Keys()).Select(wtoi));
		CHECK_LIST_ITEMS(keys, {0 _ 1 _ 2});
		CopyFrom(keys, groups[L"0"]);
		CHECK_LIST_ITEMS(keys, {3 _ 6 _ 9});
		CopyFrom(keys, groups[L"1"]);
		CHECK_LIST_ITEMS(keys, {1 _ 4 _ 7 _ 10});
		CopyFrom(keys, groups[L"2"]);
		CHECK_LIST_ITEMS(keys, {2 _ 5 _ 8});
	});

	TEST_CASE(L"Test First() / Last() / Count() / IsEmpty()")
	{
		{
			List<vint> src;
			for (vint i = 1; i <= 10; i++)
			{
				src.Add(i);
			}
			auto dst = From(src).Select(Square).Select(Double);
			TEST_ASSERT(dst.First() == 2);
			TEST_ASSERT(dst.Last() == 200);
			TEST_ASSERT(dst.Count() == 10);
			TEST_ASSERT(dst.IsEmpty() == false);
		}
		{
			List<vint> src;
			for (vint i = 1; i <= 10; i++)
			{
				src.Add(i);
			}
			auto dst = From(src).Where([](vint i) { return false; });
			TEST_ASSERT(dst.Count() == 0);
			TEST_ASSERT(dst.IsEmpty() == true);
		}
	});
}