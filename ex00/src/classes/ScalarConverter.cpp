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

static bool isInt(const std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue ;
		if (!std::isdigit(input[i]))
			return (false);
	}
	return (true);
}

static bool isFloat(const std::string input)
{
	int	doutCount = 0;

	if (input.find(".") == std::string::npos || input.find("f") == std::string::npos)
		return (false);
	for (size_t i = 0; i < input.size(); i++)
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue ;
		if (i == input.size() - 1 && input[i] == 'f')
			continue ;
		if (!std::isdigit(input[i]) && input[i] != '.')
			return (false);
		if (input[i] == '.')
		{
			if (doutCount >= 1)
				return (false);
			doutCount++;
		}
	}
	return (true);
}

static bool isDouble(const std::string input)
{
	int	doutCount = 0;

	if (input.find(".") == std::string::npos)
		return (false);
	for (size_t i = 0; i < input.size(); i++)
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			continue ;
		if (!std::isdigit(input[i]) && input[i] != '.')
			return (false);
		if (input[i] == '.')
		{
			if (doutCount >= 1)
				return (false);
			doutCount++;
		}
	}
	return (true);
}

converterDataType	getIndex(const std::string input)
{
	if (input.size() == 1 && std::isalpha(input[0]))
		return (CHAR);
	else if (isInt(input))
		return (INT);
	else if (isFloat(input))
		return (FLOAT);
	else if (isDouble(input))
		return (DOUBLE);
	else
		return (INVALID);
}

void	ScalarConverter::convert(const std::string input)
{
	switch (getIndex(input))
	{
	case CHAR:
	{
		std::cout	<< MAGENTA
					<< "Char: '" << input << "'" << std::endl
					<< "Int: " << static_cast<int>(input[0]) << std::endl
					<< "Float: " << static_cast<float>(input[0]) << ".0f" << std::endl
					<< "Double: " << static_cast<double>(input[0]) << ".0" << RESET << std::endl;
		break;
	}
	case INT:
	{
		if (!isprint(static_cast<char>(std::atoi(input.c_str()))))
			std::cout	<< MAGENTA << "Char: '" << static_cast<char>(std::atoi(input.c_str())) << "'" <<  std::endl;
		else
			std::cout	<< MAGENTA << "Char: Non displayable" << std::endl;
		std::cout	<< MAGENTA
					<< "Int: " << std::atoi(input.c_str()) << std::endl
					<< "Float: " << static_cast<float>(std::atoi(input.c_str())) << ".0f" << std::endl
					<< "Double: " << static_cast<double>(std::atoi(input.c_str())) << ".0" << RESET << std::endl;
		break;
	}
	case FLOAT:
	{
		if (!isprint(static_cast<char>(std::atof(input.c_str()))))
			std::cout	<< MAGENTA << "Char: '" << static_cast<char>(std::atoi(input.c_str())) << "'" <<  std::endl;
		else
			std::cout	<< MAGENTA << "Char: Non displayable" << std::endl;
		std::cout << MAGENTA << static_cast<int>(std::atof(input.c_str())) << std::endl;
		std::cout << MAGENTA << input << std::endl;
		std::cout << MAGENTA << input.substr(0, input.find("f")) << RESET << std::endl;
		terminar flaot
		break;
	}
	case DOUBLE:
		break;
	default:
		break;
	}
		
		if (std::isalpha(std::stoi(input)))
			std::cout << MAGENTA << static_cast<char>(std::stoi(input)) << std::endl;
		else if (std::stoi(input) >= 0 && std::stoi(input) <= 255)
			std::cout << MAGENTA << "Non displayable" << std::endl;
		else
			std::cout << MAGENTA << "Impossible" << std::endl;
		

	else
		std::cout	<< MAGENTA
					<< static_cast<char>(std::stoi(input)) << std::endl
					<< static_cast<int>(std::stoi(input)) << std::endl
					<< input << "f" << std::endl
					<< input << RESET << std::endl;
	return ;


}

/* hacer caso de recibir float y double y encargarse de manejar los tamaños o si no
esta en el ascii
-Capar para que no entren varias letras
-Tamaño máximo de cada variable*/