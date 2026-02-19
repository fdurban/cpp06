#include "Base.hpp"

Base::~Base(){}

Base	*generate(void)
{
	std::srand(std::time(0));
	int choice = std::rand() % 3;
	switch(choice)
	{
		case 0:
			return new A;
			break;
		case 1:
			return new B;
			break;
		default:
			return new C;
			break;
	}
}


void	identify(Base *p)
{
	if(dynamic_cast<A *>(p))
		std::cout<<"A"<<std::endl;
	else if(dynamic_cast<B *>(p))
		std::cout<<"B"<<std::endl;
	else if(dynamic_cast<C *>(p))
		std::cout<<"C"<<std::endl;
	else
		std::cout<<"undefined type"<<std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout<<"A"<<std::endl;
		return;
	}
	catch(std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout<<"B"<<std::endl;
		return;
	}
	catch(std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout<<"C"<<std::endl;
		return;
	}
	catch(std::exception &e)
	{
	}
}
