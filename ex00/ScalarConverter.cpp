#include "ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <regex>

const std::regex ScalarConverter::intRegex(R"(^-?\d+$)");
const std::regex ScalarConverter::floatRegex(R"(^-?\d+(\.\d*)?f$)");
const std::regex ScalarConverter::doubleRegex(R"(^-?\d+\.\d+$)");
const std::regex ScalarConverter::charRegex(R"(^.$)");
const std::regex ScalarConverter::pseudoFloatRegex(R"(^[-+]?inff|nanf$)");
const std::regex ScalarConverter::pseudoDoubleRegex(R"(^[-+]?inf|nan$)");

ScalarConverter::Type ScalarConverter::determineType(const std::string &input) {
	if (std::regex_match(input, intRegex)) return Type::INT;
	if (std::regex_match(input, floatRegex) || std::regex_match(input, pseudoFloatRegex)) return Type::FLOAT;
	if (std::regex_match(input, doubleRegex) || std::regex_match(input, pseudoDoubleRegex)) return Type::DOUBLE;
	if (std::regex_match(input, charRegex) && std::isprint(input[0])) return Type::CHAR;
	return Type::IMPOSSIBLE;
}

void ScalarConverter::convert(const std::string &input) {
	try {
		switch (determineType(input)) {
			case Type::INT: handleType(std::stoi(input)); break;
			case Type::FLOAT: handleType(std::stof(input)); break;
			case Type::DOUBLE: handleType(std::stod(input)); break;
			case Type::CHAR: handleType(input[0]); break;
			case Type::IMPOSSIBLE: printImpossible(); break;
		}
	} catch ([[maybe_unused]] const std::exception &e) {
		printImpossible();
	}
}

void ScalarConverter::printImpossible() {
	std::cout << "double: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "char: impossible" << std::endl;
}
