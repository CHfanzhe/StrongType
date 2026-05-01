#include <iostream>
#include <StrongType/wrapper.hpp>
#include <mutex>
#include <array>
#include <string>
int add(int a, int b) noexcept { return a + b; }
int main() {
	//std::cout << typeid(StrongType::inherit::basictype_inherit_t<decltype(myMutex)>).name() << std::endl;
	StrongType::wrapper_auto<std::string, struct MyTag> mw = {};
	std::array<int, 10> arr{1, 2, 3, 4,5,6,7,8,9,0};
	std::cout << "WWW" << std::endl;
	mw = "Hello, world!";
	std::cout << mw << std::endl;
	//mw = arr;
}