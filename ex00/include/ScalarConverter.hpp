#pragma once

# include <string>
# include <iostream>
# include "colors.hpp"

enum converterDataType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSF,
	PSD,
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

