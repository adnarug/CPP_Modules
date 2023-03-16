#include "ScalarConverter.hpp"


//TODO:isnan!
int main(int argc, char *argv[])
{
	if (argc != 2)
		return (std::cout << "Error\n invalid input!" << std::endl, EXIT_FAILURE);
	std::cout << std::fixed << std::setprecision(1);
	ScalarConverter::convert(argv[1]);

	return EXIT_SUCCESS;
}
