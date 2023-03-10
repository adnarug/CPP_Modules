#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm( PresidentialPardonForm const & src );
		PresidentialPardonForm(std::string const target);
		virtual ~PresidentialPardonForm();

		std::string const			getTarget() const;
		PresidentialPardonForm &	operator=( PresidentialPardonForm const & rhs );
		virtual void 				execute(Bureaucrat const & executor) const;

		class	NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		static const int	_sign_grade_required = 25;
		static const int	_exec_grade_required = 5;
		std::string	_target;

};


#endif /* ******************************************* PresidentialPardonForm_H */