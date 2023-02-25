#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed 
{
	public:
		//Constructors and deconstructor
		Fixed ();
		Fixed (Fixed const & src); 
		Fixed (int const num);
		Fixed (float const num);
		~Fixed();
		//Assignment operator
		Fixed& operator=(Fixed const & rhs);
		//Comparison operators
		bool operator>(Fixed const & rhs);
		bool operator<(Fixed const & rhs);
		bool operator>=(Fixed const & rhs);
		bool operator<=(Fixed const & rhs);
		bool operator==(Fixed const & rhs);
		bool operator!=(Fixed const & rhs);
		//Arithmetic operators
		Fixed operator+(Fixed const & rhs);
		Fixed operator-(Fixed const & rhs);
		Fixed operator*(Fixed const & rhs);
		Fixed operator/(Fixed const & rhs);
		//Increment/decrement operators
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		//Min and max
		static Fixed & min (Fixed & num1, Fixed & num2);
		static Fixed & max (Fixed & num1, Fixed & num2);
		static const Fixed & min (const Fixed & num1, const Fixed & num2);
		static const Fixed & max (const Fixed & num1, const Fixed & num2);
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