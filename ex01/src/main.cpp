#include "../include/Serializer.hpp"

int	main(void)
{
	Data *pipo;
	uintptr_t	test;

	pipo->nb = 1;
	pipo->name = "Pipo";
	test = Serializer::serialize(pipo);
	std::cout << test << std::endl;
	pipo = Serializer::deserialize(test);
	std::cout << pipo->nb << std::endl;
	std::cout << pipo->name << std::endl;
	Serializer::deserialize(Serializer::serialize(pipo));
	std::cout << pipo->nb << std::endl;
	std::cout << pipo->name << std::endl;
	return (0);
}