#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{

	public:
		Cure();
		Cure( Cure const & src );
		Cure &		operator=( Cure const & rhs );
		~Cure();

		AMateria *clone()const;
		void use (ICharacter &target);

};

std::ostream &			operator<<( std::ostream & o, Cure const & i );

#endif