#pragma once

#include <type_traits>
#include <utility>

namespace StrongType {
	namespace inherit {
		struct non_inherit {};
	}

	template<typename T, typename Tag, typename inherit = inherit::non_inherit, template<typename> class... Skills >
	class wrapper : public inherit, public Skills<wrapper<T, Tag, inherit, Skills...>>... {
	private: T _v; friend struct wrapper_controller;
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

		using _TagType = Tag;
		using _Type = T;
		using _Skills = std::tuple<Skills<wrapper<T, Tag, inherit, Skills...>>...>;
		using _Inherit = inherit;
	};

	struct wrapper_controller {
		template<typename T, typename Tag, typename Inherit, template<typename> class... Skills>
		constexpr static const T& unwrapper(const wrapper<T, Tag, Inherit, Skills...>& w) noexcept {
			return w._v;
		}
		template<typename T, typename Tag, typename Inherit, template<typename> class... Skills>
		constexpr static T& unwrapper(wrapper<T, Tag, Inherit, Skills...>& w) noexcept {
			return w._v;
		}
		template<typename T, typename Tag, typename Inherit, template<typename> class... Skills>
		constexpr static T&& unwrapper(wrapper<T, Tag, Inherit, Skills...>&& w) noexcept {
			return std::move(w._v);
		}
	};


	template<typename T>
	struct wrapper_type;

	template<typename T, typename Tag, typename Inherit, template<typename> class... Skills>
	struct wrapper_type<wrapper<T, Tag, Inherit, Skills...>> {
		using type = T;
	};


	template<typename T>
	struct wrapper_tag;

	template<typename T, typename Tag, typename Inherit, template<typename> class... Skills>
	struct wrapper_tag<wrapper<T, Tag, Inherit, Skills...>> {
		using type = Tag;
	};


	template<typename T>
	struct wrapper_inherit;

	template<typename T, typename Tag, typename Inherit, template<typename> class... Skills>
	struct wrapper_inherit<wrapper<T, Tag, Inherit, Skills...>> {
		using type = Inherit;
	};


	template<typename T>
	struct wrapper_skills;

	template<typename T, typename Tag, typename Inherit, template<typename> class... Skills>
	struct wrapper_skills<wrapper<T, Tag, Inherit, Skills...>> {
		using type = std::tuple<Skills<wrapper<T, Tag, Inherit, Skills...>>...>;
	};
}