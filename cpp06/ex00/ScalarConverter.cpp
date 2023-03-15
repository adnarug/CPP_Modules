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
bool ScalarConverter::isChar(const std::string& s)
{
	return s.length() == 1 && !isdigit(s[0]);
}

bool ScalarConverter::isChar(const int i)
{
	if (i >= 0 && i <= 127 && isprint(static_cast<char>(i)))
		return true;
	std::cout << "Non displayable" << std::endl;
	return false;
}

bool ScalarConverter::isInt(const std::string& literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]))
		return false;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	if (isPseudo_f(literal))
		return true;
	if (literal.length() == 1 && !isdigit(literal[0]))
		return false;
	if (literal.find('.') == std::string::npos)
		return false;
	if (literal.at(literal.length() - 1) != 'f')
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	if (isPseudo_d(literal))
		return true;
	if (literal.length() == 1 && !isdigit(literal[0]))
		return false;
	if (literal.find('.') == std::string::npos)
		return false;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]) && literal[i] != '.')
			return false;
	}
	return true;
}

bool ScalarConverter::isPseudo_f(const std::string& literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	return false;
}
bool ScalarConverter::isPseudo_d(const std::string& literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	return false;
}
/*
** --------------------------------- METHODS ----------------------------------
*/

/*This error indicates that the linker is unable to find the definition for the static member variable _type of the ScalarConverter class.

You need to define the static member variable _type outside of the class definition in the implementation file ScalarConverter.cpp. Add the following line in ScalarConverter.cpp:*/
type ScalarConverter::_type;

type ScalarConverter::determineType(const std::string& literal)
{

	type type;
	if (literal.empty())
		return (INVALID);
	if (isInt(literal))
	{
		type = INT;
		std::cout << "int" << std::endl;
	}
	else if (isFloat(literal))
	{
		type = FLOAT;
		std::cout << "float" << std::endl;
	}
	else if (isDouble(literal))
	{
		type = DOUBLE;
		std::cout << "double" << std::endl;
	}
	else if (isChar(literal))
	{
		type = CHAR;
		// std::cout << "char" << std::endl;
	}
	else
	{
		type = INVALID;
		std::cout << "Invalid input" << std::endl;
	}
	return (type);
}


void ScalarConverter::carryOutConversion(const std::string & literal)
{
	if (getType() == CHAR)
	{
		char c = literal[0];
		std::cout << std::left << "char: '" << c << "'" << std::endl;
		std::cout << std::left << "int: " << static_cast<int>(c) << std::endl;
		std::cout << std::left << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << std::left << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return ;
	}
	if (getType() == INT)
	{
		long i = strtol(literal.c_str(), NULL, 10);
		if (i > INT_MAX || i < INT_MIN)
		{
			errno = ERANGE;
		}
		std::cout << std::left <<   "char: ";
		if (errno == ERANGE)
			std::cout << "impossible" << std::endl;
		else if (isChar(i))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		std::cout << std::left << "int: " << i << std::endl;
		std::cout << std::left << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << std::left << "double: " << static_cast<double>(i) << ".0" << std::endl;
		return ;
	}
	if (getType() == FLOAT)
	{
		if (isPseudo_f(literal))
		{
			std::string pseudo_double =	literal.substr(0, literal.size() - 1);
			std::cout << std::left <<   "char: " << "Impossible" << std::endl;
			std::cout << std::left <<   "int: " << "Impossible" << std::endl;
			std::cout << std::left <<   "float: " << literal << std::endl;
			std::cout << std::left <<   "double: " << pseudo_double << std::endl;
		}
		else
		{
			float f = strtof(literal.c_str(), NULL);
			std::cout << std::left <<   "char: ";
			if (isChar(static_cast<int>(f)))
				std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
			std::cout << std::left <<   "int: " << static_cast<int>(f) << std::endl;
			if (f - static_cast<int>(f) == 0)
				std::cout << "float: "<< f << ".0f" << std::endl;
			else
				std::cout << "float: "<< f  << std::endl;
			if (f - static_cast<int>(f) == 0)
				std::cout << "double: "<< static_cast<double>(f) << ".0f" << std::endl;
			else
				std::cout << "double: " << static_cast<double>(f) << std::endl;
		}
		return ;
	}

	if (getType() == DOUBLE)
	{
		if (isPseudo_d(literal))
		{
			std::string literal_to_print =	literal;
			std::cout << std::left << "char: " << "Impossible" << std::endl;
			std::cout << std::left << "int: " << "Impossible" << std::endl;
			std::cout << std::left << "float: " << literal << "f" << std::endl;
			std::cout << std::left << "double: " << literal << std::endl;

		}
		else
		{
			double d = strtod(literal.c_str(), NULL);
			std::cout << std::left <<   "char: ";
				if (isChar(static_cast<int>(d)))
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
				else
			std::cout << "Non displayable" << std::endl;
			std::cout << std::left << "int: " << static_cast<int>(d) << std::endl;
			std::cout << std::left << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << std::left << std::setw(9) << "double: " << d << std::endl;
		}
		return ;
	}

}

 void ScalarConverter::convert(const std::string  &literal)
{
	checkInput(literal);
	setType(determineType(literal));
	carryOutConversion(literal);
	// printConverted(handleConversion(literal));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

	type ScalarConverter::getType()
	{
		return _type;
	}

	void ScalarConverter::setType(type newType)
	{
		_type = newType;
	}



/* ************************************************************************** */