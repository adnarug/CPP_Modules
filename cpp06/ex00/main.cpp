/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:04:03 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/17 14:13:12 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int argc, char *argv[])
{
	if (argc != 2)
		return (std::cout << "Error\n invalid input!" << std::endl, EXIT_FAILURE);
	std::cout << std::fixed << std::setprecision(1);
	ScalarConverter::convert(argv[1]);
	return EXIT_SUCCESS;
}
