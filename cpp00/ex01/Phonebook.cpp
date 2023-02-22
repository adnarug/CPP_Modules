/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:57:53 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/08 18:28:54 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
/**========================================================================
 *                           De/Constructros
 *========================================================================**/

Phonebook::Phonebook () : lastAddedContactIndex(-1), oldestContactIndex(0), maxIndex(0)
{
	return ;
}

Phonebook::~Phonebook ()
{
	return ;
}

/**========================================================================
 *                           Accessors
 *========================================================================**/

Contact Phonebook::getContact(size_t i) const
{
	return this->contacts[i];
}

void	Phonebook::setContact(size_t i)
{
	this->contacts[i].setContactField(FIRST_NAME, "First name:", CHECK_ALPH);
	this->contacts[i].setContactField(LAST_NAME, "Last name:", CHECK_ALPH);
	this->contacts[i].setContactField(NICKNAME, "Nickname:", CHECK_ALNUM);
	this->contacts[i].setContactField(PHONE_NUM, "Phone number:", CHECK_NUM);
	this->contacts[i].setContactField(SECRET, "Darkest secret:", CHECK_ALNUM);
}

int	Phonebook::getIndex(size_t i) const
{
	if (i == LAST_ADDED)
		return (this->lastAddedContactIndex);
	if (i == OLDEST)
		return (this->oldestContactIndex);
	if (i == MAX_INDEX)
		return (this->maxIndex);
	else
		return (-1);
}

void	Phonebook::setIndex(size_t i, int value)
{
	if (i == LAST_ADDED)
		this->lastAddedContactIndex = value;
	if (i == OLDEST)
		this->oldestContactIndex = value;
	if (i == MAX_INDEX)
		this->maxIndex = value;
}

/**========================================================================
 *               Core and Support Functionsfor ADD and SEARCH
 *========================================================================**/
void print_field(std::string field)
{
	if (field.length() > 10)
		std::cout<<field.substr(0, 9)<<'.'<<'|';
	else
		std::cout<<std::right<<std::setw(10)<<field<<'|';
}

void	Phonebook::print_pb(Phonebook *ph_book)
{
	std::cout<<std::right<<std::setw(10)<<"Index"<<'|'
			<<std::right<<std::setw(10)<<"First name"<<'|'
			<<std::right<<std::setw(10)<<"Last name"<<'|'
			<<std::right<<std::setw(10)<<"Nickname"<<'|'<<std::endl;
	if (ph_book->getIndex(MAX_INDEX) == 0)
		return ;
	for (int i = 0; i < this->maxIndex; i++)
	{
		std::cout<<std::right<<std::setw(10)<< i + 1<<'|';
		print_field(ph_book->contacts[i].getContactField(FIRST_NAME));
		print_field(ph_book->contacts[i].getContactField(LAST_NAME));
		print_field(ph_book->contacts[i].getContactField(NICKNAME));
		std::cout << std::endl;
	}
}

/*Updates the index of the last added until it reaches max, then resets it to the oldest, which remains the first*/
void Phonebook::add_contact(Phonebook *ph_book)
{
	ph_book->setIndex(LAST_ADDED, getIndex(LAST_ADDED) + 1);
	if (ph_book->getIndex(LAST_ADDED) > MAX_CONTACTS - 1)
		ph_book->setIndex(LAST_ADDED, getIndex(OLDEST));
	if (ph_book->getIndex(OLDEST) > MAX_CONTACTS - 1)
		ph_book->setIndex(OLDEST, 0);
	if (ph_book->getIndex(MAX_INDEX) < MAX_CONTACTS)
		ph_book->setIndex(MAX_INDEX, getIndex(MAX_INDEX) + 1);
	setContact(ph_book->getIndex(LAST_ADDED));
}

void Phonebook::show_more(Phonebook *ph_book, size_t i)
{
	std::cout<<"First name: "<<ph_book->getContact(i).getContactField(FIRST_NAME)<<std::endl;
	std::cout<<"Last name: "<<ph_book->getContact(i).getContactField(LAST_NAME)<<std::endl;
	std::cout<<"Nickname: "<<ph_book->getContact(i).getContactField(NICKNAME)<<std::endl;
	std::cout<<"Phone number: "<<ph_book->getContact(i).getContactField(PHONE_NUM)<<std::endl;
	std::cout<<"Darkest secret: "<<ph_book->getContact(i).getContactField(SECRET)<<std::endl;
}

int Phonebook::search_contact(Phonebook *ph_book)
{
	int	i = 0;
	if (ph_book->maxIndex == 0)
	{
		std::cout<<"Phonebook is empty!"<<std::endl;
		return (EXIT_FAILURE);
	}
	while (true)
	{
		print_pb(ph_book);
		std::cout<<"Enter Index value of the contact to see more:"<<std::endl;
		std::cin >> i;
		if (std::cin.eof())
		{
			std::cin.clear();
			exit(1);
		}
		else if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a valid index." << std::endl;
		}
		else if (i < 1 || i > ph_book->maxIndex)
		{	
			std::cout<<"Please enter a valid index"<<std::endl;
		}
		else
		{
			show_more(ph_book, i - 1);
			break ;
		}
	}
	return (EXIT_SUCCESS);
}

/**========================================================================
 *                            Main
 *========================================================================**/

int main()
{
	Phonebook	ph_book;
	std::string	command;
	
	while (true)
	{
		std::cout << "Please enter a command: ADD, SEARCH or EXIT: " << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cin.clear();
			return (1);
		}
		if (command == "ADD")
		{
			ph_book.add_contact(&ph_book);
			std::cout<<"The contact was succesfully added." << std::endl;
		}
		else if (command == "SEARCH")
		{
			if (ph_book.search_contact(&ph_book) == EXIT_SUCCESS)
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (command == "EXIT")
			return (0);
		else
			std::cout<<"Invalid command. Please try again (check the caps)." << std::endl;
	}
}
