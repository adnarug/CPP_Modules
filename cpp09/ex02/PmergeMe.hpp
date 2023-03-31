#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <vector>
# define NUM_CHUNKS 32

class PmergeMe
{

	public:
		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();
		PmergeMe(char **argv);

		PmergeMe &		operator=( PmergeMe const & rhs );

		std::list<int>		getList() const;
		std::vector<int>	getVector() const;

		int			getK() const;


	template <typename Container>
	void merge(Container & arr, typename Container::iterator left, 
			typename Container::iterator mid, typename Container::iterator right)
	{
		int n1 = std::distance(left, mid) + 1;
		int n2 = std::distance(mid + 1, right) + 1;

		Container L;
		std::copy(left, mid + 1, std::back_inserter(L));

		Container R;
		std::copy(mid + 1, right + 1, std::back_inserter(R));

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
	void insertionSort(Container &arr, typename Container::iterator left, 
					typename Container::iterator right)
	{
		for (typename Container::iterator i = left + 1; i <= right; i++) {
			typename Container::value_type key = *i;
			typename Container::iterator j = i - 1;
			while (j >= left && *j > key) {
				*(j + 1) = *j;
				j--;
			}
			*(j + 1) = key;
		}
	}

	template <typename Container>
	void mergeInsertionSort(Container & arr1)
	{
		Container arr(arr1.size());
		std::copy(arr1.begin(), arr1.end(), arr.begin());
		int n = std::distance(arr.begin(), arr.end());
		std::cout << "n: " << n << std::endl;
		int threshold = 10; // Set the threshold for switching to Insertion Sort
		typename Container::iterator left = arr.begin();
		typename Container::iterator right = arr.end() - 1;
		merge_InsertionSort(arr, left,right, threshold);
		typename Container::iterator it = arr.begin();
		while (it != arr.end()) {
			std::cout << *it << " ";
			++it;
		}
	}

	template <typename Container>
	void merge_InsertionSort(Container & arr, typename Container::iterator left, 
							typename Container::iterator right, int threshold)
	{
		if (std::distance(left, right) >= threshold) {
			typename Container::iterator mid = left + std::distance(left, right) / 2;
			merge_InsertionSort(arr, left, mid, threshold);
			merge_InsertionSort(arr, mid + 1, right, threshold);
			merge(arr, left, mid, right);
		}
		else {
			insertionSort(arr, left, right);
		}
	}


	// template <typename T>
	// const T& operator[](std::size_t index) const
	// {
	// 	typename std::list<T>::iterator it = lst.begin();
	// 	for (std::size_t i = 0; i < index; ++i) {
	// 	if (it == lst.end()) {
	// 	throw std::out_of_range("Index out of range");
	// 	}
	// 	++it;
	// }
	// return *it;
	// }

	private:
		std::list<int>		_list;
		std::vector<int>	_vector;
		int 	_k = NUM_CHUNKS;

};

std::ostream &			operator<<( std::ostream & o, std::vector<int> const & i );
// T& operator[](std::list<T>& lst, std::size_t index) ;


#endif /* ******************************************************** PMERGEME_H */