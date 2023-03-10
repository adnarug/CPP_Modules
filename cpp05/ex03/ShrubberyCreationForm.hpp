#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm(std::string const target);
		virtual ~ShrubberyCreationForm();

		std::string const			getTarget() const;
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		virtual void 				execute(Bureaucrat const & executor) const;
		class	NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		static const int	_sign_grade_required = 145;
		static const int	_exec_grade_required = 137;
		std::string	_target;

};


#endif /* ******************************************* ShrubberyCreationForm_H */