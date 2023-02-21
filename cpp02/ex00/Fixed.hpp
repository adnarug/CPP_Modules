#ifndef _HPP
# define _HPP

# include <iostream>
# include <string>

class Fixed 
{
	public:
		Fixed();
		~Fixed();
		Fixed (Fixed const & src); 
		Fixed& operator=(Fixed const & rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					_fixpointValue;
		static const int	numbFracBits;
};

#endif