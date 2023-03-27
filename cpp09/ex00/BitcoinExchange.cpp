#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
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
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i )
{
	//o << "Value = " << i.getValue();
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


bool operator<(const Date& lhs, const Date& rhs)
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
//filling _data and _input maps with the input from input and data files
void	BitcoinExchange::fillMaps()
{
	std::ifstream *fsInput = new std::ifstream(this->getInputFile());
	setfsInput(fsInput);
	std::string line;
	float value;
	Date date;
	std::pair <Date, float> pair;
	if (getfsInput()->is_open() && getfsInput()->good())
	{
		while (getline(*getfsInput(), line))//TODO more parsing
		{
			// std::cout << line << std::endl;
			if (!line.find('|'))
				exit (1);
			// if (!line.find(' ') || !line.find('-'))
			// 	exit (1);
			date.joinedDate = line.substr(0, line.find('|'));
			date.year = std::atol(line.substr(0, line.find(' ')).c_str());
			date.month = std::atol(line.substr(line.find(' ') + 1, line.find('-')).c_str());
			date.day = std::atol(line.substr(line.find('-') + 1).c_str());
			value = std::atof(line.substr(line.find('|') + 1).c_str());
			pair = std::make_pair (date, value);
			this->setInput(pair);
		}
	}
	delete fsInput;
}

void BitcoinExchange::checkFiles()
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

std::map<Date, float> BitcoinExchange::getData() const
{
	return this->_data;
}

std::map<Date, float> BitcoinExchange::getInput() const
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