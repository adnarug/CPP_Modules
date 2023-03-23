#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int rand_num() 
{
    return std::rand() % 100;
}

int main ()
{
    std::srand(std::time(NULL)); // seed the random number generator

    Span sp (5);        
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp3(5);
    std::vector<int> v2(5);
    std::generate(v2.begin(), v2.end(), rand_num);
    sp3.addNumbers(v2.begin(), v2.end());
    std::cout << sp3 << std::endl;
    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;

    return (0);
}