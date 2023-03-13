/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:35:50 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/13 15:56:33 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error\nInvalid input of the literal" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}