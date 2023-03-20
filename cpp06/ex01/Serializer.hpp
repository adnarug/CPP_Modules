#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

struct Data
{
	std::string s1;
	int n;
	char c;
	float f;
	double d;
} ;

class Serializer
{

	public:

		Serializer();
		Serializer( Serializer const & src );
		~Serializer();

		Serializer &		operator=( Serializer const & rhs );
		uintptr_t			serialize(Data* ptr);
		Data*				deserialize(uintptr_t raw);
};


#endif /* ****************************************************** SERIALIZER_H */