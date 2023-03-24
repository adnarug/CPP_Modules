#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <set>

# define SPAN_SIZE 50
# define UNIQUE 1 //if 1, goes crazy with the big span size

int rand_num() 
{
	return std::rand() % 200;
}

int main ()
{
	std::srand(std::time(NULL)); 

	//Manual fillng of the span
	try {
		Span sp (5);        
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Span: " << sp;
		std::cout<< "Shortest distance: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest distance: "<< sp.longestSpan() << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	//Random automatic filling of the span - from 1 to 199
	try 
	{
		Span sp3(SPAN_SIZE);
		if (UNIQUE)
		{
			std::set<int> unique_numbers;
			while (unique_numbers.size() < SPAN_SIZE) 
				unique_numbers.insert(rand_num());
			sp3.addRange(unique_numbers.begin(), unique_numbers.end());
		}
		else
		{
			std::vector<int> v2(SPAN_SIZE);
			std::generate(v2.begin(), v2.end(), rand_num);
			sp3.addRange(v2.begin(), v2.end());
		}
		std::cout << "Span: " << sp3;
		std::cout << "Shortest distance: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest distance: " <<sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}