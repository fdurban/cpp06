#include "Base.hpp"

int main()
{
	Base	*ptr = generate();
	std::cout<<"Identify by pointer"<<std::endl;
	identify(ptr);
	std::cout<<"Identify by reference"<<std::endl;
	identify(*ptr);
	delete ptr;
}
