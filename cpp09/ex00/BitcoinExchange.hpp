#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <sstream>
# include <fstream>
# include <algorithm>
# include <fstream>
# include <utility>


struct Date
{
	size_t		index;
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
		BitcoinExchange(std::string inputFile);
		~BitcoinExchange();

		BitcoinExchange &						operator=( BitcoinExchange const & rhs );
		std::string								inputFile;

		std::map<Date, float> &					getData() ;
		std::map<Date, float> &					getInput() ;

		void									checkFiles();

		void									setData(std::pair<Date, float> pair);
		void									setInput(std::pair<Date, float> pair);
		// void 								readiInputFile(std::string inputFile);
		// void									readDataFile(std::string dataFile);
		
		void									setfsInput(std::ifstream *fdInput);
		void									setfsData(std::ifstream *fdData);
		std::ifstream*							getfsInput() const;
		std::ifstream*							getfsData() const;

		std::string								getInputFile() const;
		void									fillInputMap();

		float									fillMapValue(std::string &line, char delimeter);
		Date 									fillMapDate(std::string &line, char  delimeter);
		void									fillDataMap();
		void									multiplyValues();
		float									findDate(Date const &date);
		float									findClosestDate(Date const &date);

		std::map<Date, float>::iterator		search_map(Date const &date_to_find);
	private:
		std::ifstream							*fsInput;
		std::ifstream							*fsData;
		std::map<Date, float>					_data;
		std::map<Date, float>					_input;
		std::string								_inputFile;

};

std::ostream& operator<<(std::ostream& os, const std::map<Date, float>& m);

#endif /* ************************************************* BITCOINEXCHANGE_H */