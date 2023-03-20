#include "iter.hpp"
#include <iostream>
#include <string>


int main (void)
{
	int 		array_int[5] = {1, 2, 3, 4, 5};
	std::string	array_str[6] = {"Hello", "World", "!", "I", "am", "a string array"};
	char		array_char[6] = {'H', 'e', 'l', 'l', 'o', '!'};

	iter(array_int, 5, print);
	std::cout << "***" <<std::endl;
	iter(array_str, 6, print);
	std::cout << "***" <<std::endl;
	iter(array_char, 6, print);
	return 0;
}