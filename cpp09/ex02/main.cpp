#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#define SEC_TO_MICRS 1000000

void leaks()
{
	system("leaks btc");
}

int main (int argc, char **argv)
{
	clock_t start, end;
	double time_used_vector;
	double time_used_list;

	PmergeMe me(argv);
	std::vector<int> v = me.getVector();
	std::list<int> l = me.getList();
	start = clock();
	me.mergeInsertionSort(v);
	end = clock();
	time_used_vector = ((double) (end - start)) / CLOCKS_PER_SEC;
	start = clock();
	me.mergeInsertionSort(l);
	end = clock();
	time_used_list = ((double) (end - start)) / CLOCKS_PER_SEC;
	std::cout << "After:   " << v << std::endl;
	std::cout << "After:   " << l << std::endl;
	std::cout << "Time to process a range of " << argc - 1  << " elements using a std::vector: " << time_used_vector * SEC_TO_MICRS << " ms" << std::endl;
	std::cout << "Time to process a range of " << argc - 1<< " elements using a std::list: " << time_used_list * SEC_TO_MICRS << " ms" << std::endl;

	return (0);
}