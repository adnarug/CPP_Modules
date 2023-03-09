#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat (std::string const name, int grade);
		Bureaucrat (Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &				operator=( Bureaucrat const & rhs );
		std::string const			getName (void) const;
		int							getGrade () const;
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
		void						incrementGrade();
		void						decrementGrade();
		void						signForm( AForm *form);
	private:
		std::string const			_name;
		int							_grade; //1 (is highest) to 150 (is lowest)

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */