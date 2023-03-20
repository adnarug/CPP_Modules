#include "Array.hpp"
#include <iostream>
#include <string>

int main (void)
{
	Array<int> a(5);
	Array<std::string> b(5);
	a[0] = 1;
	a[1] = 2;
	b[0] = "Hello";
	b[1] = "World";
	b[2] = "!";
	std::cout << a[0] << std::endl;
	std::cout << a[1] << std::endl;
	std::cout << b[0] << std::endl;
	return 0;

}