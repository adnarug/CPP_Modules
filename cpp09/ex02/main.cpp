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
	const std::vector<int> &v = me.getVector();
	const std::list<int> &l = me.getList();

	std::cout << "sorted list: " << std::endl;
	me.mergeInsertionSort(v);
	// std::cout << me.getVector() << std::endl;
	// me.mergeInsertionSort(me.getVector(), 0, me.getVector().size() - 1, 10);
	// me.mergeInsertionSort(l);
	// me.insertionSort();
	return (0);
}