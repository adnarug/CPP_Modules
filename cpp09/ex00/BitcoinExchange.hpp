#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <algorithm>
# include <climits>


struct Date
{
	int			year;
	int			month;
	int			day;
	std::string joinedDate;
};

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		BitcoinExchange(std::string const &inputFile);
		~BitcoinExchange();

		BitcoinExchange &						operator=( BitcoinExchange const & rhs );
		std::string								inputFile;

		std::map<Date, float> &					getData() ;

		void									checkFiles();

		void									setData(std::pair<Date, float> pair);
		std::string								getInputFile() const;

		float									fillMapValue(std::string &line, char delimeter);
		Date 									fillMapDate(std::string &line, char  delimeter);
		void									fillDataMap();

		void 									performConversion();

		class BadInput : public std::exception
		{
			public:
				BadInput(std::string & bad_line);
				const char *what() const throw();
				const std::string &bad_line;
		};
		class NegativeValue : public std::exception
		{
			const char *what() const throw();

		};
		class TooLargeValue : public std::exception
		{
			const char *what() const throw();

		};
	private:
		std::map<Date, float>					_data;
		std::string								_inputFile;

};

std::ostream& operator<<(std::ostream& os, const std::map<Date, float>& m);
bool 			operator<(const Date& lhs, const Date& rhs);

#endif /* ************************************************* BITCOINEXCHANGE_H */