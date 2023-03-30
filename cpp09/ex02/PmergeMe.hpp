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
		void mergeInsertionSort(std::vector<int>& arr) ;
		void mergeInsertionSort(std::vector<int>& arr, int left, int right, int threshold) ;
		void insertionSort(std::vector<int>& arr, int left, int right);

		void merge(std::vector<int>& arr, int left, int mid, int right);
		

	private:
		std::list<int>		_list;
		std::vector<int>	_vector;
		int 	_k = NUM_CHUNKS;

};

std::ostream &			operator<<( std::ostream & o, std::vector<int> const & i );


#endif /* ******************************************************** PMERGEME_H */