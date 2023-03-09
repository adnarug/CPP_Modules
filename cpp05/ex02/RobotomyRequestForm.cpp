#include "RobotomyRequestAForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestAForm::RobotomyRequestAForm()
{
}

RobotomyRequestAForm::RobotomyRequestAForm( const RobotomyRequestAForm & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestAForm::~RobotomyRequestAForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestAForm &				RobotomyRequestAForm::operator=( RobotomyRequestAForm const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestAForm const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */