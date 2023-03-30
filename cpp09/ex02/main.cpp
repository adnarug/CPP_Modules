#include "PmergeMe.hpp"
#include <iostream>

void leaks()
{
	system("leaks btc");
}
int main (int argc, char **argv)
{
	(void)argc;
	//print all the arguments
	for (int i = 1; i < argc; i++)
		std::cout << argv[i] << ' ';
	// if (argc != 2)
	// {
	// 	std::cerr << "Error\nInvalid file input" << std::endl;
	// 	return (1);
	// }

	// leaks(	);
	PmergeMe me(argv);
	std::cout << "sorted list: " << std::endl;
	std::cout << me.getVector() << std::endl;
	// me.insertionSort();
	return (0);
}