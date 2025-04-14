#pragma once

# include <stdint.h>
# include <iostream>
# include <string>
# include "data.hpp"

class Serializer
{
private:
	
	Serializer();
	Serializer(Serializer &toCpy);
	~Serializer();

	Serializer &operator=(const Serializer &rhs);

public:

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
