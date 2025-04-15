#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base *generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			std::cout << "A class created" << std::endl;
			return (new A);
		case 1:
			std::cout << "B class created" << std::endl;
			return (new B);
		case 2:
			std::cout << "C class created" << std::endl;
			return (new C);
		default:
			std::cout << "Error: cannot create class" << std::endl;
			return (NULL);
	}
}

void	identify(Base *p)
{
	if (p == nullptr)
		std::cout	<< "Cannot identify class" << std::endl;
	else if (p == dynamic_cast<A*>(p))
		std::cout	<< "This is an A class" << std::endl;
	else if (p == dynamic_cast<B*>(p))
		std::cout	<< "This is an B class" << std::endl;
	else if (p == dynamic_cast<C*>(p))
		std::cout	<< "This is an C class" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout	<< "This is an A class" << std::endl;

	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			std::cout	<< "This is an B class" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				std::cout	<< "This is an C class" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout	<< "cannot identify class" << std::endl;
			}
		}
	}	
}

int	main(void)
{
	Base *ptr = generate();
	Base *wrongPtr = nullptr;

	identify(ptr);
	identify(*ptr);
	identify(wrongPtr);
	identify(*wrongPtr);
	delete ptr;
	return (0);
}