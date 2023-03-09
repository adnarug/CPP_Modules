#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat; 
class AForm
{

	public:

		AForm();
		AForm( AForm const & src );
		AForm(std::string name, bool status, int const sign_grade, int const exec_grade);
		~AForm();

		AForm &		operator=( AForm const & rhs );
		 void 		beSigned(Bureaucrat * responsible);
		virtual void		beExecuted(Bureaucrat const & executor) const = 0;

		std::string	getName() const;
		bool		getSigned() const;
		int			getSignRequired() const;
		int 		getExecRequired() const;

		void		setSigned(bool status);
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
		int const			sign_grade_required;
		int const			exec_grade_required;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ FORM_H */