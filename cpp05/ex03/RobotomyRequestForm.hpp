#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm(std::string const target);
		virtual ~RobotomyRequestForm();

		std::string const			getTarget() const;
		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );
		virtual void 				execute(Bureaucrat const & executor) const;
		class	NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		static const int	_sign_grade_required = 72;
		static const int	_exec_grade_required = 45;
		std::string	_target;

};


#endif /* ******************************************* RobotomyRequestForm_H */