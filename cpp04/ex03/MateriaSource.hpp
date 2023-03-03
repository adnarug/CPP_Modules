#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource( MateriaSource const & src );
		MateriaSource &		operator=( MateriaSource const & rhs );
		~MateriaSource();

		void 				learnMateria(AMateria* m);
		AMateria* 			createMateria(const std::string &type);
	private:
		AMateria *_materia[4];
		int _count;			

};


#endif /* *************************************************** MATERIASOURCE_H */