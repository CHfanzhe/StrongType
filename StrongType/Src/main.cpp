#include <iostream>
#include <StrongType/wrapper.hpp>
#include <mutex>
int main() {
	StrongType::wrapper<int, struct MyTag, std::mutex> myWrapper(42);
	myWrapper.lock();
	std::cout << myWrapper.value() << std::endl;
	myWrapper.unlock();
}