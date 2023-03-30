#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	*this = src;
}

BitcoinExchange::BitcoinExchange(std::string inputFile) : _inputFile(inputFile)
{
	this->checkFiles();
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &					operator<<( std::ostream & o, BitcoinExchange & i )
{
	o << "The input map = " << i.getInput();
	return o;
}

//Priniting the input map
std::ostream& operator<<(std::ostream& os, const std::map<Date, float>& m)
{
    for (std::map<Date, float>::const_iterator it = m.begin(); it != m.end(); ++it) {
        os << it->first.joinedDate << " | " << it->second << std::endl;
    }
    return os;
}



bool 			operator<(const Date& lhs, const Date& rhs)
{


    // if (lhs.year != rhs.year) {
    //     return lhs.year < rhs.year;
    // }
    // if (lhs.month != rhs.month) {
    //     return lhs.month < rhs.month;
    // }
		// return lhs.index < rhs.index;

	if (lhs.year != rhs.year) {
		return lhs.year < rhs.year;
	}
	if (lhs.month != rhs.month) {
		return lhs.month < rhs.month;
	}
	return lhs.day < rhs.day;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
//filling _data and _input maps with the input from input and data files

Date	BitcoinExchange::fillMapDate(std::string &line, char  delimeter)
{
	Date date;
	date.joinedDate = line.substr(0, line.find(delimeter));
	date.year = std::atol(line.substr(0, line.find('-')).c_str());
	if (date.year < 2009 || date.year > 2022)
	{
		throw BitcoinExchange::BadInput(line);
	}
	date.month = std::atol(line.substr(line.find('-') + 1, line.find('-')).c_str());
	if (date.month < 1 || date.month > 12)
	{
		throw BitcoinExchange::BadInput(line);
	}
	date.day = std::atol(line.substr(line.rfind('-') + 1).c_str());
	if (date.day < 1 || date.day > 31)
	{
		throw BitcoinExchange::BadInput(line);
	}
	// if (date.year <= 0 || date.month <= 0 || date.day <= 0 || date.joinedDate.empty()) //close stream
	// 	exit (1);
	return date;
}

float		BitcoinExchange::fillMapValue(std::string &line, char  delimeter)
{
	float value;
	value = std::atof(line.substr(line.find(delimeter) + 1).c_str());
	if (value < 0)
	{
		throw BitcoinExchange::NegativeValue();
	}
	else if (value >= INT_MAX)
	{
		throw BitcoinExchange::TooLargeValue();
	}
	return value;
}


void	BitcoinExchange::fillInputMap()
{
	std::ifstream *fsInput = new std::ifstream(this->getInputFile());
	setfsInput(fsInput);
	std::string line;
	float value;
	float *value_new;
	Date date;
	Date *date_new;
	std::pair <Date, float> pair;
	char delimeter = '|';
	if (getfsInput()->is_open() && getfsInput()->good())
	{
		while (getline(*getfsInput(), line))//TODO more parsing
		{
			// std::cout << line << std::endl;
			if (!line.find(delimeter))
				exit (1);
			if (line.find('-') == std::string::npos)
				continue ;
			try
			{
				date = this->fillMapDate(line, delimeter);
				value = this->fillMapValue(line, delimeter);
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
			date_new = new Date(date);
			value_new = new float(value);
			pair = std::make_pair(*date_new, *value_new);
			this->setInput(pair);
		}
	}
	else
	{
		std::cerr << "Error\nUnable to open the file" << std::endl;
		exit(1);
	}

	// delete fsInput;
}
//Funciton which opens the input file and reads it line by line
void BitcoinExchange::performConversion()
{
	Date			date;
	float			value;
	std::string		line;
	std::ifstream	fsInput(this->getInputFile());
	if (fsInput.is_open() && fsInput.good())
	{
		while (getline(fsInput, line))//TODO more parsing
		{
			try
			{
				if (line.empty())
				{
					std::cerr << "Error: empty line" << std::endl;
					continue;
				}
				if (line.find('|') == std::string::npos)
					throw BitcoinExchange::BadInput(line);
				if (line.find('-') == std::string::npos)
					throw BitcoinExchange::BadInput(line);
				date = this->fillMapDate(line, '|');
				value = this->fillMapValue(line, '|');
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				continue ;
			}
			std::cout << date.joinedDate << "=>" << value << " = " << value * (--getData().upper_bound(date))->second << std::endl;
		}

	}
}
//Remove the malloc
void	BitcoinExchange::fillDataMap()
{
	std::ifstream			fsData("data.csv");
	std::string				line;
	float					value;
	// float					*value_new;
	Date					date;
	// Date					*date_new;
	char 					delimeter = ',';
	std::pair <Date, float> pair;
	if (fsData.is_open() && fsData.good())
	{
		while (getline(fsData, line))//TODO more parsing
		{
			// std::cout << line << std::endl;
			if (!line.find(delimeter))
				exit (1);
			if (line.find('-') == std::string::npos)
				continue ;
			try
			{
				date = this->fillMapDate(line, delimeter);
				value = this->fillMapValue(line, delimeter);
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			// date_new = new Date(date);
			// value_new = new float(value);
			pair = std::make_pair(date, value);
			this->setData(pair);
		}
	}
	else
	{
		std::cerr << "Error\nUnable to open the data file" << std::endl;
		exit(1);
	}
}

// Function which takes the date from _input, finds the closest date in _data and returns the value
float		BitcoinExchange::findClosestDate(Date const &date)
{
	std::map<Date, float>::iterator it;

	it = this->getData().lower_bound(date);
	std::cout << " the closest: " << date.joinedDate << std::endl;
	if (it == this->getData().end())
	{
		std::cerr << "Error\nNo data for the given date" << std::endl;
		exit(1);
	}
	return it->second;
}
//Introducing find-like function that will search the map for the given date
std::map<Date, float>::iterator		BitcoinExchange::search_map(Date const &date_to_find)
{
	std::map<Date, float>::iterator it;
	it = this->getData().begin();
	while (it != this->getData().end())
	{
		if (it->first.year == date_to_find.year && it->first.month == date_to_find.month && it->first.day == date_to_find.day)
		{
			return it;
		}
		it++;
	}
	return this->getData().end();
}
// Takes the date from _input finds the corresponding date in _data and returns the multiplication result
float		BitcoinExchange::findDate(Date const &date)
{
	std::map<Date, float>::iterator it;
	std::cout << "Date to find: " << date.joinedDate << std::endl;
	it = search_map(date);
	std::cout << "Date found: " << it->first.joinedDate << std::endl;
	if (it == this->getData().end())
	{
		this->findClosestDate(date);
	}
	return it->second;
}

//Multiply the values

void		BitcoinExchange::multiplyValues()
{
	// std::cout << getInput().size() << std::endl;
	// std:: map <Date, float>::iterator it = getInput().begin();
	// std::cout << it->first.joinedDate << std::endl; 
	std::map<Date, float>::iterator it;
	std::map<Date, float>::iterator it2;

	float value;
	float result;
	for (it = getInput().begin()++; it != getInput().end(); it++)
	{
		value = this->findDate(it->first);
		std::cout << std::endl;
		 std::cout << "value: " << value << std::endl;
		//  std::cout << "exch_rate: " << exch_rate << std::endl;
		result = it->second * value;
		std::cout << it->first.joinedDate << "=>" << it->second << " = " << result << std::endl;
	}
}
void	BitcoinExchange::checkFiles()
{
	if (this->getInputFile().empty())
	{
		std::cerr << "Error\nInvalid file input2" << std::endl;
		exit(1);
	}
	std::ifstream ifsInput;
	std::ifstream ifsData;

	ifsInput.open(this->getInputFile());
	if (!ifsInput.is_open())
	{
		std::cerr << "Error\nUnable to open the input file" << std::endl;
		exit(1);
	}
	ifsData.open("data.csv");
	if (!ifsData.is_open())
	{
		std::cerr << "Error\nUnable to open the database file" << std::endl;
		exit(1);
	}
	if (ifsInput >> std::ws && ifsInput.peek () == EOF)
	{
		std::cerr << "Error\nEmpty input file" << std::endl;
		exit(1);
	}
	if (ifsData >> std::ws && ifsData.peek () == EOF)
	{
		std::cerr << "Error\nEmpty database file" << std::endl;
		exit(1);
	}

}

const char *BitcoinExchange::BadInput::what() const throw()
{
	std::string error = "Error: bad input => ";
	if (!this->bad_line.empty())
		return (error.append(this->bad_line).c_str());
	else
		return "Error: bad input ";
}

BitcoinExchange::BadInput::BadInput(std::string  &message) : bad_line(message)
{
}


const char *BitcoinExchange::NegativeValue::what() const throw()
{
	return "Error: not a positive number";
}

const char *BitcoinExchange::TooLargeValue::what() const throw()
{
	return "Error: too large a number";
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void BitcoinExchange::setData(std::pair<Date, float> my_pair)
{
	this->_data.insert(my_pair);
}


void BitcoinExchange::setInput(std::pair<Date, float> my_pair)
{
	this->_input.insert(my_pair);
}

std::map<Date, float> & BitcoinExchange::getData() 
{
	return this->_data;
}

std::map<Date, float>  & BitcoinExchange::getInput() 
{
	return this->_input;
}

std::string BitcoinExchange::getInputFile() const
{
	return this->_inputFile;
}

std::ifstream *BitcoinExchange::getfsInput() const
{
	return this->fsInput;
}

std::ifstream *BitcoinExchange::getfsData() const
{
	return this->fsData;
}

void BitcoinExchange::setfsInput(std::ifstream *fdInput)
{
	this->fsInput = fdInput;
}

void BitcoinExchange::setfsData(std::ifstream *fdData)
{
	this->fsData = fdData;
}
/* ************************************************************************** */