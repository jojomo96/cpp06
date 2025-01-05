#include "ScalarConverter.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <regex>

const std::regex ScalarConverter::intRegex(R"(^-?\d+$)");
const std::regex ScalarConverter::floatRegex(R"(^-?\d+\.\d+f$)");
const std::regex ScalarConverter::doubleRegex(R"(^-?\d+\.\d+$)");
const std::regex ScalarConverter::charRegex(R"(^.$)");
const std::regex ScalarConverter::pseudoFloatRegex(R"(^[-+]?inff|nanf$)");
const std::regex ScalarConverter::pseudoDoubleRegex(R"(^[-+]?inf|nan$)");

ScalarConverter::Type ScalarConverter::determineType(const std::string &input) {
	if (std::regex_match(input, intRegex)) {
		return Type::INT;
	}
	if (std::regex_match(input, floatRegex) || std::regex_match(input, pseudoFloatRegex)) {
		return Type::FLOAT;
	}
	if (std::regex_match(input, doubleRegex) || std::regex_match(input, pseudoDoubleRegex)) {
		return Type::DOUBLE;
	}
	if (std::regex_match(input, charRegex) && std::isprint(input[0])) {
		return Type::CHAR;
	}
	return Type::IMPOSSIBLE;
}

ScalarConverter::ScalarConverter() = default;

ScalarConverter::~ScalarConverter() = default;

ScalarConverter::ScalarConverter(const ScalarConverter &other) = default;

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) = default;

void ScalarConverter::handleInt(const std::string &input) {
	try {
		const int intValue = std::stoi(input);
		std::cout << "int: " << intValue << std::endl;

		// Check and cast to float
		const auto floatValue = static_cast<float>(intValue);
		std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;

		// Check and cast to double
		const auto doubleValue = static_cast<double>(intValue);
		std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;

		// Check and cast to char
		if (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max() &&
		    std::isprint(intValue)) {
			const char charValue = static_cast<char>(intValue);
			std::cout << "char: '" << charValue << "'" << std::endl;
		} else {
			std::cout << "char: impossible" << std::endl;
		}
	} catch (const std::exception &e) {
		printImpossible();
	}
}

void ScalarConverter::handleFloat(const std::string &input) {
	try {
		const float floatValue = std::stof(input);

		// Check and cast to int
		if (floatValue >= std::numeric_limits<int>::min() && floatValue <= std::numeric_limits<int>::max()) {
			const int intValue = static_cast<int>(floatValue);
			std::cout << "int: " << intValue << std::endl;
		} else {
			std::cout << "int: impossible" << std::endl;
		}

		std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;

		// Check and cast to double
		const auto doubleValue = static_cast<double>(floatValue);
		std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;

		// Check and cast to char
		if (floatValue >= std::numeric_limits<char>::min() && floatValue <= std::numeric_limits<char>::max() &&
		    std::isprint(static_cast<int>(floatValue))) {
			const char charValue = static_cast<char>(floatValue);
			std::cout << "char: '" << charValue << "'" << std::endl;
		} else {
			std::cout << "char: impossible" << std::endl;
		}
	} catch (const std::exception &e) {
		printImpossible();
	}
}

void ScalarConverter::handleDouble(const std::string &input) {
	try {
		const double doubleValue = std::stod(input);

		// Check and cast to int
		if (doubleValue >= std::numeric_limits<int>::min() && doubleValue <= std::numeric_limits<int>::max()) {
			const int intValue = static_cast<int>(doubleValue);
			std::cout << "int: " << intValue << std::endl;
		} else {
			std::cout << "int: impossible" << std::endl;
		}

		// Check and cast to float
		if (doubleValue >= -std::numeric_limits<float>::max() && doubleValue <= std::numeric_limits<float>::max()) {
			const auto floatValue = static_cast<float>(doubleValue);
			std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
		} else {
			std::cout << "float: impossible" << std::endl;
		}

		std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;

		// Check and cast to char
		if (doubleValue >= std::numeric_limits<char>::min() && doubleValue <= std::numeric_limits<char>::max() &&
		    std::isprint(static_cast<int>(doubleValue))) {
			const char charValue = static_cast<char>(doubleValue);
			std::cout << "char: '" << charValue << "'" << std::endl;
		} else {
			std::cout << "char: impossible" << std::endl;
		}
	} catch (const std::exception &e) {
		printImpossible();
	}
}

void ScalarConverter::handleChar(const std::string &input) {
	try {
		char charValue = input[0];

		// Cast to int
		const auto intValue = static_cast<int>(charValue);
		std::cout << "int: " << intValue << std::endl;

		// Cast to float
		const auto floatValue = static_cast<float>(charValue);
		std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;

		// Cast to double
		const auto doubleValue = static_cast<double>(charValue);
		std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
		std::cout << "char: '" << charValue << "'" << std::endl;
	} catch (const std::exception &e) {
		printImpossible();
	}
}

void ScalarConverter::convert(const std::string &input) {
	switch (determineType(input)) {
		case Type::INT:
			handleInt(input);
			break;
		case Type::FLOAT:
			handleFloat(input);
			break;
		case Type::DOUBLE:
			handleDouble(input);
			break;
		case Type::CHAR:
			handleChar(input);
			break;
		case Type::IMPOSSIBLE:
			printImpossible();
			break;
	}
}

void ScalarConverter::printImpossible() {
	std::cout << "double: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "char: impossible" << std::endl;
}
