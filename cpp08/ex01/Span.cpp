#include "Span.hpp"
#include <numeric>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
}

Span::Span(const unsigned int N) : _N(N), _N_added(0)
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
	if (_N_added == _N)
		throw Span::NoSpaceException();
	_span.push_back(n);
	_N_added++;
}


int Span::shortestSpan(void)
{
	if (_N_added < 2)
		throw Span::NoSpanException();
	std::vector<int>diffs;
	std::sort(getSpan().begin(), getSpan().end());
	std::adjacent_difference(getSpan().begin(), getSpan().end(), std::back_inserter(diffs));
	std::vector<int>::iterator min_element = std::min_element(diffs.begin() + 1, diffs.end());
	return *min_element;
}

int Span::longestSpan(void)
{
	if (_N_added < 2 || _span.empty())
		throw Span::NoSpanException();
	std::vector<int>::iterator max_element = std::max_element(getSpan().begin(), getSpan().end());
	std::vector<int>::iterator min_element = std::min_element(getSpan().begin(), getSpan().end());
    return std::abs(*max_element - *min_element);
}

const char * Span::NoSpaceException::what () const throw ()
{
	return ("Excepetion: No space left in the container\n");
};

const char * Span::NoSpanException::what () const throw ()
{
	return ("Excepetion: Not enough elements in teh container\n");
};
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