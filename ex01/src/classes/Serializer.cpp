#include "../../include/Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Serializer::Serializer(Serializer &toCpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCpy;
	return ;
}

Serializer::~Serializer()
{
	std::cout << "Default destructor called" << std::endl;
	return ;
}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	if (this != &rhs)
		return *this;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t uInt = reinterpret_cast<uintptr_t>(ptr);
	return (uInt);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *reconverted = reinterpret_cast<Data*>(raw);
	return (reconverted);
}