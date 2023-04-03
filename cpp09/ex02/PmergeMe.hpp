#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <iterator>
# include <algorithm>

class PmergeMe
{

	public:
		PmergeMe();
		PmergeMe(PmergeMe const & src );
		~PmergeMe();
		PmergeMe(char **argv);

		PmergeMe &		operator=( PmergeMe const & rhs );

		std::list<int>&		getList();
		std::vector<int>&	getVector();

template<typename ForwardIterator>
ForwardIterator my_prev(ForwardIterator iter, typename std::iterator_traits<ForwardIterator>::difference_type n = 1)
{
	std::advance(iter, -n);
	return iter;
}


template <typename Container>
void merge(Container& arr, typename Container::iterator left,
		typename Container::iterator mid, typename Container::iterator right)
{
	(void)arr;
	int n1 = std::distance(left, mid);
	int n2 = std::distance(mid, right);
	Container L(n1);
	std::copy(left, mid, L.begin());
	Container R(n2);
	std::copy(mid, right, R.begin());
	typename Container::iterator i = L.begin();
	typename Container::iterator j = R.begin();
	typename Container::iterator k = left;
	while (i != L.end() && j != R.end())
	{
		if (*i <= *j) {
			*k = *i;
			std::advance(i, 1);
		}
		else {
			*k = *j;
			std::advance(j, 1);
		}
		std::advance(k, 1);
	}
	while (i != L.end())
	{
		*k = *i;
		std::advance(i, 1);
		std::advance(k, 1);
	}
	while (j != R.end())
	{
		*k = *j;
		std::advance(j, 1);
		std::advance(k, 1);
	}
}


	template <typename Container>
	void insertionSort(Container& arr, typename Container::iterator left,
					typename Container::iterator right)
	{
		(void)arr;
		for (typename Container::iterator i = left; i != right; std::advance(i, 1)) {
			typename Container::value_type key = *i;
			typename Container::iterator j = i;
			while (j != left && *(my_prev(j)) > key) 
			{
				*j = *(my_prev(j));
				std::advance(j, -1);
			}
			*j = key;
		}
	}

	template <typename Container>
	void mergeInsertionSort(Container& arr)
	{
		int threshold = 10;
		typename Container::iterator left = arr.begin();
		typename Container::iterator right = arr.end();
		merge_InsertionSort(arr, left, right, threshold);
		arr.erase(unique(arr.begin(), arr.end() ), arr.end());
	}

	template <typename Container>
	void merge_InsertionSort(Container& arr, typename Container::iterator left,
							typename Container::iterator right, int threshold)
	{
		if (std::distance(left, right) >= threshold) {
			typename Container::iterator mid = left;
			std::advance(mid, std::distance(left, right) / 2);

			merge_InsertionSort(arr, left, mid, threshold);
			merge_InsertionSort(arr, mid, right, threshold);
			merge(arr, left, mid, right);
		}
		else
		{
			insertionSort(arr, left, right);
		}
	}


		private:
			std::list<int>		_list;
			std::vector<int>	_vector;
	};


std::ostream &			operator<<( std::ostream & o, std::vector<int> i);
std::ostream &			operator<<( std::ostream & o, std::list<int> i);
std::ostream &			operator<<( std::ostream & o, char  **i );


#endif /* ******************************************************** PMERGEME_H */
