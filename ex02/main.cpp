
#include "Base.hpp"
#include <iostream>

int main() {
	// Test the generate function
	Base* obj1 = Base::generate();
	Base* obj2 = Base::generate();
	Base* obj3 = Base::generate();

	// Test the identify function with pointers
	std::cout << "Testing identify(Base* p):" << std::endl;
	Base::identify(obj1);
	Base::identify(obj2);
	Base::identify(obj3);

	// Test the identify function with references
	std::cout << "Testing identify(Base& p):" << std::endl;
	Base::identify(*obj1);
	Base::identify(*obj2);
	Base::identify(*obj3);

	// Clean up
	delete obj1;
	delete obj2;
	delete obj3;

	return 0;
}
