#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <vector>
# include <cstdlib>

class Span
{

	public:

		Span();
		Span( Span const & src );
		Span(const unsigned int);
		~Span();

		Span &		operator=( Span const & rhs );

		void		addNumber(int n);
		int			shortestSpan();
		int			longestSpan();
		template <typename Iter>
		void			addNumbers(Iter it1, Iter it2)
		{
			std::copy(it1, it2, back_inserter(_span));
		}

		std::vector<int>& getSpan();
		unsigned int 		getSize() const;

		// void addRange(int start, int finish);

	private:
		unsigned int		_N;
		std::vector<int>	_span;

};

std::ostream&	operator<<(std::ostream& out, Span& sp);


#endif /* ************************************************************ SPAN_H */