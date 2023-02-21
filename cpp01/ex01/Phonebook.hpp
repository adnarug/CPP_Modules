#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define MAX_CONTACTS 3

#define LAST_ADDED 0
#define OLDEST 1
#define MAX_INDEX 2

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook		(void);
		~Phonebook		(void);
		void			add_contact(Phonebook *ph_book);
		int				search_contact(Phonebook *ph_book);
		void			print_pb(Phonebook *ph_book);
		void			show_more(Phonebook *ph_book, size_t i);
		Contact 		getContact(size_t index) const;
		void			setContact(size_t index);
		int				getIndex(size_t index_type) const;
		void			setIndex(size_t i, int value);

	private:
		Contact			contacts[MAX_CONTACTS];
		int				lastAddedContactIndex;
		int				oldestContactIndex;
		int				maxIndex;
};

int	str_check(std::string str, int (*check_func)(int));

#endif