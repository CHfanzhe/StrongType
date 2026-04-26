#pragma once

#include <type_traits>
#include <utility>

namespace StrongType {
	struct non_inherit {};

	template<typename T, typename Tag, typename inherit = non_inherit, template<typename> class... Skills >
	class wrapper : public inherit, public Skills<wrapper<T, Tag, inherit, Skills...>>... {
	private: T _v;
	public:
		using inherit::inherit;
		constexpr wrapper() noexcept :_v() {}
		constexpr wrapper(const wrapper&) noexcept(std::is_nothrow_copy_constructible_v<T>) = default;
		constexpr wrapper(wrapper&&) noexcept(std::is_nothrow_move_constructible_v<T>) = default;

		constexpr wrapper(const T& value) noexcept(std::is_nothrow_copy_constructible_v<T>) : _v(value) {}
		constexpr wrapper(T&& value) noexcept(std::is_nothrow_move_constructible_v<T>) : _v(std::move(value)) {}
		constexpr wrapper& operator=(const T& value) noexcept(std::is_nothrow_copy_assignable_v<T>) { _v = value; return *this; }
		constexpr wrapper& operator=(T&& value) noexcept(std::is_nothrow_move_assignable_v<T>) { _v = std::move(value); return *this; }
		
		constexpr const T& value() const & noexcept { return _v; }
		constexpr T& value() & noexcept { return _v; }
		constexpr T&& value() && noexcept { return std::move(_v); }
		constexpr const T&& value() const&& noexcept { return std::move(_v); }

		using TagType = Tag;
		using Type = T;
	};
}