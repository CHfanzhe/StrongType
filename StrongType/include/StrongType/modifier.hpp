#pragma once
#include <type_traits>
#include "wrapper.hpp"
namespace StrongType::modifier {
    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct addable {
        constexpr friend T operator+(const T& lhs, const T& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) + StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T operator+(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) + rhs);
        }

        constexpr friend T operator+(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return T(lhs + StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T& operator+=(T& lhs, const T& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) += StrongType::wrapper_operator::value(rhs);
            return lhs;
        }

        constexpr friend T& operator+=(T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) += rhs;
            return lhs;
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct subtractable {
        constexpr friend T operator-(const T& lhs, const T& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) - StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T& operator-=(T& lhs, const T& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) -= StrongType::wrapper_operator::value(rhs);
            return lhs;
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct multiplicable {
        constexpr friend T operator*(const T& lhs, const T& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) * StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T operator*(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) * rhs);
        }

        constexpr friend T operator*(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return T(lhs * StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T& operator*=(T& lhs, const T& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) *= StrongType::wrapper_operator::value(rhs);
            return lhs;
        }

        constexpr friend T& operator*=(T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) *= rhs;
            return lhs;
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct dividable {
        constexpr friend T operator/(const T& lhs, const T& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) / StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T& operator/=(T& lhs, const T& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) /= StrongType::wrapper_operator::value(rhs);
            return lhs;
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct modulable {
        constexpr friend T operator%(const T& lhs, const T& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) % StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T& operator%=(T& lhs, const T& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) %= StrongType::wrapper_operator::value(rhs);
            return lhs;
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct incrementable {
        constexpr friend T& operator++(T& t) noexcept {
            ++StrongType::wrapper_operator::value(t);
            return t;
        }

        constexpr friend const T operator++(T& t, int) noexcept {
            T ret(t);
            ++StrongType::wrapper_operator::value(t);
            return ret;
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct decrementable {
        constexpr friend T& operator--(T& t) noexcept {
            --StrongType::wrapper_operator::value(t);
            return t;
        }

        constexpr friend const T operator--(T& t, int) noexcept {
            T ret(t);
            --StrongType::wrapper_operator::value(t);
            return ret;
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct equality_comparable {
        constexpr friend bool operator==(const T& lhs, const T& rhs) noexcept {
            return StrongType::wrapper_operator::value(lhs) == StrongType::wrapper_operator::value(rhs);
        }

        constexpr friend bool operator==(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return StrongType::wrapper_operator::value(lhs) == rhs;
        }

        constexpr friend bool operator==(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return lhs == StrongType::wrapper_operator::value(rhs);
        }

        constexpr friend bool operator!=(const T& lhs, const T& rhs) noexcept {
            return StrongType::wrapper_operator::value(lhs) != StrongType::wrapper_operator::value(rhs);
        }

        constexpr friend bool operator!=(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return StrongType::wrapper_operator::value(lhs) != rhs;
        }

        constexpr friend bool operator!=(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return lhs != StrongType::wrapper_operator::value(rhs);
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct orderable {
        constexpr friend bool operator<(const T& lhs, const T& rhs) noexcept {
            return StrongType::wrapper_operator::value(lhs) < StrongType::wrapper_operator::value(rhs);
        }

        constexpr friend bool operator<(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return StrongType::wrapper_operator::value(lhs) < rhs;
        }

        constexpr friend bool operator<(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return lhs < StrongType::wrapper_operator::value(rhs);
        }

        constexpr friend bool operator<=(const T& lhs, const T& rhs) noexcept {
            return StrongType::wrapper_operator::value(lhs) <= StrongType::wrapper_operator::value(rhs);
        }

        constexpr friend bool operator<=(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return StrongType::wrapper_operator::value(lhs) <= rhs;
        }

        constexpr friend bool operator<=(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return lhs <= StrongType::wrapper_operator::value(rhs);
        }

        constexpr friend bool operator>(const T& lhs, const T& rhs) noexcept {
            return StrongType::wrapper_operator::value(lhs) > StrongType::wrapper_operator::value(rhs);
        }

        constexpr friend bool operator>(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return StrongType::wrapper_operator::value(lhs) > rhs;
        }

        constexpr friend bool operator>(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return lhs > StrongType::wrapper_operator::value(rhs);
        }

        constexpr friend bool operator>=(const T& lhs, const T& rhs) noexcept {
            return StrongType::wrapper_operator::value(lhs) >= StrongType::wrapper_operator::value(rhs);
        }

        constexpr friend bool operator>=(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return StrongType::wrapper_operator::value(lhs) >= rhs;
        }

        constexpr friend bool operator>=(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return lhs >= StrongType::wrapper_operator::value(rhs);
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct arithmetic : addable<T>,
        subtractable<T>,
        multiplicable<T>,
        dividable<T>,
        modulable<T>,
        incrementable<T>,
        decrementable<T>,
        equality_comparable<T>,
        orderable<T> {};

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct bitwise_orable {
        constexpr friend T operator|(const T& lhs, const T& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) | StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T operator|(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) | rhs);
        }

        constexpr friend T operator|(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return T(lhs | StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T& operator|=(T& lhs, const T& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) |= StrongType::wrapper_operator::value(rhs);
            return lhs;
        }

        constexpr friend T& operator|=(T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) |= rhs;
            return lhs;
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct bitwise_andable {
        constexpr friend T operator&(const T& lhs, const T& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) & StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T operator&(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) & rhs);
        }

        constexpr friend T operator&(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return T(lhs & StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T& operator&=(T& lhs, const T& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) &= StrongType::wrapper_operator::value(rhs);
            return lhs;
        }

        constexpr friend T& operator&=(T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) &= rhs;
            return lhs;
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct bitwise_xorable {
        constexpr friend T operator^(const T& lhs, const T& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) ^ StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T operator^(const T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            return T(StrongType::wrapper_operator::value(lhs) ^ rhs);
        }

        constexpr friend T operator^(const typename StrongType::wrapper_type<T>::type& lhs, const T& rhs) noexcept {
            return T(lhs ^ StrongType::wrapper_operator::value(rhs));
        }

        constexpr friend T& operator^=(T& lhs, const T& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) ^= StrongType::wrapper_operator::value(rhs);
            return lhs;
        }

        constexpr friend T& operator^=(T& lhs, const typename StrongType::wrapper_type<T>::type& rhs) noexcept {
            StrongType::wrapper_operator::value(lhs) ^= rhs;
            return lhs;
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct bitwise_negatable {
        constexpr friend T operator~(const T& lhs) noexcept {
            return T(~StrongType::wrapper_operator::value(lhs));
        }
    };

    template<typename T, typename = std::enable_if_t<StrongType::is_wrapper_v<T>>>
    struct bitwise_manipulable : bitwise_orable<T>,
        bitwise_andable<T>,
        bitwise_xorable<T>,
        bitwise_negatable<T> {};

}