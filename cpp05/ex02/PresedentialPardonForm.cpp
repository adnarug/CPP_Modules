#include "PresedentialPardonAForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresedentialPardonAForm::PresedentialPardonAForm()
{
}

PresedentialPardonAForm::PresedentialPardonAForm( const PresedentialPardonAForm & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresedentialPardonAForm::~PresedentialPardonAForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresedentialPardonAForm &				PresedentialPardonAForm::operator=( PresedentialPardonAForm const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresedentialPardonAForm const & i )
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