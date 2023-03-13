/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:08:19 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/13 11:45:55 by pguranda         ###   ########.fr       */
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
	Intern		someRandomIntern;
	AForm		*Form0 = NULL;
	AForm		*Form1 = NULL;
	AForm		*Form2 = NULL;
	AForm		*Form3 = NULL;
	try 
	{
		Form0 = someRandomIntern.makeForm("shrubbery creation", "Gollum");
		Form1 = someRandomIntern.makeForm("robotomy request", "Gollum");
		Form2 = someRandomIntern.makeForm("presidential pardon", "Gollum");
	}
	catch (std::exception &e)
	{
		std::cerr<< e.what() << std::endl;
		delete bureaucrat0;
		delete bureaucrat1;
		delete Form0;
		delete Form1;
		delete Form2;
		// system ("leaks intern");
		return (1) ;
	}
	std::cout << "**** Forms Signing ****" << std::endl;
	bureaucrat0->signForm(*Form0);
	bureaucrat0->signForm(*Form1);
	bureaucrat0->signForm(*Form2);
	std::cout << std::endl;
	std::cout << "**** Forms Execution ****" << std::endl;
	bureaucrat1->executeForm(*Form0);
	bureaucrat0->executeForm(*Form1);
	bureaucrat0->executeForm(*Form2);
	try 
	{
		AForm		*Form3;
		Form3 = someRandomIntern.makeForm("invalid form", "Gollum");
	}
	catch (std::exception &e)
	{
		std::cerr<< e.what() << std::endl;
	}
	delete bureaucrat0;
	delete bureaucrat1;
	delete Form0;
	delete Form1;
	delete Form2;
	delete Form3;
	// system ("leaks intern");
	return (0);
}