#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr<<"Please use the right number of arguments"<<std::endl;
		return 1;
	}
	std::cout<<argv[1]<<std::endl;
	ScalarConverter::convert(argv[1]);
	return 0;
}		
