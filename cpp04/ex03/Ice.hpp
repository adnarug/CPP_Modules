#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"


class Ice: public AMateria
{
	public:
		Ice();
		Ice( Ice const & src );
		Ice &		operator=( Ice const & rhs );
		 ~Ice();

		AMateria* clone() const;
	 	void use (ICharacter &target);

};

std::ostream &			operator<<( std::ostream & o, Ice const & i );

#endif