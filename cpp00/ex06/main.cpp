/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:40:54 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/20 15:16:15 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout<<"Error\nInvalid input"<<std::endl;
		return 1;
	}
	Harl harley;
	std::string	input = argv[1];
	harley.complain(input);
	return 0;
}
