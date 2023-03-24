#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>


int main()
{

	std::cout << "***** SUBJECT TEST - START ***** " << std::endl;
	std::cout << "***** MutantStack ***** " << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);


	MutantStack<int> secondStack(mstack);
	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
		std::cout<<"Check:"<<*(it - 2) <<std::endl;

	/* -------------------------------------------------------------------- */

	std::cout << std::endl;
	std::cout << "/ ***** List ***** /" << std::endl;

	std::list< int > lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Top: " << lst.back() << std::endl;

	lst.pop_back();
	std::cout << "Size: " <<lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lst_it = lst.begin();
	std::list<int>::iterator lst_ite = lst.end();
	++it;
	--it;
	while (lst_it != lst_ite)
	{
		std::cout << *lst_it << std::endl;
		++lst_it;
	}

	std::cout<<"Check:"<<*(it - 2) <<std::endl;
	std::cout << "***** SUBJECT TEST - END ***** " << std::endl << std::endl;

	std::cout << "***** MY TEST - START ***** " << std::endl;
	MutantStack<int> mstack1;

	if (mstack1.empty() == true)
		std::cout << "Stack is empty" << std::endl;
	else
		std::cout << "Stack is not empty" << std::endl;
	
	mstack1.push(1);
	std::cout<< "Size of the container: " << mstack1.size() << std::endl;
	mstack1.pop();

	if (mstack1.empty() == true)
		std::cout << "Stack is empty" << std::endl;
	else
		std::cout << "Stack is not empty" << std::endl;

	mstack1.push(42);
	mstack1.push(2);
	mstack1.push(3);
	mstack1.push(4);
	mstack1.push(5);
	mstack1.push(-42);


	MutantStack<int>::iterator it_b = mstack1.begin();
	MutantStack<int>::iterator it_e = mstack1.end();

	std::cout << "Value of the beginning iter: " << *it_b << std::endl;
	std::cout << "Value of the end iter: " << *(it_e -1)<< std::endl;

	std::cout << "***** MY TEST - END ***** " << std::endl;

	return 0;
}
