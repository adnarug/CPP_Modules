#include "BitcoinExchange.hpp"
#include <iostream>

void leaks()
{
	system("leaks btc");
}
int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error\nInvalid file input" << std::endl;
		return (1);
	}
	(void)argc;
	BitcoinExchange bitcoin(argv[1]);
	bitcoin.performConversion();
	leaks(	);
	return (0);
}