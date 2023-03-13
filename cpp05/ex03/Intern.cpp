#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char* Intern::InvalidFormException::what() const throw()
{
	return ("Error\n Invalid form name requested from Intern");
}

AForm * Intern::makeForm(std::string const &name, std::string const &target)
{
	size_t i = 0;
	std::string valid_forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for (i = 0; i < 3; i++)
	{
		if (name == valid_forms[i])
			break ;
	}
	switch (i)
	{
		case 0:
			if (name == valid_forms[i])
				return (new RobotomyRequestForm(target));
		case 1:
			if (name == valid_forms[i])
				return (new PresidentialPardonForm(target));
		case 2:
			if (name == valid_forms[i])
				return (new ShrubberyCreationForm(target));
		default:
			throw Intern::InvalidFormException();
		return (NULL);
	}
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */