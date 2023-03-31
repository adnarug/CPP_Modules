#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	*this = src;
}
//Error handling
PmergeMe::PmergeMe(char **argv)
{
	std::cout << "Before:  ";
	std::cout << argv << std::endl;
	while (*argv)
	{
		_list.push_back(std::atoi(*argv));
		_vector.push_back(std::atoi(*argv));
		argv++;
	}
}

/*
** -------------------------------- DESTRUCTOR -------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->_list = rhs._list;
		this->_vector = rhs._vector;
	}
	return *this;
}
std::ostream &			operator<<( std::ostream & o, std::vector<int>  i )
{
	for (std::vector<int>::const_iterator it = ++i.begin(); it != i.end(); it++)
	{
		o << *it << ' ';
	}
	return o;
}

std::ostream &			operator<<( std::ostream & o, std::list<int>  i )
{

	for (std::list<int>::const_iterator it = ++i.begin(); it != i.end(); it++)
	{
		o << *it << ' ';
	}
	return o;
}

std::ostream & 			operator<<( std::ostream & o, char **argv )
{
	argv++;
	while (*argv)
	{
		o << *argv << ' ';
		argv++;
	}
	return o;
}
/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::list<int> & PmergeMe::getList()
{
	return _list;
}

std::vector<int> & PmergeMe::getVector()
{
	return _vector;
}

/* ************************************************************************** */