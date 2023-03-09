/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:03:17 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/09 15:14:26 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	try 
	{
		if (_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cerr<< this->getName()<<e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error\n The grade is too high (1 is max)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error\n The grade is too low (150 is min)");
}

void Bureaucrat::incrementGrade()
{
	if (this->getGrade() - 1 < 1)
	{
		std::cerr << this->getName() << " ";
		throw Bureaucrat::GradeTooHighException();
	}
	else
		this->_grade--;
	std::cout << *this << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (this->getGrade() + 1 > 150)
	{
		std::cerr << this->getName() << " ";
		throw Bureaucrat::GradeTooLowException();
	}
	else
		this->_grade++;
	std::cout << *this << std::endl;
}

void Bureaucrat::signForm(AForm * form)
{
	try
	{
		form->beSigned(this);
		std::cout << this->getName() << " signed " << form->getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << this->getName() << " could not sign " << form->getName() << "because";
		std::cerr << e.what() << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string const Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade () const
{
	return (this->_grade);
}


/* ************************************************************************** */