#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>


/*
1. Check the name of the file passed and the numbr of args
	try open
	check if not empty
	check if at least one valid line
	check if there is a title, otherwise maybe 
2. Check the format of date | value
	pre checks:
		find the pipe and check if it is the only one
		find the dash and check taht there is more than one
		spaces around pipe - ?? irrelevant

	2.a check date - year month data
		just checking the format
		if value not found write bad input from the input
	2.b check value - in 0 - 1000
		check if it is positive or not
		if it is in the range
	Tokenize the input
3. Tokenize data based on comma
	would be cool to take the separator from the first line
4. Match the tokens
5. Mutlitply and put them into a new vector
6. Print the new vector

		*/
//To Do to overwrite lower bound
int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error\nInvalid file input" << std::endl;
		return (1);
	}
	BitcoinExchange bitcoin(argv[1]);
	// bitcoin.fillInputMap();
	bitcoin.fillDataMap();
	bitcoin.performConversion();
	// std::cout << bitcoin.getInput() << std::endl;
	//  std::cout << bitcoin.getData() << std::endl;
	// bitcoin.multiplyValues();

	
	return (0);
}