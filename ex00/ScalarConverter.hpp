#pragma once
#include <regex>

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

	static void handleInt(const std::string &input);

	static void handleFloat(const std::string &input);

	static void printImpossible();

	static void handleDouble(const std::string &input);

	static void handleChar(const std::string &input);

public:
	ScalarConverter();

	~ScalarConverter();

	ScalarConverter(const ScalarConverter &other);

	ScalarConverter &operator=(const ScalarConverter &other);

	static void convert(const std::string &input);
};
