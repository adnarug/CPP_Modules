#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <cfloat>
# include <cmath>

enum type 
{
	INVALID = 0,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO
} ;

static struct formats
{
	int		intVal;
	char	charVal;
	float	floatVal;
	double	doubleVal;
} formats;

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();

		ScalarConverter &		operator=( ScalarConverter const &rhs);
		static void				convert(const std::string  &literal);
		static type				determineType(const std::string &literal);
		static void				carryOutConversion(const std::string &literal);

		static bool				isInt(const std::string& literal);
		static bool				isFloat(const std::string& literal);
		static bool				isDouble(const std::string& literal);
		static bool				isChar(const std::string& s);
		static bool				isChar(const char i);

		static void				printAllFormats();
		static void				printChar();
		static void				printInt();
		static void				printFloat();
		static void				printDouble();
		static void				printPseudoFloat();
		static void				printPseudoDouble();
		static void				printPseudoInt();
		static void				printIntImpossible();

		static bool				isPseudo_f(const std::string& literal);
		static bool				isPseudo_d(const std::string& literal);

		static type				getType();
		static void				setType(type type);

		static struct formats		getFormats();
		static void					setFormat(int const input);
		static void					setFormat(char const input);
		static void					setFormat(float const input);
		static void					setFormat(double const input);
	

	private:
		static type 				_type;
		static struct formats		_formats;
};

#endif /* ************************************************* SCALARCONVERTER_H */