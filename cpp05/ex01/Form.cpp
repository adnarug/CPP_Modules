#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Default Form"), _signed(false), sign_grade_required(150), exec_grade_required(150)
{
	return ;
}

Form::Form(std::string name, bool status, int const sign_grade, int const exec_grade) : 
	_name(name), _signed(status), sign_grade_required(sign_grade), exec_grade_required(exec_grade)
{

	if (sign_grade < 1 || exec_grade < 1)
	{
		std::cerr<<"For the form " << this->getName() << " signing or execution is not possible: ";
		throw Form::GradeTooHighException();
	}
	else if (sign_grade > 150 || exec_grade > 150)
	{
		std::cerr<<"For the form " << this->getName() << " signing or execution is not possible: ";
		throw Form::GradeTooLowException();
	}

	return ;
}

Form::Form( Form const & src ) : _name(src.getName()), _signed(src.getSigned()), sign_grade_required(src.getSignRequired()), exec_grade_required(src.getExecRequired())
{
}



/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
		this->_signed = rhs._signed;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form's Name: " << i.getName() << " | Signed: " << i.getSigned() << " | Sign Grade Required: " << i.getSignRequired() << " | Exec Grade Required: " << i.getExecRequired() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char* Form::GradeTooHighException::what() const throw()
{
	return ("the grade is too high (1 is max)");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("the grade is too low (150 is min)");
}

void Form::beSigned(Bureaucrat *responsible)
{
	if (responsible->getGrade() <= this->getSignRequired())
		this->setSigned(true);
	else
		throw Form::GradeTooLowException();
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getSignRequired() const
{
	return (this->sign_grade_required);
}

int Form::getExecRequired() const
{
	return (this->exec_grade_required);
}

void Form::setSigned(bool status)
{
	this->_signed = status;
}

/* ************************************************************************** */