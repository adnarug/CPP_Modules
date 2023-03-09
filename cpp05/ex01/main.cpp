/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:08:19 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/08 14:41:12 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	Bureaucrat *bureaucrat0 = new Bureaucrat("Bureaucrat0", 2);
	Bureaucrat *bureaucrat1 = new Bureaucrat("Bureaucrat1", 149);
	try 
	{
		Form *form0 = new Form("Form0 ", false, 1, 150);
		Form *form1 = new Form("Form1 ", false, 151, 1);
		
		// bureaucrat0->incrementGrade();
		// bureaucrat1->decrementGrade();
		bureaucrat0->signForm(form0);
		bureaucrat1->signForm(form1);
	}
	catch (std::exception &e)
	{
		std::cerr<< e.what() << std::endl;
	}
	delete bureaucrat0;
	delete bureaucrat1;
	// delete form0;
	// delete form1;
	system ("leaks bureaucrat_form");
	return (0);
}