#include "ScalarConverter.hpp"

static bool	isChar(std::string& string)
{
	return(string.length() == 1 && !isdigit(string))
}

static bool	isInt(std::string& string)
{
	char	*endptr;
	long	longnum = std::strtol(string.c_str(), endptr, 10);
	return (INT_MAX >= longnum && longnum >= INT_MIN)	
}

static bool	isFloat(std::string& string)
{
	char	*end;
	if(string == "nanf" || string == "+inff" || string == "-inff")
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

void	printChar()
{

}

void	ScalarConverter::convert(std::string str)
{
	char c;
	int number;
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

		printChar();
		printInt();
		printFloat();
		printDouble();
	}
	else if(isFloat(str))
	{
		printChar();
		printInt();
		printFloat();
		printDouble();
	}
	else if(isDouble(str))
	{
		printChar();
		printInt();
		printFloat();
		printDouble();
	}
	else
	{
		printChar();
		printInt();
		printFloat();
		printDouble();
	}
}
