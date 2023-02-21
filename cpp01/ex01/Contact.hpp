#ifndef  CONTACT_H
# define  CONTACT_H

#include <iostream>

#define CHECK_ALPH	1
#define CHECK_NUM	2
#define CHECK_ALNUM 3

#define FIRST_NAME	0
#define LAST_NAME	1
#define NICKNAME	2
#define PHONE_NUM	3
#define SECRET		4

#define	ADD			0
#define SEARCH		1
#define EXIT		2

class Contact
{
	public:
		Contact(void);
		~Contact (void);
		void		setContactField(size_t i, std::string field_name, int check_flag);
		std::string	getContactField(size_t field_num) const;

	private:
		std::string ContactField[5];
};

#endif 