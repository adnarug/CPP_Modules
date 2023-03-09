#ifndef ROBOTOMYREQUESTAForm_HPP
# define ROBOTOMYREQUESTAForm_HPP

# include <iostream>
# include <string>

class RobotomyRequestAForm
{

	public:

		RobotomyRequestAForm();
		RobotomyRequestAForm( RobotomyRequestAForm const & src );
		~RobotomyRequestAForm();

		RobotomyRequestAForm &		operator=( RobotomyRequestAForm const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestAForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTAForm_H */