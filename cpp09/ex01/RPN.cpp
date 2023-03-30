#include "RPN.hpp"
# define VALID_INPUT "0123456789+-*/ "

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}

RPN::RPN( const RPN & src ) : _input(src._input)
{
}

RPN::RPN(std::string const & input) : _input(input)
{
	int numDigits = 0;
	int numOperators = 0;
	std::string valid_input = VALID_INPUT;
	if (_input.empty())
	{
		std::cout << "Error: Empty input" << std::endl;
		exit(1);
	}
	if (_input[0] == ' '  || !isdigit(_input[0]))
	{
		std::cout << "Error: Invalid input" << std::endl;
		exit(1);
	}
	for (size_t i = 0; i < _input.size(); i++)
	{
		if (valid_input.find(_input[i]) == std::string::npos)
		{
			std::cout << "Error: Invalid input" << std::endl;
			exit(1);}
	}
	for (size_t i = 0; i < _input.size(); i++)
	{
		if (_input[i] == ' ')
			_input.erase(i, 1);
	}
	for (size_t i = 0; i < _input.size(); i++)
	{
		if (_input[i] >= '0' && _input[i] <= '9')
			numDigits++;
		else
			numOperators++;	
	}
	if (numDigits - numOperators != 1)
	{
		std::cout << "Error: Invalid input - wrong ratio of operators to values" << std::endl;
		exit(1);
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	if ( this != &rhs )
	{
		this->_input = rhs._input;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void RPN::performExpression()
{
	int num1;
	int num2;
	int result;
	for (size_t i = 0; i < _input.size(); i++)
	{
		if (_input[i] >= '0' && _input[i] <= '9')
			_stack.push(_input[i] - '0');
		else if (_input[i] == '+')
		{
			num1 = _stack.top();
			_stack.pop();
			num2 = _stack.top();
			_stack.pop();
			result = num1 + num2;
			_stack.push(result);
		}
		else if (_input[i] == '-')
		{
			num1 = _stack.top();
			_stack.pop();
			num2 = _stack.top();
			_stack.pop();
			result = num2 - num1;
			_stack.push(result);
		}
		else if (_input[i] == '*')
		{
			num1 = _stack.top();
			_stack.pop();
			num2 = _stack.top();
			_stack.pop();
			result = num1 * num2;
			_stack.push(result);
		}
		else if (_input[i] == '/')
		{
			num1 = _stack.top();
			_stack.pop();
			num2 = _stack.top();
			_stack.pop();
			if (num2 == 0)
			{
				std::cout << "Error: Division by zero" << std::endl;
				exit(1);
			}
			result = num2 / num1;
			_stack.push(result);
		}
	}
	std::cout << "Result: " << _stack.top() << std::endl;

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string RPN::getInput() const
{
	return _input;
}
/* ************************************************************************** */