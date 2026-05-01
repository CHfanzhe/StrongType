#pragma once
#include <type_traits>
#include <utility>
#include "inherit.hpp"

#define StrongType_MakeSkill(TYPE,NAME)	template<typename> using NAME = TYPE

namespace StrongType {
	template<typename T>	struct auto_inherit { using type = std::conditional_t<std::is_class_v<T>, inherit::inherit_all<T>, inherit::inherit_store<T>>; };
	template<typename T>	using auto_inherit_t = auto_inherit<T>::type;

	template<typename T>
	struct wrapper_info;

	template<typename _Inherit_T, typename _Tag, template<typename> typename... _Skills>
	class wrapper : public _Inherit_T, public _Skills<wrapper<_Inherit_T, _Tag, _Skills...>>... {
		static_assert(inherit::is_inherit_v<_Inherit_T>, "[wrapper] _Inherit_T only supports inherit::inherit...");
		friend struct wrapper_operator;
	public:
		using _Inherit_T::_Inherit_T;
	};
	



	template<typename _Inherit_T, typename _Tag, template<typename> typename... _Skills>
	using wrapper_auto = wrapper<auto_inherit_t<_Inherit_T>, _Tag, _Skills...>;

	template<typename T>
	struct wrapper_type { using type = void; };
	template<typename _Inherit_T, typename _Tag, template<typename> typename... _Skills>
	struct wrapper_type<wrapper<_Inherit_T, _Tag, _Skills...>> { using type = _Inherit_T; };
	template<typename T> using wrapper_type_t = typename wrapper_type<T>::type;

	template<typename T>
	struct wrapper_tag { using type = void; };
	template<typename _Inherit_T, typename _Tag, template<typename> typename... _Skills>
	struct wrapper_tag<wrapper<_Inherit_T, _Tag, _Skills...>> { using type = _Tag; };
	template<typename T> using wrapper_tag_t = typename wrapper_tag<T>::type;

	template<typename T>
	struct wrapper_skills { using type = void; };
	template<typename _Inherit_T, typename _Tag, template<typename> typename... _Skills>
	struct wrapper_skills<wrapper<_Inherit_T, _Tag, _Skills...>> { using type = std::tuple<_Skills...>; };
	template<typename T> using wrapper_skills_t = typename wrapper_skills<T>::type;

	template<typename T>
	struct wrapper_basictype { using type = void; };
	template<typename _Inherit_T, typename _Tag, template<typename> typename... _Skills>
	struct wrapper_basictype<wrapper<_Inherit_T, _Tag, _Skills...>> { using type = inherit::basictype_inherit_t<_Inherit_T>; };
	template<typename T> using wrapper_basictype_t = typename wrapper_basictype<T>::type;


	template<typename T>	struct is_wrapper : std::false_type {};
	template<typename _Inherit_T, typename _Tag, template<typename> typename... _Skills>
											struct is_wrapper<wrapper<_Inherit_T, _Tag, _Skills...>> : std::true_type {};
	template<typename T>	inline constexpr bool is_wrapper_v = is_wrapper<T>::value;





	struct wrapper_operator {
		template<typename T, typename = std :: enable_if_t<is_wrapper_v<T>>>
		inline static constexpr auto convert(const T& obj) noexcept -> const typename wrapper_type<T>::type& {
			return static_cast<const typename wrapper_type<T>::type&>(obj);
		}
		template<typename T, typename = std::enable_if_t<is_wrapper_v<T>>>
		inline static constexpr auto convert(T& obj) noexcept -> typename wrapper_type<T>::type& {
			return static_cast<typename wrapper_type<T>::type&>(obj);
		}
		template<typename T, typename = std::enable_if_t<is_wrapper_v<T>>>
		inline static constexpr auto convert(T&& obj) noexcept -> typename wrapper_type<T>::type&& {
			return static_cast<typename wrapper_type<T>::type&&>(obj);
		}

		template<typename T, typename = std::enable_if_t<is_wrapper_v<T>>>
		inline static constexpr auto value(const T& obj) noexcept -> const typename wrapper_basictype<T>::type& {
			return inherit::inherit_cast::reference_const(convert(obj));
		}
		template<typename T, typename = std::enable_if_t<is_wrapper_v<T>>>
		inline static constexpr auto value(T& obj) noexcept -> typename wrapper_basictype<T>::type& {
			return inherit::inherit_cast::reference(convert(obj));
		}
		template<typename T, typename = std::enable_if_t<is_wrapper_v<T>>>
		inline static constexpr auto move(T&& obj) noexcept -> typename wrapper_basictype<T>::type&& {
			return inherit::inherit_cast::move(convert(std::forward<T>(obj)));
		}
	};
}