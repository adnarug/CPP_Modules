#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	(void)rhs;
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/
void ScalarConverter::determineType(const std::string& literal)
{
	if (isChar(literal))
	{
		std::cout << "char: '" << literal << "'" << std::endl;
		return;
	}

	try 
	{
		int i = std::stoi(literal);
		if (isChar(i))
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << i << std::endl;
	}
	catch(const std::exception&) 
	{
		std::cout << "int: impossible" << std::endl;
	}

	try 
	{
		float f = std::stof(literal);
		std::cout << "float: " << f << "f" << std::endl;
	}
	catch(const std::exception&) {
		std::cout << "float: impossible" << std::endl;
	}

	try 
	{
		double d = std::stod(literal);
		std::cout << "double: " << d << std::endl;
	}
	catch(const std::exception&)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string& s)
{
	return s.length() == 1 && !isdigit(s[0]);
}

bool ScalarConverter::isChar(const int i)
{
	return i >= 0 && i <= 127 && std::isprint(static_cast<char>(i));
}


void ScalarConverter::convert(std::string literal)
{
	determineType(literal);
	// printConverted(handleConversion(literal));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */