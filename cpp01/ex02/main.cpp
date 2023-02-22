/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:42:33 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/20 15:40:12 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main ()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPtr = &str;
	std::string &refPtr = str;
	
	std::cout << std::right << "Memory address of str:      " << &str << std::endl;
	std::cout << "Memory address held by ptr: "<<strPtr << std::endl;
	std::cout << "Memory address held by ref: " <<&refPtr << std::endl;

	std::cout <<"Content of str: " << str << std::endl;
	std::cout <<"Content of ptr: " <<*strPtr << std::endl;
	std::cout <<"Content of ref: " <<refPtr << std::endl;
	return (0);
}