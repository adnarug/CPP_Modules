#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : AForm("ShrubberryCreationForm", false, _sign_grade_required, _exec_grade_required), _target("NoTarget")
{
}
PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", false, _sign_grade_required, _exec_grade_required), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src )
{
		*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	srand (time(0));
	if (this->getSigned() == false)
	{
		std::cerr<<"Cannot execute the Pardon: ";
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getExecRequired())
	{
		std::cerr<<"Cannot execute the Pardon: ";
		throw AForm::GradeTooLowException();
	}
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

/* ************************************************************************** */