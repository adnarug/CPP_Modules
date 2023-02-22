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
		//Comparison operators
		bool operator>(Fixed const & rhs);
		bool operator<(Fixed const & rhs);
		bool operator>=(Fixed const & rhs);
		bool operator<=(Fixed const & rhs);
		bool operator==(Fixed const & rhs);
		bool operator!=(Fixed const & rhs);
		//Arithmetic operators
		// Fixed& operator+(Fixed const & rhs);
		// Fixed& operator-(Fixed const & rhs);
		// Fixed& operator*(Fixed const & rhs);
		// Fixed& operator/(Fixed const & rhs);
		// //Increment/decrement operators
		// Fixed& operator=(Fixed const & rhs);
		// Fixed& operator=(Fixed const & rhs);
		// Fixed& operator=(Fixed const & rhs);
		// Fixed& operator=(Fixed const & rhs);

		static Fixed & min (Fixed & num1, Fixed & num2);
		static Fixed & min (const Fixed & num1, const Fixed & num2);
		static Fixed & max (Fixed & num1, Fixed & num2);
		static Fixed & max (const Fixed & num1, const Fixed & num2);
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