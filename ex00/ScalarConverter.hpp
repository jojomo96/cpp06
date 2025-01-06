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

	template<class T, class FP>
	static void handleFloating(T value, const char *label, const char *suffix = "");

	template<class T>
	static void handleChar(T value);

	template<typename T>
	static void handleType(T value);

	template<class From, class To>
	static bool inRange(From val);

	template<typename FloatT>
	static std::string formatFloatingNumber(FloatT value, const char *suffix = "");

	template<class T>
	static void handleInt(T value);

public:
	ScalarConverter() = delete;

	~ScalarConverter() = delete;

	ScalarConverter(const ScalarConverter &other) = delete;

	ScalarConverter &operator=(const ScalarConverter &other) = delete;

	static void convert(const std::string &input);
};

template<typename T>
void ScalarConverter::handleType(T value) {
	handleChar(value);
	handleInt(value);
	handleFloating<T, float>(value, "float", "f");
	handleFloating<T, double>(value, "double");
}

template<typename T>
void ScalarConverter::handleChar(T value) {
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

template<typename T, typename FP>
void ScalarConverter::handleFloating(T value, const char *label, const char *suffix) {
	if (std::isinf(value)) {
		std::cout << label << ": " << (value > 0 ? "+inf" : "-inf") << suffix << std::endl;
	} else if (std::isnan(value)) {
		std::cout << label << ": nan" << suffix << std::endl;
	} else if (inRange<T, FP>(value)) {
		auto floatVal = static_cast<FP>(value);
		std::cout << label << ": " << formatFloatingNumber(floatVal, suffix) << std::endl;
	} else {
		std::cout << label << ": impossible" << std::endl;
	}
}

template<typename T>
void ScalarConverter::handleInt(T value) {
	if (inRange<T, int>(value)) {
		const int intValue = static_cast<int>(value);
		std::cout << "int: " << intValue << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}
}

template<typename FloatT>
std::string ScalarConverter::formatFloatingNumber(FloatT value, const char *suffix) {
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

template<typename From, typename To>
bool ScalarConverter::inRange(From val) {
	const auto lval = static_cast<long double>(val);
	const auto min = static_cast<long double>(std::numeric_limits<To>::lowest());
	const auto max = static_cast<long double>(std::numeric_limits<To>::max());
	return lval >= min && lval <= max;
}
