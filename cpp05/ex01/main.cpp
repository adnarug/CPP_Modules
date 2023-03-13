/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:08:19 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/13 10:49:14 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	try 
	{
		Bureaucrat bureaucrat0 ("Bureaucrat0", 2);
		Bureaucrat bureaucrat1 ("Bureaucrat1", 150);
		Form form0 ("Form0 ", false, 2, 150);
		Form form1 ("Form1 ", false, 150, 1);
		Form form3 ("Form1 ", false, 1, 150);
		bureaucrat0.signForm(&form0);
		bureaucrat0.signForm(&form0);
		bureaucrat0.decrementGrade();
		bureaucrat0.signForm(&form3);
		bureaucrat1.signForm(&form1);
	}
	catch (std::exception &e)
	{
		std::cerr<< e.what() << std::endl;
	}
	// system ("leaks bureaucrat_form");
	return (0);
}