#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : AForm("ShrubberryCreationForm", false, _sign_grade_required, _exec_grade_required), _target("NoTarget")
{
}
RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", false, _sign_grade_required, _exec_grade_required), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
{
		*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
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
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand (time(0));

	int randomNum = rand() % 2;
	if (this->getSigned() == false)
	{
		std::cerr<<"Cannot execute Robotomy: ";
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getExecRequired())
	{
		std::cerr<<"Cannot execute Robotomy: ";
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::cout << "Drilling noise: Drr bzz drill drillll brin hlup hluuu" << std::endl;
		if (randomNum == 0)
			std::cout << this->getTarget() << " has been robotomized" << std::endl;
		else
			std::cout << this->getTarget() << " robotomy failed" << std::endl;
	}

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

/* ************************************************************************** */