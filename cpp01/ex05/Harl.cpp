/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:01:04 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/20 16:04:58 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

Harl::Harl() 
{
	complain_fts[0] = &Harl::debug;
	complain_fts[1] = &Harl::info;
	complain_fts[2] = &Harl::warning;
	complain_fts[3] = &Harl::error;
	complaint_lvl[0] = "DEBUG";
	complaint_lvl[1] = "INFO";
	complaint_lvl[2] = "WARNING";
	complaint_lvl[3] = "ERROR";
	return ;
}

Harl::~Harl() {
	return ;
}

void Harl::debug( void )
{
	std::cout<<"[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"<<std::endl;
}

void Harl::info( void )
{
	std::cout<<"[INFO]\nI cannot believe adding exta bacon cost more money. You don’t put enough bacon in my burger! If you did, I would have asked for more"<<std::endl;
}

void Harl::warning( void )
{
	std::cout<<"[WARNING]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::error( void )
{
	std::cout<<"[ERROR]\nThis is unacceptable, I want to speak to the manager now."<<std::endl;
}

void Harl::complain (std::string level)
{

	for (size_t i = 0; i < 4; i++)
	{
		if (level == complaint_lvl[i])
		{
			(this->*complain_fts[i])();
			return ;
		}
	}
	std::cout<<"[RANDOM]\nSome random rant."<<std::endl;
	return ;
}