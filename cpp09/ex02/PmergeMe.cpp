#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
}
//Error handling
PmergeMe::PmergeMe(char **argv)
{
	while (*argv)
	{
		_list.push_back(std::atoi(*argv));
		_vector.push_back(std::atoi(*argv));
		argv++;
	}
	mergeInsertionSort(_vector);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

//Function performs merge sort on the list

// Merge function for merging two sorted arrays
void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) 
	{
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) 
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) 
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

// Insertion Sort function for small subarrays
void PmergeMe::insertionSort(std::vector<int>& arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// Main sorting function that calls Merge and Insertion Sort recursively
void PmergeMe::mergeInsertionSort(std::vector<int>& arr, int left, int right, int threshold)
{
	if (left < right) {
		if (right - left <= threshold) {
			insertionSort(arr, left, right);
		}
		else {
			int mid = left + (right - left) / 2;
			mergeInsertionSort(arr, left, mid, threshold);
			mergeInsertionSort(arr, mid + 1, right, threshold);
			merge(arr, left, mid, right);
		}
	}
}

// Function to call the sorting function with default threshold value
void PmergeMe::mergeInsertionSort(std::vector<int>& arr)
{
	int n = arr.size();
	int threshold = 10; // Set the threshold for switching to Insertion Sort
	mergeInsertionSort(arr, 0, n - 1, threshold);
}

//assignement overload to print a vector with itarator
std::ostream &			operator<<( std::ostream & o, std::vector<int> const & i )
{
	for (std::vector<int>::const_iterator it = i.begin(); it != i.end(); it++)
	{
		o << *it << ' ';
	}
	return o;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::list<int> PmergeMe::getList() const
{
	return _list;
}

std::vector<int> PmergeMe::getVector() const
{
	return _vector;
}

int PmergeMe::getK() const
{
	return _k;
}
/* ************************************************************************** */