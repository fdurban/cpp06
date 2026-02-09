#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){}


static bool	isChar(std::string& string)
{
	return(string.length() == 1 && !std::isdigit(string[0]));
}

static bool	isInt(std::string& string)
{
	char	*endptr;
	long	longnum = std::strtol(string.c_str(), &endptr, 10);
	return (INT_MAX >= longnum && longnum >= INT_MIN);
}

static bool	isFloat(std::string& string)
{
	char	*end;
	if (string == "nanf" || string == "+inff" || string == "-inff")
		return (true);
	std::strtof(string.c_str(), &end);
	return (*end == 'f' && *(end + 1) == '\0');
}

static bool	isDouble(std::string&	string)
{
	char	*end;
	if (string == "nan" || string == "+inf" || string == "-inf")
		return (true);
	std::strtod(string.c_str(), &end);
	return (*end == '\0');
}


// print functions of char

void	printChar(char c)
{
	if (!isprint(c))
		std::cout<<"char: Non displayable"<<std::endl;
	else
		std::cout<<"char: "<<c<<std::endl;
}

void	printInt(char c)
{
	std::cout<<"int :"<<static_cast<int>(c)<<std::endl;
}

void	printFloat(char c)
{
	float result;
	result = static_cast<float>(c);
	std::cout<<"float: "<<result<<std::endl;
}

void	printDouble(char c)
{
	double result;
	result =  static_cast<double>(c);
	std::cout<<"double: "<<result<<std::endl;
}

// print functions of int


void	printChar(int i)
{
	char	result;
	
	if (i < 0 || i > 127)
		std::cout<<"char: impossible"<<std::endl;
	else if (!isprint(static_cast<char>(i)))
		std::cout<<"char: Non displayable"<<std::endl;
	else
	{
		result = static_cast<char>(i);
		std::cout<<"char: "<<result<<std::endl;
	}
}

void	printInt(int i)
{
	std::cout<<"int: "<<i<<std::endl;
}

void	printFloat(int i)
{
	float result;
	result = static_cast<float>(i);
	std::cout<<"float: "<<result<<"f"<<std::endl;
}

void	printDouble(int i)
{
	double result;
	result =  static_cast<double>(i);
	std::cout<<"double: "<<result<<std::endl;
}

//print functions of float


void	printChar(float f) {

	char	result;
	
	if (f < 0 || f > 127)
		std::cout<<"char: impossible"<<std::endl;
	else if (!isprint(static_cast<char>(f)))
		std::cout<<"char: Non displayable"<<std::endl;
	else
	{
		result = static_cast<char>(f);
		std::cout<<"char: "<<result<<std::endl;
	}
}

void	printInt(float f)
{
	std::cout<<"int :"<<static_cast<int>(f)<<std::endl;
}

void	printFloat(float c)
{
	std::cout<<"float: "<<c<<std::endl;
}

void	printDouble(float f)
{
	double result;
	result =  static_cast<double>(f);
	std::cout<<"double: "<<result<<std::endl;
}

// print functions of double


void	printChar(double c)
{
	char	result;
	
	if (c < 0 || c > 127)
		std::cout<<"char: impossible"<<std::endl;
	else if(!isprint(static_cast<char>(c)))
		std::cout<<"char: Non displayable"<<std::endl;
	else
	{
		result = static_cast<char>(c);
		std::cout<<"char: "<<result<<std::endl;
	}
}

void	printInt(double c)
{
	std::cout<<"int :"<<static_cast<int>(c)<<std::endl;
}

void	printFloat(double c)
{
	float result;
	result = static_cast<float>(c);
	std::cout<<"float: "<<result<<std::endl;
}

void	printDouble(double c)
{
	double result;
	result =  static_cast<double>(c);
	std::cout<<"double: "<<result<<std::endl;
}

void	ScalarConverter::convert(std::string str)
{
	char c;
	int number;
	long tmp;
	char *end;
	float floatNum;
	double doubleNum;

	if(isChar(str))
	{
		c = str[0];
		printChar(c);
		printInt(c);
		printFloat(c);
		printDouble(c);
	}
	else if(isInt(str))
	{
		tmp = std::strtol(str.c_str(), &end, 10);
		number = static_cast<int>(tmp);
		printChar(number);
		printInt(number);
		printFloat(number);
		printDouble(number);
	}
	else if(isFloat(str))
	{
		floatNum = strtof(str.c_str(), NULL);
		printChar(floatNum);
		printInt(floatNum);
		printFloat(floatNum);
		printDouble(floatNum);
	}
	else if(isDouble(str))
	{
		doubleNum = strtod(str.c_str(), NULL);
		printChar(doubleNum);
		printInt(doubleNum);
		printFloat(doubleNum);
		printDouble(doubleNum);
	}
	else
	{
		std::cout<<"char: impossible";
		std::cout<<"int: impossible";
		std::cout<<"float: impossible";
		std::cout<<"long: impossible";
		std::cout<<"double: impossible";
	}
}
