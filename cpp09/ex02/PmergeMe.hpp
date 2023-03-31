#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <iterator>

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

	template <typename Container>
	void merge(Container& arr, typename Container::iterator left,
			typename Container::iterator mid, typename Container::iterator right)
	{
		(void)arr;
		int n1 = std::distance(left, mid) + 1;
		int n2 = std::distance(mid, right) + 1;

		Container L(n1);
		std::copy(left, std::next(mid), L.begin());

		Container R(n2);
		std::copy(mid, std::next(right), R.begin());

		typename Container::iterator i = L.begin();
		typename Container::iterator j = R.begin();
		typename Container::iterator k = left;

		while (i != L.end() && j != R.end())
		{
			if (*i <= *j) {
				*k = *i;
				i++;
			}
			else {
				*k = *j;
				j++;
			}
			k++;
		}

		while (i != L.end())
		{
			*k = *i;
			i++;
			k++;
		}

		while (j != R.end())
		{
			*k = *j;
			j++;
			k++;
		}
	}

	template <typename Container>
	void insertionSort(Container& arr, typename Container::iterator left,
					typename Container::iterator right)
	{
		(void)arr;
		for (typename Container::iterator i = std::next(left); i != std::next(right); i++) {
			typename Container::value_type key = *i;
			typename Container::iterator j = std::prev(i);
			while (j != std::prev(left) && *j > key) {
				*(std::next(j)) = *j;
				j--;
			}
			*(std::next(j)) = key;
		}
	}

	template <typename Container>
	void mergeInsertionSort(Container& arr)
	{
		int threshold = 10;
		typename Container::iterator left = arr.begin();
		typename Container::iterator right = std::prev(arr.end());
		merge_InsertionSort(arr, left, right, threshold);
		arr.erase( unique( arr.begin(), arr.end() ), arr.end());
	}

	template <typename Container>
	void merge_InsertionSort(Container& arr, typename Container::iterator left,
							typename Container::iterator right, int threshold)
	{
		if (std::distance(left, right) >= threshold) {
			typename Container::iterator mid = std::next(left, std::distance(left, right) / 2);
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