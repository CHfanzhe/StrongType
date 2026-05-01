#pragma once
#include <type_traits>
#include <utility>

namespace StrongType::inherit {
	template<typename T>
	class inherit_store {
	private:
		friend struct inherit_cast;
		T data;
	public:
		constexpr inherit_store() noexcept = default;
		constexpr explicit inherit_store(const T& value) noexcept : data(value) {}
		constexpr explicit inherit_store(T&& value) noexcept : data(std::move(value)) {}

		constexpr inherit_store& operator=(const T& other) noexcept {
			data = other;
			return *this;
		}
		constexpr inherit_store& operator=(T&& other) noexcept {
			data = std::move(other);
			return *this;
		}

		constexpr const T& store_value() const & noexcept {
			return data;
		}
		constexpr T& store_value() & noexcept {
			return data;
		}
		constexpr T&& store_move() && noexcept {
			return std::move(data);
		}
	};

	template<class T>
	class inherit_default : public T {
		friend struct inherit_cast;
	};

	template<class T>
	class inherit_all : public T {
		friend struct inherit_cast;
	public:
		using T::T;
	};

	template<typename T>		struct is_inherit_store : std::false_type {};
	template<typename T>		struct is_inherit_store<inherit_store<T>> : std::true_type {};
	template<typename T>		inline constexpr bool is_inherit_store_v = is_inherit_store<T>::value;

	template<typename T>		struct is_inherit_default : std::false_type {};
	template<typename T>		struct is_inherit_default<inherit_default<T>> : std::true_type {};
	template<typename T>		inline constexpr bool is_inherit_default_v = is_inherit_default<T>::value;

	template<typename T>		struct is_inherit_all : std::false_type {};
	template<typename T>		struct is_inherit_all<inherit_all<T>> : std::true_type {};
	template<typename T>		inline constexpr bool is_inherit_all_v = is_inherit_all<T>::value;
	
	template<typename T>		using is_inherit = std::disjunction<is_inherit_all<T>, is_inherit_default<T>, is_inherit_store<T>>;
	template<typename T>		inline constexpr bool is_inherit_v = is_inherit<T>::value;

	template<typename T>		struct basictype_inherit_store { using type = void; };
	template<typename T>		struct basictype_inherit_store <inherit_store<T>> { using type = T; };
	template<typename T>		using basictype_inherit_store_t = typename basictype_inherit_store<T>::type;

	template<typename T>		struct basictype_inherit_default { using type = void; };
	template<typename T>		struct basictype_inherit_default<inherit_default<T>> { using type = T; };
	template<typename T>		using basictype_inherit_default_t = typename basictype_inherit_default<T>::type;

	template<typename T>		struct basictype_inherit_all { using type = void; };
	template<typename T>		struct basictype_inherit_all<inherit_all<T>> { using type = T; };
	template<typename T>		using basictype_inherit_all_t = typename basictype_inherit_all<T>::type;

	template<typename T>		struct basictype_inherit {
		using type =	std::conditional_t<is_inherit_all_v<T>, typename basictype_inherit_all<T>::type,
								std::conditional_t<is_inherit_default_v<T>, typename basictype_inherit_default<T>::type,
								std::conditional_t<is_inherit_store_v<T>, typename basictype_inherit_store<T>::type, void >>>;
	};
	template<typename T>		using basictype_inherit_t = typename basictype_inherit<T>::type;

	struct inherit_cast {
		template<typename T, typename = std::enable_if_t<is_inherit_v<T>>>
		inline static constexpr auto reference_const(const T& obj) noexcept -> const basictype_inherit_t<T>& {
			if constexpr ( is_inherit_store_v<T> )	return obj.store_value();
			else														return static_cast<const basictype_inherit_t<T>&>(obj);
		}
		template<typename T, typename = std::enable_if_t<is_inherit_v<T>>>
		inline static constexpr auto reference(T& obj) noexcept -> basictype_inherit_t<T>& {
			if constexpr (is_inherit_store_v<T>)	return obj.store_value();
			else														return static_cast<basictype_inherit_t<T>&>(obj);
		}
		template<typename T, typename = std::enable_if_t<is_inherit_v<T>>>
		inline static constexpr auto move(T&& obj) noexcept -> basictype_inherit_t<T>&& {
			if constexpr (is_inherit_store_v<T>)	return obj.store_move();
			else														return static_cast<basictype_inherit_t<T>&&>(std::forward<T>(obj));
		}
	};
}