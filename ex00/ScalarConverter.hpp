#pragma once
#include <regex>

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

	static void handleInt(const std::string &input);

	static void handleFloat(const std::string &input);

	static void printImpossible();

	static void handleDouble(const std::string &input);

	static void handleChar(const std::string &input);

	ScalarConverter();

	~ScalarConverter();

	ScalarConverter(const ScalarConverter &other);

	ScalarConverter &operator=(const ScalarConverter &other);
public:

	static void handlePsuedoFloat(const std::string &input);

	static void handlePsuedoDouble(const std::string &input);

	static void convert(const std::string &input);
};
