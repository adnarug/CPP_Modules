#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>

enum type 
{
	INVALID = 0,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO
} ;

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
		static bool				isChar(int i);
		static bool				isPseudo(const std::string& literal);
		static bool				isPseudo_f(const std::string& literal);
		static bool				isPseudo_d(const std::string& literal);

		static type				getType();
		static void				setType(type type);

	private:
		static type 			_type;
};

#endif /* ************************************************* SCALARCONVERTER_H */