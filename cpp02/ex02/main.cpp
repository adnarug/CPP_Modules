#include "Fixed.hpp"

int main() {
	Fixed	a (2);
	Fixed const b(42.42f);
	// Fixed  const b( Fixed ( 5.05f ) * Fixed( 2 ) );

	if (a > b)
		std::cout << "a is bigger" << std::endl;
	else if (a < b)
		std::cout << "b is bigger" << std::endl;
	else
		std::cout << "a and b are equal" << std::endl;
	// std::cout<<a<<std::endl;
	// std::cout<<++a<<std::endl;
	// std::cout<<a<<std::endl;
	// std::cout<<a++<<std::endl;
	// std::cout<<a<<std::endl;

	// std::cout<<b<<std::endl;
	// std::cout<<Fixed::max( a, b )<<std::endl;

	return 0;
}
