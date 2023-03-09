#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberryCreationForm", false, 145, 137), _target("NoTarget")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
{
		*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
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
void ShrubberyCreationForm::beExecuted(Bureaucrat const & executor) const
{
	// if (this->getSigned() == false)
	// 	throw AAForm::NotSignedException();
	if (executor.getGrade() > this->getExecRequired())
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream ofs(this->getTarget() + "_shrubbery");

		ofs << "       _-_" << std::endl;
		ofs << "    /~~   ~~\\" << std::endl;
		ofs << " /~~         ~~\\" << std::endl;
		ofs << "{               }" << std::endl;
		ofs << " \\  _-     -_  /" << std::endl;
		ofs << "   ~  \\\\ //  ~" << std::endl;
		ofs << "_- -   | | _- _" << std::endl;
		ofs << "  _ -  | |   -_" << std::endl;
		ofs << "      // \\\\" << std::endl;
		ofs.close();
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}


/* ************************************************************************** */