#include "Base.hpp"

#include <iostream>
#include <random>

Base *Base::generate() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 2);

	if (const int random = dis(gen); random == 0) {
		return new A();
	} else if (random == 1) {
		return new B();
	} else {
		return new C();
	}
}

void Base::identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B *>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C *>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void Base::identify(Base &p) {
	try {
		(void) dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (const std::bad_cast &) {
	}

	try {
		(void) dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	} catch (const std::bad_cast &) {
	}

	try {
		(void) dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	} catch (const std::bad_cast &) {
	}
}
