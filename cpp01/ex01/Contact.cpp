/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:21:27 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/08 12:32:35 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
/**========================================================================
 *                           De/Constructors
 *========================================================================**/

Contact::Contact()
{
	return ;
}

Contact::~Contact ()
{
	return ;
}

/**========================================================================
 *                           Util
 *========================================================================**/

int	str_check(std::string str, int (*check_func)(int))
{
	for (size_t i = 0; i < str.length() ; i++)
	{
		if (check_func(str.at(i)) == 0)
			return (1);
	}
	return (0);
}

/**========================================================================
 *                           Accessors
 *========================================================================**/

std::string	Contact::getContactField(size_t field_num) const
{
	return (this->ContactField[field_num]);
}

void	Contact::setContactField(size_t i, std::string field_name, int check_flag)
{
	std::string	input;
	
	while (true)
	{
		std::cout<<field_name<<std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cin.clear();
			exit(0);
		}
		if (check_flag == CHECK_ALPH)
		{
			if (str_check(input, isalpha) == 1)
				std::cout<<"Invalid input. Only alphabetic characters are allowed."<<std::endl;
			else if (input.empty() == true)
				std::cout<<"Invalid input. No empty fields allowed."<<std::endl;
			else
				break;
		}
		else if (check_flag == CHECK_NUM)
		{
			if (str_check(input, isdigit) == 1)
				std::cout<<"Invalid input. Only numeric characters are allowed."<<std::endl;
			else if (input.empty() == true)
				std::cout<<"Invalid input. No empty fields allowed."<<std::endl;
			else
				break;
		}
		else if (check_flag == CHECK_ALNUM)
		{
			if (str_check(input, isalnum) == 1)
				std::cout<<"Invalid input. Only alphanumeric characters are allowed."<<std::endl;
			else if (input.empty() == true)
				std::cout<<"Invalid input. No empty fields allowed."<<std::endl;
			else
				break;
		}
	}
	this->ContactField[i] = input;
	return ;
}
