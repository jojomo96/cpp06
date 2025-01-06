#pragma once
#include <iostream>
#include <regex>
#include <cmath>
#include <sstream>

class ScalarConverter {
	enum class Type {
		INT,
		FLOAT,
		DOUBLE,
		CHAR,
		PSEUDO_FLOAT,
		PSEUDO_DOUBLE,
		IMPOSSIBLE
	};

	static const std::regex intRegex;
	static const std::regex floatRegex;
	static const std::regex doubleRegex;
	static const std::regex charRegex;

	static const std::regex pseudoFloatRegex;

	static const std::regex pseudoDoubleRegex;

	static Type determineType(const std::string &input);

	static void printImpossible();

	ScalarConverter();

	~ScalarConverter();

	ScalarConverter(const ScalarConverter &other);

	ScalarConverter &operator=(const ScalarConverter &other);

	template <typename T>
	static void handleType(T value);
public:

	static void handlePseudoFloat(const std::string &input);

	static void handlePseudoDouble(const std::string &input);

	static void convert(const std::string &input);
};

template <typename FloatT>
std::string formatFloatingNumber(FloatT value, const char* suffix = "") {
	FloatT intPart;
	if (std::modf(value, &intPart) == 0.0) {
		// No fractional part
		std::ostringstream oss;
		oss << value << ".0" << suffix;
		return oss.str();
	}
	// There is a fractional part
	std::ostringstream oss;
	oss << value << suffix;
	return oss.str();
}

template <typename From, typename To>
bool inRange(From val)
{
	const auto lval = static_cast<long double>(val);
	const auto min  = static_cast<long double>(std::numeric_limits<To>::lowest());
	const auto max  = static_cast<long double>(std::numeric_limits<To>::max());
	return lval >= min && lval <= max;
}

template<typename T>
void handleInt(T value) {
	if (inRange<T, int>(value)) {
		const int intValue = static_cast<int>(value);
		std::cout << "int: " << intValue << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}
}

template<typename T>
void handleFloat(T value) {
	if (inRange<T, float>(value))
	{
		const auto floatValue = static_cast<float>(value);
		std::cout << "float: " << formatFloatingNumber(floatValue, "f") << std::endl;
	} else {
		std::cout << "float: impossible" << std::endl;
	}
}

template<typename T>
void handleDouble(T value) {
	const auto doubleValue = static_cast<double>(value);
	std::cout << "double: " << formatFloatingNumber(doubleValue) << std::endl;
}

template<typename T>
void handleChar(T value) {
	if (inRange<T, char>(value)) {
		if (std::isprint(static_cast<int>(value))) {
			const char charValue = static_cast<char>(value);
			std::cout << "char: '" << charValue << "'" << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
	} else {
		std::cout << "char: impossible" << std::endl;
	}
}

template<typename T>
void ScalarConverter::handleType(T value) {
	handleChar(value);
	handleInt(value);
	handleFloat(value);
	handleDouble(value);
}
