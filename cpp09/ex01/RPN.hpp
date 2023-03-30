#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{

	public:

		RPN();
		RPN(RPN const & src );
		RPN(std::string const & input);
		~RPN();

		RPN &				operator=( RPN const & rhs );

		void 				performExpression();

		std::string			getInput() const;
		std::stack<int>		getStack() const;

	private:
		std::string 			_input;
		std::stack<int> 		_stack;

};


#endif /* ************************************************************* RPN_H */