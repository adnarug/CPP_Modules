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
	for (int i = 0; i < 4; i++) 
	{
		if (src._materia[i]) 
			this->_materia[i] = src._materia[i]->clone();
		else 
			this->_materia[i] = NULL;
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
	if (VERBOSE)
		std::cout << "MateriaSource destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=(const MateriaSource& rhs) 
{
	if (this != &rhs) 
	{
		this->~MateriaSource();
		for (int i = 0; i < 4; i++)
		{
			if (rhs._materia[i])
				this->_materia[i] = rhs._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return *this;
}
/*
** --------------------------------- METHODS ----------------------------------
*/
void MateriaSource::learnMateria(AMateria* type) 
{
	if (type != NULL) 
	{
		for (int i = 0; i < 4; i++) 
		{
			if (!this->_materia[i]) 
			{
				this->_materia[i] = type;
				this->_count++;
				return ; 
			}
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{		
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	if (VERBOSE)
		std::cerr << "No materia found" << std::endl;
	return (NULL);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */