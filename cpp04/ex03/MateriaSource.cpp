#include "MateriaSource.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
		for (int i = 0; i < 4; i++)
		if (this->_materia[i])
			delete this->_materia[i];
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	this->_count= rhs._count;
	for (int i = 0; i < _count; i++)
		this->_materia[i] = rhs._materia[i]->clone();
	return *this;
}
/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = m;
			this->_count++;
			return ;
		}
	}
	std::cout << "Cannot learn any new materias" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{		
		if (_materia[i]&& _materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	std::cout << "No materia found" << std::endl;
	return (NULL);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */