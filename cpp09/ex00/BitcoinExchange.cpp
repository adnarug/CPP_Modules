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

BitcoinExchange::BitcoinExchange(std::string const &inputFile) : _inputFile(inputFile)
{
	this->checkFiles();
	this->fillDataMap();
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
	this->_inputFile = rhs._inputFile;
	return *this;
}

std::ostream &					operator<<( std::ostream & o, BitcoinExchange & i )
{
	o << "The input map = " << i.getData();
	return o;
}

std::ostream& operator<<(std::ostream& os, const std::map<Date, float>& m)
{
    for (std::map<Date, float>::const_iterator it = m.begin(); it != m.end(); ++it) 
	{
        os << it->first.joinedDate << " | " << it->second << std::endl;
    }
    return os;
}

bool 			operator<(const Date& lhs, const Date& rhs)
{
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
Date	BitcoinExchange::fillMapDate(std::string &line, char delimeter)
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

void BitcoinExchange::performConversion()
{
	Date			date;
	float			value;
	std::string		line;
	std::ifstream	fsInput(this->getInputFile());
	if (fsInput.is_open() && fsInput.good())
	{
		fsInput >> std::ws;
		while (getline(fsInput, line))
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
		fsInput.close();
	}
	else
	{
		std::cerr << "Error\nUnable to open the input file" << std::endl;
		fsInput.close();
		exit(1);
	}
}

void	BitcoinExchange::fillDataMap()
{
	std::ifstream			fsData("data.csv");
	std::string				line;
	float					value;
	Date					date;
	char 					delimeter = ',';
	std::pair <Date, float> pair;
	if (fsData.is_open() && fsData.good())
	{
		while (getline(fsData, line))
		{
			if (line.empty())
				continue;
			try
			{
				if (line.find('-') == std::string::npos)
					continue;
				date = this->fillMapDate(line, delimeter);
				value = this->fillMapValue(line, delimeter);
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			pair = std::make_pair(date, value);
			this->setData(pair);
		}
		fsData.close();
	}
	else
	{
		std::cerr << "Error\nUnable to open the data file" << std::endl;
		fsData.close();
		exit(1);
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
		ifsInput.close();
		exit(1);
	}
	ifsData.open("data.csv");
	if (!ifsData.is_open())
	{
		std::cerr << "Error\nUnable to open the database file" << std::endl;
		ifsInput.close();
		ifsData.close();
		exit(1);
	}
	if (ifsInput >> std::ws && ifsInput.peek () == EOF)
	{
		std::cerr << "Error\nEmpty input file" << std::endl;
		ifsInput.close();
		ifsData.close();
		exit(1);
	}
	if (ifsData >> std::ws && ifsData.peek () == EOF)
	{
		std::cerr << "Error\nEmpty database file" << std::endl;
		ifsInput.close();
		ifsData.close();
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


std::map<Date, float> & BitcoinExchange::getData() 
{
	return this->_data;
}

std::string BitcoinExchange::getInputFile() const
{
	return this->_inputFile;
}

/* ************************************************************************** */