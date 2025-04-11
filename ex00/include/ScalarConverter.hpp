#pragma once

# include <string>
# include <iostream>
# include <iomanip>
# include "colors.hpp"

# define INT_MIN "-2147483648"
# define INT_MAX  "2147483647"

enum converterDataType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	MSF,
	MSD,
	OVERFLOW,
	INVALID
};

class ScalarConverter
{
private:
	
	ScalarConverter();
	ScalarConverter(const ScalarConverter &toCopy);

	~ScalarConverter();
	
	ScalarConverter &operator=(const ScalarConverter &rhs);

public:	

	static void	convert(const std::string input);

};

