/***********************************************************************
Author: Zihan Chen (vczh)
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_VARIANT
#define VCZH_VARIANT

#include "../Basic.h"

#ifdef VCZH_CHECK_MEMORY_LEAKS_NEW
#undef new
#endif

namespace vl
{
	template<vint I>
	struct VariantIndex
	{
		static constexpr vint value = I;
	};

	template<typename ...TCallbacks>
	struct Overloading : TCallbacks ...
	{
		using TCallbacks::operator()...;
#ifdef VCZH_GCC
		Overloading(const Overloading<TCallbacks...>&) = default;
		Overloading(Overloading<TCallbacks...>&&) = default;
		Overloading<TCallbacks...>& operator=(const Overloading<TCallbacks...>&) = default;
		Overloading<TCallbacks...>& operator=(Overloading<TCallbacks...>&&) = default;

		template<typename ...TArguments>
		Overloading(TArguments&& ...arguments)
			: TCallbacks(std::forward<TArguments&&>(arguments))...
		{
		}
#endif
	};

	template<typename ...TCallbacks>
	Overloading(TCallbacks&&...) -> Overloading<std::remove_cvref_t<TCallbacks>...>;
}

namespace vl::variant_internal
{
	template<typename T, typename ...TArgs>
	consteval T MaxOf(T first, TArgs ...others)
	{
		T result = first;
		T nexts[] = { others... };
		for (T next : nexts)
		{
			if (result < next) result = next;
		}
		return result;
	}
	template<typename T>
	consteval T MaxOf(T first)
	{
		return first;
	}

	template<vint I, typename T>
	struct VariantElement
	{
		template<typename U>
			requires(std::is_same_v<T, U>)
		static consteval VariantIndex<I> IndexOf() { return {}; }

		static consteval VariantIndex<I> IndexOfCast(const T&) { return {}; }
		static consteval VariantIndex<I> IndexOfCast(T&&) { return {}; }

		template<typename TCallback>
		static bool i_Apply(vint index, char* buffer, TCallback&& callback)
		{
			if (I != index) return false;
			callback(*reinterpret_cast<T*>(buffer));
			return true;
		}

		template<typename TCallback>
		static bool i_Apply(vint index, const char* buffer, TCallback&& callback)
		{
			if (I != index) return false;
			callback(*reinterpret_cast<const T*>(buffer));
			return true;
		}

		static bool i_CopyCtor(vint index, char* buffer, const char* source)
		{
			if constexpr (std::is_copy_constructible_v<T>)
			{
				if (I != index) return false;
				new (buffer)T(*reinterpret_cast<const T*>(source));
				return true;
			}
			else
			{
				return false;
			}
		}

		static bool i_MoveCtor(vint index, char* buffer, char* source)
		{
			if constexpr (std::is_move_constructible_v<T>)
			{
				if (I != index) return false;
				new (buffer)T(std::move(*reinterpret_cast<T*>(source)));
				return true;
			}
			else
			{
				return false;
			}
		}

		static bool i_Dtor(vint index, char* buffer)
		{
			if (I != index) return false;
			reinterpret_cast<T*>(buffer)->~T();
			return true;
		}

		static bool i_CopyAssign(vint index, char* buffer, const char* source)
		{
			if constexpr (std::is_copy_assignable_v<T>)
			{
				if (I != index) return false;
				*reinterpret_cast<T*>(buffer) = *reinterpret_cast<const T*>(source);
				return true;
			}
			else
			{
				return false;
			}
		}

		static bool i_MoveAssign(vint index, char* buffer, char* source)
		{
			if constexpr (std::is_move_constructible_v<T>)
			{
				if (I != index) return false;
				*reinterpret_cast<T*>(buffer) = std::move(*reinterpret_cast<T*>(source));
				return true;
			}
			else
			{
				return false;
			}
		}

		template<typename ...TArgs>
		static void Ctor(VariantIndex<I>, char* buffer, TArgs&& ...args)
		{
			new (buffer)T(std::forward<TArgs&&>(args)...);
		}

		static void DefaultCtor(VariantIndex<I>, char* buffer)
		{
			new (buffer)T();
		}

		static void CopyCtor(VariantIndex<I>, char* buffer, const T& source)
		{
			new (buffer)T(source);
		}

		static void MoveCtor(VariantIndex<I>, char* buffer, T&& source)
		{
			new (buffer)T(std::move(source));
		}

		template<typename TArg>
		static void Assign(VariantIndex<I>, char* buffer, TArg&& value)
		{
			*reinterpret_cast<T*>(buffer) = std::forward<TArg&&>(value);
		}

		static void CopyAssign(VariantIndex<I>, char* buffer, const T& source)
		{
			*reinterpret_cast<T*>(buffer) = source;
		}

		static void MoveAssign(VariantIndex<I>, char* buffer, T&& source)
		{
			*reinterpret_cast<T*>(buffer) = std::move(source);
		}
	};

	template<typename Is, typename ...TElements>
	struct VariantElementPack;

	template<std::size_t ...Is, typename ...TElements>
	struct VariantElementPack<std::index_sequence<Is...>, TElements...> : VariantElement<Is, TElements>...
	{
		using VariantElement<Is, TElements>::IndexOf...;
		using VariantElement<Is, TElements>::IndexOfCast...;
		using VariantElement<Is, TElements>::DefaultCtor...;
		using VariantElement<Is, TElements>::Ctor...;
		using VariantElement<Is, TElements>::CopyCtor...;
		using VariantElement<Is, TElements>::MoveCtor...;
		using VariantElement<Is, TElements>::Assign...;
		using VariantElement<Is, TElements>::CopyAssign...;
		using VariantElement<Is, TElements>::MoveAssign...;

		template<typename TCallback>
		static void Apply(vint index, char* buffer, TCallback&& callback)
		{
			bool result = (VariantElement<Is, TElements>::i_Apply(index, buffer, std::forward<TCallback&&>(callback)) || ...);
			CHECK_ERROR(result, L"vl::variant_internal::VariantElementPack<...>::Apply(...)#Internal error: none of elements are selected.");
		}

		template<typename TCallback>
		static void Apply(vint index, const char* buffer, TCallback&& callback)
		{
			bool result = (VariantElement<Is, TElements>::i_Apply(index, buffer, std::forward<TCallback&&>(callback)) || ...);
			CHECK_ERROR(result, L"vl::variant_internal::VariantElementPack<...>::Apply(...)#Internal error: none of elements are selected.");
		}

		static void CopyCtor(vint index, char* buffer, const char* source)
		{
			bool result = (VariantElement<Is, TElements>::i_CopyCtor(index, buffer, source) || ...);
			CHECK_ERROR(result, L"vl::variant_internal::VariantElementPack<...>::CopyCtor(...)#Internal error: none of elements are selected.");
		}

		static void MoveCtor(vint index, char* buffer, char* source)
		{
			bool result = (VariantElement<Is, TElements>::i_MoveCtor(index, buffer, source) || ...);
			CHECK_ERROR(result, L"vl::variant_internal::VariantElementPack<...>::MoveCtor(...)#Internal error: none of elements are selected.");
		}

		static void Dtor(vint index, char* buffer)
		{
			bool result = (VariantElement<Is, TElements>::i_Dtor(index, buffer) || ...);
			CHECK_ERROR(result, L"vl::variant_internal::VariantElementPack<...>::Dtor(...)#Internal error: none of elements are selected.");
		}

		static void CopyAssign(vint index, char* buffer, const char* source)
		{
			bool result = (VariantElement<Is, TElements>::i_CopyAssign(index, buffer, source) || ...);
			CHECK_ERROR(result, L"vl::variant_internal::VariantElementPack<...>::CopyAssign(...)#Internal error: none of elements are selected.");
		}

		static void MoveAssign(vint index, char* buffer, char* source)
		{
			bool result = (VariantElement<Is, TElements>::i_MoveAssign(index, buffer, source) || ...);
			CHECK_ERROR(result, L"vl::variant_internal::VariantElementPack<...>::MoveAssign(...)#Internal error: none of elements are selected.");
		}
	};
}

namespace vl
{
	template<typename T>
	concept VariantElementType = requires()
	{
		std::is_same_v<T, std::remove_cvref_t<T>>;
	};

	template<VariantElementType ...TElements>
	class alignas(TElements...) Variant
	{
	public:
		template<VariantElementType ...UElements>
		friend class Variant;

		using ElementPack = variant_internal::VariantElementPack<std::make_index_sequence<sizeof...(TElements)>, TElements...>;

		template<typename T>
		static constexpr vint IndexOf = decltype(ElementPack::template IndexOf<T>())::value;

		template<typename T>
		static constexpr vint IndexOfCast = decltype(ElementPack::IndexOfCast(std::declval<T>()))::value;

		static constexpr std::size_t	MaxSize = variant_internal::MaxOf(sizeof(TElements)...);
		vint							index = -1;
		char							buffer[MaxSize];

	public:
		Variant()
			requires(std::is_default_constructible_v<TypeTupleElement<0, TypeTuple<TElements...>>>)
			: index(0)
		{
			ElementPack::DefaultCtor(VariantIndex<0>{}, buffer);
		}

		Variant(const Variant<TElements...>& variant)
			: index(variant.index)
		{
			ElementPack::CopyCtor(index, buffer, variant.buffer);
		}

		Variant(Variant<TElements...>&& variant)
			: index(variant.index)
		{
			ElementPack::MoveCtor(index, buffer, variant.buffer);
		}

		template<typename T>
			requires((std::is_same_v<T, TElements> || ...))
		Variant(const T& element)
		{
			constexpr auto i = IndexOf<T>;
			index = i;
			ElementPack::CopyCtor(VariantIndex<i>{}, buffer, element);
		}

		template<typename T>
			requires((std::is_same_v<T, TElements> || ...))
		Variant(T&& element)
		{
			constexpr auto i = IndexOf<T>;
			index = i;
			ElementPack::MoveCtor(VariantIndex<i>{}, buffer, std::move(element));
		}

		template<vint I, typename ...TArgs>
		Variant(VariantIndex<I> i, TArgs&& ...args)
			: index(I)
		{
			ElementPack::Ctor(i, buffer, std::forward<TArgs&&>(args)...);
		}

		template<typename T>
			requires(
				!std::is_same_v<std::remove_cvref_t<T>, Variant<TElements...>> &&
				((!std::is_same_v<std::remove_cvref_t<T>, TElements>) && ...)
			)
		Variant(T&& value)
		{
			constexpr auto i = IndexOfCast<T&&>;
			index = i;
			ElementPack::Ctor(VariantIndex<i>{}, buffer, std::forward<T&&>(value));
		}

		~Variant()
		{
			ElementPack::Dtor(index, buffer);
		}

		Variant<TElements...>& operator=(const Variant<TElements...>& variant)
		{
			if (this != &variant)
			{
				if (index == variant.index)
				{
					ElementPack::CopyAssign(index, buffer, variant.buffer);
				}
				else
				{
					ElementPack::Dtor(index, buffer);
					index = variant.index;
					ElementPack::CopyCtor(index, buffer, variant.buffer);
				}
			}
			return *this;
		}

		Variant<TElements...>& operator=(Variant<TElements...>&& variant)
		{
			if (this != &variant)
			{
				if (index == variant.index)
				{
					ElementPack::MoveAssign(index, buffer, variant.buffer);
				}
				else
				{
					ElementPack::Dtor(index, buffer);
					index = variant.index;
					ElementPack::MoveCtor(index, buffer, variant.buffer);
				}
			}
			return *this;
		}

		template<typename T>
			requires((std::is_same_v<T, TElements> || ...))
		Variant<TElements...>& operator=(const T& element)
		{
			constexpr auto i = IndexOf<T>;
			if (index == i)
			{
				ElementPack::CopyAssign(VariantIndex<i>{}, buffer, element);
			}
			else
			{
				ElementPack::Dtor(index, buffer);
				index = i;
				ElementPack::CopyCtor(VariantIndex<i>{}, buffer, element);
			}
			return *this;
		}

		template<typename T>
			requires((std::is_same_v<T, TElements> || ...))
		Variant<TElements...>& operator=(T&& element)
		{
			constexpr auto i = IndexOf<T>;
			if (index == i)
			{
				ElementPack::MoveAssign(VariantIndex<i>{}, buffer, std::move(element));
			}
			else
			{
				ElementPack::Dtor(index, buffer);
				index = i;
				ElementPack::MoveCtor(VariantIndex<i>{}, buffer, std::move(element));
			}
			return *this;
		}

		template<vint I, typename T>
		Variant<TElements...>& Set(VariantIndex<I> i, T&& value)
		{
			if (index == I)
			{
				ElementPack::Assign(i, buffer, std::forward<T&&>(value));
			}
			else
			{
				ElementPack::Dtor(index, buffer);
				index = I;
				ElementPack::Ctor(i, buffer, std::forward<T&&>(value));
			}
			return *this;
		}

		template<typename T>
			requires(
				!std::is_same_v<std::remove_cvref_t<T>, Variant<TElements...>> &&
				((!std::is_same_v<std::remove_cvref_t<T>, TElements>) && ...)
			)
		Variant<TElements...>& operator=(T&& value)
		{
			constexpr auto i = IndexOfCast<T&&>;
			return Set(VariantIndex<i>{}, std::forward<T&&>(value));
		}

		vint Index() const
		{
			return index;
		}

		template<typename T>
			requires((std::is_same_v<T, TElements> || ...))
		T& Get()&
		{
			auto result = TryGet<T>();
			CHECK_ERROR(result != nullptr, L"vl::Variant<T...>::Get<T>()#Content does not match the type.");
			return *result;
		}

		template<typename T>
			requires((std::is_same_v<T, TElements> || ...))
		T&& Get()&&
		{
			auto result = TryGet<T>();
			CHECK_ERROR(result != nullptr, L"vl::Variant<T...>::Get<T>()#Content does not match the type.");
			return std::move(*result);
		}

		template<typename T>
			requires((std::is_same_v<T, TElements> || ...))
		const T& Get() const&
		{
			auto result = TryGet<T>();
			CHECK_ERROR(result != nullptr, L"vl::Variant<T...>::Get<T>()#Content does not match the type.");
			return *result;
		}

		template<typename T>
			requires((std::is_same_v<T, TElements> || ...))
		T* TryGet()
		{
			return const_cast<T*>(static_cast<const Variant<TElements...>*>(this)->TryGet<T>());
		}

		template<typename T>
			requires((std::is_same_v<T, TElements> || ...))
		const T* TryGet() const
		{
			constexpr auto i = IndexOf<T>;
			return index == i ? reinterpret_cast<const T*>(buffer) : nullptr;
		}

		template<typename TCallback>
		void Apply(TCallback&& callback)
		{
			ElementPack::Apply(index, buffer, std::forward<TCallback&&>(callback));
		}

		template<typename TCallback>
		void Apply(TCallback&& callback) const
		{
			ElementPack::Apply(index, buffer, std::forward<TCallback&&>(callback));
		}

		template<typename TCallback>
		bool TryApply(TCallback&& callback)
		{
			bool result = true;
			Apply(Overloading(
				std::forward<TCallback&&>(callback),
				[&result](auto&&) { result = false; }
				));
			return result;
		}

		template<typename TCallback>
		bool TryApply(TCallback&& callback) const
		{
			bool result = true;
			Apply(Overloading(
				std::forward<TCallback&&>(callback),
				[&result](auto&&) { result = false; }
				));
			return result;
		}
	};
}

#ifdef VCZH_CHECK_MEMORY_LEAKS_NEW
#define new VCZH_CHECK_MEMORY_LEAKS_NEW
#endif

#endif