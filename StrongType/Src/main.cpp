#include <iostream>
#include <StrongType/StrongType.hpp>//
#include <mutex>
int add(int a, int b) noexcept { return a + b; }
int main() {
	StrongType::wrapper<StrongType::inherit::inherit_store<int>, struct MyTag> myWrapper = 1;
	std::cout << typeid(StrongType::wrapper_info<decltype(myWrapper)>::Type).name() << std::endl;
	std::cout << myWrapper.value() << std::endl;
	//std::cout << myWrapper.value() << std::endl;
}