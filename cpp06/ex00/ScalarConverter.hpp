#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{

	public:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();

		ScalarConverter &		operator=( ScalarConverter const & rhs );
		static void				convert(std::string literal);
		static void				determineType(const std::string& literal);
		static bool				isChar(const std::string& s);
		static bool				isChar(int i);
	private:

};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */