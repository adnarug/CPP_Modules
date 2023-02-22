/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:51:33 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/20 16:11:38 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	return ;
}

Zombie::~Zombie() 
{
	std::cout << "zombie " << _name << " was destroyed" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout<<this->_name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
	return ;
}

void Zombie::setZombieName (std::string name)
{
	this->_name = name;
	return ; 
}
