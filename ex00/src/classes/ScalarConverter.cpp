#include "../../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << BLUE << "ScalarConverter default constructor called" << RESET << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy)
{
	std::cout << BLUE << "ScalarConverter copy constructor called" << RESET << std::endl;
	*this = toCopy;
	return ;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter destructor called" << RESET << std::endl;
	return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	std::cout	<< BLUE << "Copy assignment operator called" << RESET << std::endl;
	(void)rhs;
	return (*this);
}

void	ScalarConverter::convert(std::string input)
{
	std::cout << input.size() << std::endl;
	
	if (input.size() == 1 && std::isalpha(input[0]))
		std::cout	<< MAGENTA
					<< input << std::endl
					<< static_cast<int>(input[0]) << std::endl
					<< static_cast<float>(input[0]) << ".0f" << std::endl
					<< static_cast<double>(input[0]) << ".0" << RESET << std::endl;
	else
		std::cout	<< MAGENTA
					<< static_cast<char>(std::stoi(input)) << std::endl
					<< input << std::endl
					<< input << ".0f" << std::endl
					<< input << ".0" << RESET << std::endl;
	return ;


}

hacer caso de recibir float y double y encargarse de manejar los tamaños o si no
esta en el ascii