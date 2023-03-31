#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
}
//Error handling
PmergeMe::PmergeMe(char **argv)
{
	while (*argv)
	{
		_list.push_back(std::atoi(*argv));
		_vector.push_back(std::atoi(*argv));
		argv++;
	}


}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

//Function performs merge sort on the list

// Merge function for merging two sorted arrays


//assignement overload to print a vector with itarator
std::ostream &			operator<<( std::ostream & o, std::vector<int> const & i )
{
	for (std::vector<int>::const_iterator it = i.begin(); it != i.end(); it++)
	{
		o << *it << ' ';
	}
	return o;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::list<int> PmergeMe::getList() const
{
	return _list;
}

std::vector<int> PmergeMe::getVector() const
{
	return _vector;
}

int PmergeMe::getK() const
{
	return _k;
}
/* ************************************************************************** */