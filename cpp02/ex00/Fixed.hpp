#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed 
{
	public:
		Fixed();
		~Fixed();
		Fixed (Fixed const & src); 
		Fixed& 				operator=(Fixed const & rhs);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
	private:
		int					_fixpointValue;
		static const int	numbFracBits = 8;
};

#endif