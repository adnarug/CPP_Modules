#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character : public ICharacter
{

	public:

		Character();
		Character( Character const & src );
		virtual ~Character();
		Character(std::string name);

		Character &		operator=( Character const & rhs );
		std::string const & getName(void) const;


		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria	*slots[4];
		size_t		_slotsEmpty;


};


#endif