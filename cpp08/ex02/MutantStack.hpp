#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const & src);
		~MutantStack();
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type container_type;

		iterator begin();
		iterator end();
		MutantStack &		operator=( MutantStack const & rhs );
};

# include "MutantStack.tpp"

#endif /* MUTANTSTACK_HPP */
