#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"
class Cure : public AMateria
{

	public:

		Cure();
		Cure( Cure const & src );
		~Cure();

		Cure &		operator=( Cure const & rhs );
		AMateria *clone()const;

	private:

};

std::ostream &			operator<<( std::ostream & o, Cure const & i );

#endif /* ************************************************************ CURE_H */