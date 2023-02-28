#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const &src);
		virtual ~Brain(void);
		Brain &operator=(Brain const &rhs);
		virtual std::string *getIdeas ();
		virtual void setIdeas (size_t i);
		virtual void printIdeas();
		virtual size_t getNumIdeas() const;
	
	protected:
		static size_t const	_numIdeas = 5;
		std::string 	_ideas[_numIdeas];
};

#endif