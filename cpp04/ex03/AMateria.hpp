#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

# define VERBOSE 0

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria( AMateria const & src );
		AMateria (std::string const & type);
		virtual ~AMateria();

		AMateria &		operator=( AMateria const & rhs );
		std::string const & getType() const; //Returns the materia type
		void setType(std::string const & type);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};

#endif