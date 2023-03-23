/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:24:36 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/23 07:48:32 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <string>
#include <exception>

#include <vector>
#include <deque>
#include <list>
#include <map>
#include <stack>
#include <queue>

int main ()
{
	try{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	std::vector<int>::iterator it = easyfind(v, 5);
	std::cout << *it << std::endl;
	
	std::deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	std::deque<int>::iterator it2 = easyfind(d, 5);
	std::cout << *it2 << std::endl;
	
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	std::list<int>::iterator it3 = easyfind(l, 1);
	std::cout << *it3 << std::endl;	
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}
	return 0;
} 