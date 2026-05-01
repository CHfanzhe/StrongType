#pragma once
#include <type_traits>
#include "wrapper.hpp"

namespace StrongType::modifier {
    template<typename T>
    struct addable {
        constexpr friend T operator+(const T& lhs, const T& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) + wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T operator+(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) + rhs);
        }

        constexpr friend T operator+(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return T(lhs + wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T& operator+=(T& lhs, const T& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) += wrapper_controller::unwrapper(rhs);
            return lhs;
        }

        constexpr friend T& operator+=(T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) += rhs;
            return lhs;
        }
    };

    template<typename T>
    struct subtractable {
        constexpr friend T operator-(const T& lhs, const T& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) - wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T& operator-=(T& lhs, const T& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) -= wrapper_controller::unwrapper(rhs);
            return lhs;
        }
    };

    template<typename T>
    struct multiplicable {
        constexpr friend T operator*(const T& lhs, const T& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) * wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T operator*(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) * rhs);
        }

        constexpr friend T operator*(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return T(lhs * wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T& operator*=(T& lhs, const T& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) *= wrapper_controller::unwrapper(rhs);
            return lhs;
        }

        constexpr friend T& operator*=(T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) *= rhs;
            return lhs;
        }
    };

    template<typename T>
    struct dividable {
        constexpr friend T operator/(const T& lhs, const T& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) / wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T& operator/=(T& lhs, const T& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) /= wrapper_controller::unwrapper(rhs);
            return lhs;
        }
    };

    template<typename T>
    struct modulable {
        constexpr friend T operator%(const T& lhs, const T& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) % wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T& operator%=(T& lhs, const T& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) %= wrapper_controller::unwrapper(rhs);
            return lhs;
        }
    };

    template<typename T>
    struct incrementable {
        constexpr friend T& operator++(T& t) noexcept {
            ++wrapper_controller::unwrapper(t);
            return t;
        }

        constexpr friend const T operator++(T& t, int) noexcept {
            T ret(t);
            ++wrapper_controller::unwrapper(t);
            return ret;
        }
    };

    template<typename T>
    struct decrementable {
        constexpr friend T& operator--(T& t) noexcept {
            --wrapper_controller::unwrapper(t);
            return t;
        }

        constexpr friend const T operator--(T& t, int) noexcept {
            T ret(t);
            --wrapper_controller::unwrapper(t);
            return ret;
        }
    };

    template<typename T>
    struct equality_comparable {
        constexpr friend bool operator==(const T& lhs, const T& rhs) noexcept {
            return wrapper_controller::unwrapper(lhs) == wrapper_controller::unwrapper(rhs);
        }

        constexpr friend bool operator==(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return wrapper_controller::unwrapper(lhs) == rhs;
        }

        constexpr friend bool operator==(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return lhs == wrapper_controller::unwrapper(rhs);
        }

        constexpr friend bool operator!=(const T& lhs, const T& rhs) noexcept {
            return wrapper_controller::unwrapper(lhs) != wrapper_controller::unwrapper(rhs);
        }

        constexpr friend bool operator!=(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return wrapper_controller::unwrapper(lhs) != rhs;
        }

        constexpr friend bool operator!=(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return lhs != wrapper_controller::unwrapper(rhs);
        }
    };

    template<typename T>
    struct orderable {
        constexpr friend bool operator<(const T& lhs, const T& rhs) noexcept {
            return wrapper_controller::unwrapper(lhs) < wrapper_controller::unwrapper(rhs);
        }

        constexpr friend bool operator<(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return wrapper_controller::unwrapper(lhs) < rhs;
        }

        constexpr friend bool operator<(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return lhs < wrapper_controller::unwrapper(rhs);
        }

        constexpr friend bool operator<=(const T& lhs, const T& rhs) noexcept {
            return wrapper_controller::unwrapper(lhs) <= wrapper_controller::unwrapper(rhs);
        }

        constexpr friend bool operator<=(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return wrapper_controller::unwrapper(lhs) <= rhs;
        }

        constexpr friend bool operator<=(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return lhs <= wrapper_controller::unwrapper(rhs);
        }

        constexpr friend bool operator>(const T& lhs, const T& rhs) noexcept {
            return wrapper_controller::unwrapper(lhs) > wrapper_controller::unwrapper(rhs);
        }

        constexpr friend bool operator>(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return wrapper_controller::unwrapper(lhs) > rhs;
        }

        constexpr friend bool operator>(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return lhs > wrapper_controller::unwrapper(rhs);
        }

        constexpr friend bool operator>=(const T& lhs, const T& rhs) noexcept {
            return wrapper_controller::unwrapper(lhs) >= wrapper_controller::unwrapper(rhs);
        }

        constexpr friend bool operator>=(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return wrapper_controller::unwrapper(lhs) >= rhs;
        }

        constexpr friend bool operator>=(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return lhs >= wrapper_controller::unwrapper(rhs);
        }
    };

    template<typename T>
    struct arithmetic : addable<T>,
        subtractable<T>,
        multiplicable<T>,
        dividable<T>,
        modulable<T>,
        incrementable<T>,
        decrementable<T>,
        equality_comparable<T>,
        orderable<T> {};

    template<typename T>
    struct bitwise_orable {
        constexpr friend T operator|(const T& lhs, const T& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) | wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T operator|(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) | rhs);
        }

        constexpr friend T operator|(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return T(lhs | wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T& operator|=(T& lhs, const T& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) |= wrapper_controller::unwrapper(rhs);
            return lhs;
        }

        constexpr friend T& operator|=(T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) |= rhs;
            return lhs;
        }
    };

    template<typename T>
    struct bitwise_andable {
        constexpr friend T operator&(const T& lhs, const T& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) & wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T operator&(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) & rhs);
        }

        constexpr friend T operator&(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return T(lhs & wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T& operator&=(T& lhs, const T& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) &= wrapper_controller::unwrapper(rhs);
            return lhs;
        }

        constexpr friend T& operator&=(T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) &= rhs;
            return lhs;
        }
    };

    template<typename T>
    struct bitwise_xorable {
        constexpr friend T operator^(const T& lhs, const T& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) ^ wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T operator^(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return T(wrapper_controller::unwrapper(lhs) ^ rhs);
        }

        constexpr friend T operator^(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return T(lhs ^ wrapper_controller::unwrapper(rhs));
        }

        constexpr friend T& operator^=(T& lhs, const T& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) ^= wrapper_controller::unwrapper(rhs);
            return lhs;
        }

        constexpr friend T& operator^=(T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            wrapper_controller::unwrapper(lhs) ^= rhs;
            return lhs;
        }
    };

    template<typename T>
    struct bitwise_negatable {
        constexpr friend T operator~(const T& lhs) noexcept {
            return T(~wrapper_controller::unwrapper(lhs));
        }
    };

    template<typename T>
    struct bitwise_manipulable : bitwise_orable<T>,
        bitwise_andable<T>,
        bitwise_xorable<T>,
        bitwise_negatable<T> {};

}