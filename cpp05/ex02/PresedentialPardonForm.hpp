#ifndef PRESEDENTIALPARDONAForm_HPP
# define PRESEDENTIALPARDONAForm_HPP

# include <iostream>
# include <string>

class PresedentialPardonAForm
{

	public:

		PresedentialPardonAForm();
		PresedentialPardonAForm( PresedentialPardonAForm const & src );
		~PresedentialPardonAForm();

		PresedentialPardonAForm &		operator=( PresedentialPardonAForm const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, PresedentialPardonAForm const & i );

#endif /* ****************************************** PRESEDENTIALPARDONAForm_H */