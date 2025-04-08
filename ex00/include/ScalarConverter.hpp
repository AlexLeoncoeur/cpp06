#pragma once

# include <string>
# include <iostream>
# include "colors.hpp"

class ScalarConverter
{
private:
	
	ScalarConverter();
	ScalarConverter(const ScalarConverter &toCopy);

	~ScalarConverter();
	
	ScalarConverter &operator=(const ScalarConverter &rhs);

public:	

	static void	convert(std::string input);

};

