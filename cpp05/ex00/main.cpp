/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:08:19 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/13 10:26:18 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat *bureaucrat0 = new Bureaucrat("Bureaucrat0", 2);
	Bureaucrat *bureaucrat1 = new Bureaucrat("Bureaucrat1", 149);
	try
	{
		bureaucrat0->incrementGrade();
		std::cout << *bureaucrat0 << std::endl;
		bureaucrat1->decrementGrade();
		bureaucrat1->decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr<< e.what() << std::endl;
	}
	delete bureaucrat0;
	delete bureaucrat1;
	return (0);
}