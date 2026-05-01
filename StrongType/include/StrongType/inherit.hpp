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
		inherit_store() noexcept = default;
		inherit_store(const T& value) noexcept : data(value) {}
		inherit_store(T&& value) noexcept : data(std::move(value)) {}

		inherit_store& operator=(const T& other) noexcept {
			data = other;
			return *this;
		}
		inherit_store& operator=(T&& other) noexcept {
			data = std::move(other);
			return *this;
		}

		constexpr const T& value() const & noexcept {
			return data;
		}
		constexpr T& value() & noexcept {
			return data;
		}
		constexpr T&& move() && noexcept {
			return std::move(data);
		}
	};

	template<class... Ts>
	class inherit_default : public Ts... {
		friend struct inherit_cast;
	public:
	};

	template<class... Ts>
	class inherit_all : public Ts... {
		friend struct inherit_cast;
	public:
		using Ts::Ts...;
	};

	struct inherit_cast {
		template<typename T>
		constexpr static const T& reference_const(const T& value) noexcept {
			if constexpr ( std::is_same_v<T, inherit_store<T>> ) {
				return value.data;
			} else if constexpr ( std::is_same_v<T, inherit_default<T>> ) {
				return static_cast<const T&>(value);
			} else if constexpr ( std::is_same_v<T, inherit_all<T>> ) {
				return static_cast<const T&>(value);
			}
			return value;
		}

		template<typename T>
		constexpr static T& reference(T& value) noexcept {
			if constexpr (std::is_same_v<T, inherit_store<T>>) {
				return value.data;
			}
			else if constexpr (std::is_same_v<T, inherit_default<T>>) {
				return static_cast<T&>(value);
			}
			else if constexpr (std::is_same_v<T, inherit_all<T>>) {
				return static_cast<T&>(value);
			}
			return value;
		}

		template<typename T>
		constexpr static T&& move(T&& value) noexcept {
			if constexpr (std::is_same_v<T, inherit_store<T>>) {
				return std::move(value.data);
			}
			else if constexpr (std::is_same_v<T, inherit_default<T>>) {
				return std::move(static_cast<T&>(value));
			}
			else if constexpr (std::is_same_v<T, inherit_all<T>>) {
				return std::move(static_cast<T&>(value));
			}
			return std::move(value);
		}
	};
}