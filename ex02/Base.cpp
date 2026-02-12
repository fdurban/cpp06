#include "Base.hpp"


Base	*generate(void)
{
	int choice = std::rand() %3;
	if(choice == 0) return new A;
	if (choice == 1) return new B;
	return new C;
}

