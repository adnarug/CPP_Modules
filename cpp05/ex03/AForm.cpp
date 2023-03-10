#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : _name("Default Form"), _signed(false), sign_grade_required(150), exec_grade_required(150)
{
	return ;
}

AForm::AForm(std::string name, bool status, int const sign_grade, int const exec_grade) : 
	_name(name), _signed(status), sign_grade_required(sign_grade), exec_grade_required(exec_grade)
{

	if (sign_grade < 1 || exec_grade < 1)
	{
		std::cerr<<"For the form " << this->getName() << " signing or execution is not possible: ";
		throw AForm::GradeTooHighException();
	}
	else if (sign_grade > 150 || exec_grade > 150)
	{
		std::cerr<<"For the form " << this->getName() << " signing or execution is not possible: ";
		throw AForm::GradeTooLowException();
	}

	return ;
}

AForm::AForm( AForm const & src ) : _name(src.getName()), _signed(src.getSigned()), sign_grade_required(src.getSignRequired()), exec_grade_required(src.getExecRequired())
{
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
		this->_signed = rhs._signed;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << "Form's Name: " << i.getName() << " | Signed: " << i.getSigned() << " | Sign Grade Required: " << i.getSignRequired() << " | Exec Grade Required: " << i.getExecRequired() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("the grade is too high (1 is max)\n");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("the grade is too low (150 is min)\n");
}

const char* AForm::NotSignedException::what() const throw()
{
	return("Form is not signed\n");
}

void AForm::beSigned(Bureaucrat const * responsible) 
{
	if (responsible->getGrade() <= this->getSignRequired())
		this->setSigned(true);
	else
	{
		throw AForm::GradeTooLowException();
	}
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getSignRequired() const
{
	return (this->sign_grade_required);
}

int AForm::getExecRequired() const
{
	return (this->exec_grade_required);
}

void AForm::setSigned(bool status)
{
	this->_signed = status;
}

/* ************************************************************************** */