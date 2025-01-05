
#include <iostream>

#include "ScalarConverter.hpp"

void testScalarConverter() {

	std::cout << "Test 1: Input '42'" << std::endl;
	ScalarConverter::convert("42");

	std::cout << std::endl;
	std::cout << "Test 2: Input '42.0'" << std::endl;
	ScalarConverter::convert("42.1");

	std::cout << std::endl;
	std::cout << "Test 3: Input 'a'" << std::endl;
	ScalarConverter::convert("a");

	std::cout << std::endl;
	std::cout << "Test 4: Input 'hello'" << std::endl;
	ScalarConverter::convert("hello");

	std::cout << std::endl;
	std::cout << "Test 5: Input '12345678901234567890'" << std::endl;
	ScalarConverter::convert("12345678901234567890");
}

int main() {
	testScalarConverter();
	return 0;
}
