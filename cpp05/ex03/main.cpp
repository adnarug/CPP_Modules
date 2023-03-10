/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:08:19 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/10 23:37:59 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ()
{
	Bureaucrat *bureaucrat0 = new Bureaucrat("Bureaucrat0", 2);
	Bureaucrat *bureaucrat1 = new Bureaucrat("Bureaucrat1", 137);
	AForm		*shrubbery = new ShrubberyCreationForm("home");
	AForm		*robotomy = new RobotomyRequestForm("Bender");
	AForm		*pardon = new PresidentialPardonForm("Frodo Baggins");

    Intern  someRandomIntern;
    AForm*   rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Gollum");
	
	try 
	{
		std::cout << "**** Forms Signing ****" << std::endl;
		bureaucrat0->signForm(*shrubbery);
		bureaucrat0->signForm(*robotomy);
		bureaucrat0->signForm(*pardon);
		bureaucrat0->signForm(*rrf);
		std::cout << std::endl;
		std::cout << "**** Forms Execution ****" << std::endl;
		bureaucrat1->executeForm(*shrubbery);
		bureaucrat0->executeForm(*robotomy);
		bureaucrat0->executeForm(*pardon);
		bureaucrat0->executeForm(*rrf);
	}

	catch (std::exception &e)
	{
		std::cerr<< e.what() << std::endl;
	}
	delete bureaucrat0;
	delete bureaucrat1;
	delete shrubbery;
	delete robotomy;
	delete pardon;
	
	system ("leaks bureaucrat_form");
	return (0);
}