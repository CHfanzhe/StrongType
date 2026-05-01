#pragma once
#include <type_traits>
#include <utility>
#include "inherit.hpp"
namespace StrongType {
	template<typename T>
	struct wrapper_info;

	template<typename _Inherit_T, typename _Tag, template<typename> typename... _Skills>
	class wrapper : public _Inherit_T, public _Skills<wrapper<_Inherit_T, _Tag, _Skills...>>... {
		static_assert(std::is_class_v<_Inherit_T>, "[wrapper] _Inherit_T must be a class type");
	public:
		using _Inherit_T::_Inherit_T;
	};
	
	template<typename _Inherit_T, typename _Tag, template<typename> typename... _Skills>
	struct wrapper_info<wrapper<_Inherit_T, _Tag, _Skills...>> {
		using Type = _Inherit_T;
		using Tag = _Tag;
		using Skills = std::tuple<_Skills...>;
	};
}