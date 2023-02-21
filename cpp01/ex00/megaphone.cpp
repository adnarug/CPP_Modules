/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:29:27 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/07 16:18:42 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

std::string uppercase(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (std::isspace(input[i]))
			continue ;
		input[i] = std::toupper(input[i]);
	
	}
	return (input);
}

int main(int argc, char **argv)
{
	int	i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < argc)
	{
		std::cout << uppercase(argv[i]);
		i++;
	}
	std::cout << std::endl;
	return 0;
}
