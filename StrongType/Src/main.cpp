#include <iostream>
#include <StrongType/StrongType.hpp>
#include <mutex>
int add(int a, int b) noexcept { return a + b; }
int main() {
	StrongType::wrapper<int, struct MyTag, StrongType::inherit::non_inherit, StrongType::modifier::arithmetic> myWrapper = 1;
	std::cout << myWrapper.value() << std::endl;
	std::cout << (myWrapper += 100).value() << std::endl;
	std::cout << myWrapper.value() << std::endl;
}