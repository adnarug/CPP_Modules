/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:08:19 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/09 15:58:38 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main ()
{
	Bureaucrat *bureaucrat0 = new Bureaucrat("Bureaucrat0", 2);
	Bureaucrat *bureaucrat1 = new Bureaucrat("Bureaucrat1", 149);
	AForm		*shrubbery = new ShrubberyCreationForm("home");
	shrubbery->beExecuted(*bureaucrat0);
	// try 
	// {
	// 	// AForm *form0 = new AForm("Form0 ", false, 1, 150);
	// 	// AForm *form1 = new AForm("Form1 ", false, 151, 1);
	// 	// bureaucrat0->incrementGrade();
	// 	// bureaucrat1->decrementGrade();
	// 	bureaucrat0->signForm(form0);
	// 	bureaucrat1->signForm(form1);
	// }
	// catch (std::exception &e)
	// {
	// 	std::cerr<< e.what() << std::endl;
	// }
	delete bureaucrat0;
	delete bureaucrat1;
	// delete form0;
	// delete form1;
	system ("leaks bureaucrat_form");
	return (0);
}