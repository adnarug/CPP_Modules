/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:06:38 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/17 14:20:50 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main ()
{
	Data *data = new Data;
	data->s1 = "Hello World";
	data->n = 42;
	data->c = 'c';
	data->f = 42.42f;
	data->d = 42.42;
	
	Serializer serializer;
	uintptr_t raw = serializer.serialize(data);
	std::cout << "Serial representation:" << raw << std::endl;
	Data *data2 = serializer.deserialize(raw);
	std::cout << data2->s1 << std::endl;
	std::cout << data2->n << std::endl;
	std::cout << data2->c << std::endl;
	std::cout << data2->f << 'f' << std::endl;
	std::cout << data2->d << std::endl;
	delete data;
	return 0;
}