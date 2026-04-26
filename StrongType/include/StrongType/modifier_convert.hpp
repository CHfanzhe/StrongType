#pragma once
#include <type_traits>
#include "wrapper.hpp"

namespace StrongType::modifier_convert {
	template<typename T>
	struct implicit {
		constexpr friend	operator typename StrongType::wrapper_type<T>::type(const T& t) noexcept {
			return wrapper_controller::unwrapper(t);
		};
	};
}