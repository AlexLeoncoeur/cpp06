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
	if ((std::atoll(input.c_str()) > INT_MAX)
		|| std::atoll(input.c_str()) < INT_MIN)
		return (OVERFLOW);
	else if (input == "-inff" || input == "+inff" || input == "nanf")
		return (MSF);
	else if (input == "-inf" || input == "+inf" || input == "nan")
		return (MSD);
	else if (input.size() == 1 && (std::atoi(input.c_str()) >= 0 && std::atoi(input.c_str()) <= 255)
		&& ((input[0] >= 32 && input[0] < 48) || (input[0] >= 58 && input[0] <= 126)))
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
		std::cout	<< GREEN
					<< "Char: '" << input << "'" << std::endl
					<< "Int: " << static_cast<int>(input[0]) << std::endl
					<< "Float: " << static_cast<float>(input[0]) << ".0f" << std::endl
					<< "Double: " << static_cast<double>(input[0]) << ".0" << RESET << std::endl;
		break;
	}
	case INT:
	{
		std::cout << std::fixed << std::setprecision(1);
		if (std::atoi(input.c_str()) >= 0 && std::atoi(input.c_str()) <= 255 && isprint(static_cast<char>(std::atoi(input.c_str()))))
			std::cout	<< BLUE << "Char: '" << static_cast<char>(std::atoi(input.c_str())) << "'" <<  std::endl;
		else
			std::cout	<< BLUE << "Char: Non displayable" << std::endl;
		std::cout	<< BLUE
					<< "Int: " << std::atoi(input.c_str()) << std::endl
					<< "Float: " << static_cast<float>(std::atof(input.c_str())) << "f" << std::endl
					<< "Double: " << static_cast<double>(std::atof(input.c_str())) << RESET << std::endl;
		break;
	}
	case FLOAT:
	{
		std::cout << std::fixed << std::setprecision(input.substr(input.find(".") + 1).size() - 1);
		if (std::atoi(input.c_str()) >= 0 && std::atoi(input.c_str()) <= 255 && isprint(static_cast<char>(std::atof(input.c_str()))))
			std::cout	<< MAGENTA << "Char: '" << static_cast<char>(std::atoi(input.c_str())) << "'" <<  std::endl;
		else
			std::cout	<< MAGENTA << "Char: Non displayable" << std::endl;
		std::cout << MAGENTA << "Int: " << std::atoi(input.c_str()) << std::endl;
		if (std::atof(input.c_str()) == std::atoi(input.c_str()))
		{
			std::cout << MAGENTA << "Float: " << static_cast<float>(std::atof(input.c_str())) << "f" << RESET << std::endl;
			std::cout << MAGENTA << "Double: " << std::atof(input.c_str()) << RESET << std::endl;
		}
		else
		{
			std::cout << MAGENTA << "Float: " << static_cast<float>(std::atof(input.c_str())) << "f" << RESET << std::endl;
			std::cout << MAGENTA << "Double: " << std::atof(input.c_str()) << RESET << std::endl;
		}
		break;
	}
	case DOUBLE:
	{
		if (std::atoi(input.c_str()) >= 0 && std::atoi(input.c_str()) <= 255 && isprint(static_cast<char>(std::atof(input.c_str()))))
			std::cout	<< YELLOW << "Char: '" << static_cast<char>(std::atoi(input.c_str())) << "'" <<  std::endl;
		else
			std::cout	<< YELLOW << "Char: Non displayable" << std::endl;
		std::cout << YELLOW << "Int: " << std::atoi(input.c_str()) << std::endl;
		if (std::atof(input.c_str()) == std::atoi(input.c_str()))
		{
			std::cout << std::fixed << std::setprecision(1);
			std::cout << YELLOW << "Float: " << static_cast<float>(std::atof(input.c_str())) << "f" << RESET << std::endl;
			std::cout << YELLOW << "Double: " << std::atof(input.c_str()) << RESET << std::endl;
		}
		else
		{
			std::cout << std::fixed << std::setprecision(input.substr(input.find(".") + 1).size());
			std::cout << YELLOW << "Float: " << static_cast<float>(std::atof(input.c_str())) << "f" << RESET << std::endl;
			std::cout << YELLOW << "Double: " << std::atof(input.c_str()) << RESET << std::endl;
		}
		break;
	}
	case MSF:
	{
		std::cout	<< MAGENTA << "Char: Impossible" << std::endl;
		std::cout	<< MAGENTA << "Int: Impossible" << std::endl;
		std::cout << MAGENTA << "Float: " << input << RESET << std::endl;
		std::cout << MAGENTA << "Double: " << input.substr(0, input.find_last_of("f"))  << RESET << std::endl;
		break ;
	}
	case MSD:
	{
		std::cout	<< MAGENTA << "Char: Impossible" << std::endl;
		std::cout	<< MAGENTA << "Int: Impossible" << std::endl;
		std::cout << MAGENTA << "Float: " << input << "f"  << RESET << std::endl;
		std::cout << MAGENTA << "Double: " << input << RESET << std::endl;
		break ;
	}
	case OVERFLOW:
	{
		std::cout	<< MAGENTA << "Char: Overflow" << std::endl;
		std::cout	<< MAGENTA << "Int: Overflow" << std::endl;
		std::cout << MAGENTA << "Float: Overflow" << RESET << std::endl;
		std::cout << MAGENTA << "Double: Overflow" << RESET << std::endl;
		break ;
	}
	default:
	{
		std::cout	<< RED << "error: invalid conversion" << RESET << std::endl;
		break;
	}
	}
	return ;


}
