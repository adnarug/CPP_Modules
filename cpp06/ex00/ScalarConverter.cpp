#include "ScalarConverter.hpp"


type ScalarConverter::_type;
struct formats ScalarConverter::_formats;

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

bool ScalarConverter::isChar(const char i)
{
	if (i >= CHAR_MIN && i <= CHAR_MAX)
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string& literal)
{
	if (literal.length() == 1 && !isdigit(literal[0]))
		return false;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]) && literal[i] != '-' && literal[i] != '+')
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
	if (literal.find('.') == std::string::npos || (literal.find('.') != literal.rfind('.')))
		return false;
	if (literal.at(literal.length() - 1) != 'f')
		return false;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f' && literal[i] != '-' && literal[i] != '+')
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
	if (literal.find('.') == std::string::npos || (literal.find('.') != literal.rfind('.')))
		return false;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]) && literal[i] != '.' && literal[i] != '-' && literal[i] != '+')
			return false;
	}
	return true;
}

bool ScalarConverter::isPseudo_f(const std::string& literal)
{
	if (literal == "nanf")
	{
		setFormat(std::numeric_limits<float>::quiet_NaN());
		setFormat(std::numeric_limits<double>::quiet_NaN());
		return true;
	}
	else if (literal == "+inff" || literal == "inff")
	{
		setFormat(std::numeric_limits<float>::infinity());
		setFormat(std::numeric_limits<double>::infinity());
		return true;
	}
	else if (literal == "-inff")
	{
		setFormat(-1 * std::numeric_limits<float>::infinity());
		setFormat(-1 * std::numeric_limits<double>::infinity());
		return true;
	}
	return false;
}

bool ScalarConverter::isPseudo_d(const std::string& literal)
{
	if (literal == "nan")
	{
		setFormat(std::numeric_limits<float>::quiet_NaN());
		setFormat(std::numeric_limits<double>::quiet_NaN());
		return true;
	}
	else if (literal == "+inf" || literal == "inf")
	{
		setFormat(std::numeric_limits<float>::infinity());
		setFormat(std::numeric_limits<double>::infinity());
		return true;
	}
	else if (literal == "-inf")
	{
		setFormat(-1 * std::numeric_limits<float>::infinity());
		setFormat(-1 * std::numeric_limits<double>::infinity());
		return true;
	}
	return false;
}
/*
** --------------------------------- METHODS ----------------------------------
*/

type ScalarConverter::determineType(const std::string& literal)
{
	type type;
	if (literal.empty())
		return (INVALID);
	if (isInt(literal))
	{
		type = INT;
	}
	else if (isFloat(literal))
	{
		type = FLOAT;
	}
	else if (isDouble(literal))
	{
		type = DOUBLE;
	}
	else if (isChar(literal))
	{
		type = CHAR;
	}
	else
	{
		type = INVALID;
		std::cerr << "Invalid input" << std::endl;
	}
	return (type);
}

void ScalarConverter::printFloat()
{
	if (getFormats().floatVal > FLT_MAX || getFormats().floatVal < -FLT_MAX )
	{
		std::cout << "float : impossible" << std::endl;
	}
	else
	{
		std::cout << std::fixed << "float: " << getFormats().floatVal << "f" << std::endl;
	}
}

void ScalarConverter::printDouble()
{
	if (getFormats().doubleVal > DBL_MAX || getFormats().doubleVal < -DBL_MAX)
	{
		std::cout << "double : impossible" << std::endl;
	}
	else
	{
		setFormat(static_cast<double>(getFormats().doubleVal));
		std::cout << std::fixed << "double: " << getFormats().doubleVal << std::endl;
	}
}

void ScalarConverter::printInt()
{
	if (getFormats().intVal > INT_MAX || getFormats().intVal < INT_MIN)
	{
		std::cout << "int : impossible" << std::endl;
		printIntImpossible();
	}
	else
	{
		setFormat(static_cast<int>(getFormats().doubleVal));
		std::cout << "int: " << getFormats().intVal << std::endl;
	}
}

void ScalarConverter::printIntImpossible()
{
	std::cout << "int : impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	exit (0);
}

void ScalarConverter::printPseudoFloat()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (getFormats().floatVal == std::numeric_limits<float>::infinity())
	{
		std::cout << "float: " << getFormats().floatVal << 'f' << std::endl;
		std::cout << "double: " << getFormats().floatVal << std::endl;

	}
	else if (getFormats().floatVal == -std::numeric_limits<float>::infinity())
	{
		std::cout << "float: " << getFormats().floatVal << 'f' << std::endl;
		std::cout << "double: " << getFormats().floatVal << std::endl;
	}
	else if (getFormats().floatVal != getFormats().floatVal)
	{
		std::cout << "float: " << getFormats().floatVal << 'f' << std::endl;
		std::cout << "double: " << getFormats().floatVal << std::endl;
	}
}

void ScalarConverter::printPseudoDouble()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (getFormats().doubleVal == std::numeric_limits<float>::infinity())
	{
		std::cout << "float: " << getFormats().doubleVal << 'f' << std::endl;
		std::cout << "double: " << getFormats().doubleVal << std::endl;

	}
	else if (getFormats().doubleVal == -std::numeric_limits<float>::infinity())
	{
		std::cout << "float: " << getFormats().doubleVal << 'f' << std::endl;
		std::cout << "double: " << getFormats().doubleVal << std::endl;
	}
	else if (getFormats().doubleVal != getFormats().doubleVal)
	{
		std::cout << "float: " << getFormats().doubleVal << 'f' << std::endl;
		std::cout << "double: " << getFormats().doubleVal << std::endl;
	}
}

void ScalarConverter::printChar()
{ 
	if (!isChar(getFormats().charVal) || getFormats().doubleVal < CHAR_MIN || getFormats().doubleVal > CHAR_MAX )
	{
		std::cout << "char : impossible" << std::endl;	
		return ;
	}
	if (!isprint(getFormats().charVal))
	{
		std::cout << "char : Non displayable" << std::endl;
		return ;
	}
	else
		std::cout << std::left << "char: '" << getFormats().charVal  << "'" << std::endl;
}

void ScalarConverter::printAllFormats()
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void ScalarConverter::carryOutConversion(const std::string & literal)
{
	if (getType() == CHAR)
	{
		char c = static_cast<char>(literal[0]);
		setFormat(c);
		setFormat(static_cast<long int>(c));
		setFormat(static_cast<float>(c));
		setFormat(static_cast<double>(c));
		printAllFormats();
		return ;
	}
	else if (getType() == INT)
	{
		long int i = strtoll(literal.c_str(), NULL, 10);
		setFormat(static_cast<double>(i));
		setFormat(static_cast<char>(i));
		setFormat(i);
		setFormat(static_cast<float>(i));
		printAllFormats();
		return ;
	}
	else if (getType() == FLOAT)
	{
		if (isPseudo_f(literal))
			printPseudoFloat();
		else
		{
			float f = strtof(literal.c_str(), NULL);
			setFormat(static_cast<char>(f));
			setFormat(static_cast<long int>(f));
			setFormat(f);
			setFormat(static_cast<double>(f));
			printAllFormats();
		return ;
		}
	}

	if (getType() == DOUBLE)
	{
		if (isPseudo_d(literal))
			printPseudoDouble();
		else
		{
			long double d = strtold(literal.c_str(), NULL);
			setFormat(d);
			setFormat(static_cast<char>(d));
			setFormat(static_cast<long int>(d));
			setFormat(static_cast<float>(d));
			printAllFormats();
		}
		return ;
	}

}

 void ScalarConverter::convert(const std::string  &literal)
{
	setType(determineType(literal));
	carryOutConversion(literal);
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

struct formats ScalarConverter::getFormats()
{
	return _formats;
}

void ScalarConverter::setFormat(long int const input)
{
	_formats.intVal = input;
}
void ScalarConverter::setFormat(int const input)
{
	_formats.intVal = input;
}
void ScalarConverter::setFormat(char const input)
{
	_formats.charVal = input;
}

void ScalarConverter::setFormat(float const input)
{
	_formats.floatVal = input;
}

void ScalarConverter::setFormat(double const input)
{
	_formats.doubleVal = input;
}

void ScalarConverter::setFormat(long double const input)
{
	_formats.doubleVal = input;
}

/* ************************************************************************** */