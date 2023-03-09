#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat; 
class Form
{

	public:

		Form();
		Form( Form const & src );
		Form(std::string name, bool status, int const sign_grade, int const exec_grade);
		~Form();

		Form &		operator=( Form const & rhs );
		void 		beSigned(Bureaucrat * responsible);

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

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */