
#include <iostream>

#include "ScalarConverter.hpp"

void testScalarConverter() {

	std::cout << "Test 1: Input '42'" << std::endl;
	ScalarConverter::convert("42");

	std::cout << std::endl;
	std::cout << "Test 2: Input '42.1'" << std::endl;
	ScalarConverter::convert("42.1");

	std::cout << std::endl;
	std::cout << "Test 3: Input '42.4f'" << std::endl;
	ScalarConverter::convert("42.4f");

	std::cout << std::endl;
	std::cout << "Test 3: Input 'a'" << std::endl;
	ScalarConverter::convert("a");

	std::cout << std::endl;
	std::cout << "Test 4.1: Input '-inf'" << std::endl;
	ScalarConverter::convert("-inf");

	std::cout << std::endl;
	std::cout << "Test 4.2: Input 'inf'" << std::endl;
	ScalarConverter::convert("inf");

	std::cout << std::endl;
	std::cout << "Test 4.3: Input '-inff'" << std::endl;
	ScalarConverter::convert("-inff");

	std::cout << std::endl;
	std::cout << "Test 4.4: Input 'inff'" << std::endl;
	ScalarConverter::convert("inff");

	std::cout << std::endl;
	std::cout << "Test 4.6: Input 'nanf'" << std::endl;
	ScalarConverter::convert("nanf");

	std::cout << std::endl;
	std::cout << "Test 4.7: Input 'nan'" << std::endl;
	ScalarConverter::convert("nan");

	std::cout << std::endl;
	std::cout << "Test 5: Input 'hello'" << std::endl;
	ScalarConverter::convert("hello");

	std::cout << std::endl;
	std::cout << "Test 6: Input '12345678901234567890'" << std::endl;
	ScalarConverter::convert("12345678901234567890");
}

int main() {
	testScalarConverter();
	return 0;
}
