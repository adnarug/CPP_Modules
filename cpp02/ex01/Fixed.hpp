#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed 
{
	public:
		Fixed();
		Fixed (Fixed const & src); 
		Fixed (int const num);
		Fixed (float const num);

		~Fixed();
		Fixed& operator=(Fixed const & rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					_fixpointValue;
		static const int	_numbFracBits = 8;
};
		std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif