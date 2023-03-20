
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
T min(const T &v1, const T &v2)
{
	if (v1 < v2)
		return v1;
	else
		return v2;
}

template <typename T>
T max(const T &v1, const T &v2)
{
	if (v1 > v2)
		return v1;
	else
		return v2;
}

template <typename T>
void swap(T &v1, T &v2)
{
	if (v1 == v2)
		return ;
	T v3;
	v3 = v1;
	
	v1 = v2;
	v2 = v3;
}
	
// }
// template <typename T>
// {
// 	public:
// 		T   &max(T &a, T &b);
// 		T   &min(T &a, T &b);
// 		void    swap(T &a, T &b);
// };

#endif