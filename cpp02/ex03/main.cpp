/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:13:58 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/24 10:44:54 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {

	if (bsp( Point(100, 100), Point(5, 5), Point(5, 0), Point(2, 2) ) == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	
}