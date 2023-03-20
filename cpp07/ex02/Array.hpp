#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{

	public:

		Array(void) : _array(NULL), _size(0) {}
		 Array(unsigned int n) : _array(new T[n]), _size(n) {}
		 Array(Array const & src) : _array(new T[src._size]), _size(src._size) 
		{
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}


		~Array() { delete [] this->_array; };

		Array &		operator=( Array const & rhs )
		{
			if (this != &rhs)
			{
				delete [] this->_array;
				this->_array = new T[rhs._size];
				this->_size = rhs._size;
				for (unsigned int i = 0; i < _size; i++)
					this->_array[i] = rhs._array[i];
			}
			return *this;
		}

		T &			operator[](unsigned int i)
		{
			if (i >= _size)
				throw std::exception();
			return _array[i];
		}

	private:
		T				*_array;
		unsigned int	_size;

};

#endif /* *********************************************************** ARRAY_H */