#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <vector>
# include <cstdlib>
# include <cmath>

class Span
{
	public:

		Span();
		Span(Span const & src );
		Span(const unsigned int);
		~Span();
		Span &		operator=( Span const & rhs );

		void		addNumber(int n);
		int			shortestSpan();
		int			longestSpan();
		template <typename Iter>
		void addRange(Iter it1, Iter it2)
		{
			std::copy(it1, it2, back_inserter(_span));
			_N_added = _span.size();
		}
		class NoSpaceException : public std::exception
		{
			const char * what() const throw();
		};
		class NoSpanException : public std::exception
		{
			const char *what() const throw();
		};
		std::vector<int>&	getSpan();
		unsigned int 		getSize() const;

	private:
		unsigned int		_N;
		unsigned int		_N_added;
		std::vector<int>	_span;

};

std::ostream&	operator<<(std::ostream& out, Span& sp);


#endif /* ************************************************************ SPAN_H */