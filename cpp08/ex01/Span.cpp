#include "Span.hpp"
#include <numeric>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
}

Span::Span(const unsigned int N) : _N(N)
{
}

Span::Span( const Span & src )
{
	*this = src;
	_N = src._N;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_span = rhs._span;
		this->_N = rhs._N;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& out, Span& sp)
{
	std::vector<int>	spans = sp.getSpan();
	for(unsigned long i = 0; i < sp.getSize(); i++)
		out << sp.getSpan()[i] << " ";
	out << std::endl;
	return out;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int n)
{
	_span.push_back(n);
}

// void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
// {
	
// 	if (std::distance(begin, end) > _N)
// 		throw std::length_error("Out of range");
// 	_span.insert(_span.end(), begin, end);
// }

int Span::shortestSpan(void)
{
	std::vector<int>diffs;
	std::sort(getSpan().begin(), getSpan().end());
	std::adjacent_difference(getSpan().begin(), getSpan().end(), std::back_inserter(diffs));
	std::vector<int>::iterator min_element = std::min_element(diffs.begin() + 1, diffs.end());
	return *min_element;
}


int Span::longestSpan(void)
{
	std::vector<int>::iterator max_element = std::max_element(getSpan().begin(), getSpan().end());
	std::vector<int>::iterator min_element = std::min_element(getSpan().begin(), getSpan().end());
    return *max_element - *min_element ;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::vector<int>& Span::getSpan() 
{
	return this->_span;
}

unsigned int Span::getSize() const
{
	return this->_N;
}


/* ************************************************************************** */