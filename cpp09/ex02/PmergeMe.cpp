/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:34:34 by jbrousse          #+#    #+#             */
/*   Updated: 2024/12/03 17:16:18 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>

const int PmergeMe::_group[14] = {2,   2,	6,	 10,   22,	 42,   86,
								  170, 342, 682, 1366, 2730, 5462, 10922};

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int *tab, int size) : _size(size)
{
	_tab = tab;
	for (int i = 0; i < size; i++) {
		_vec.push_back(tab[i]);
		_list.push_back(tab[i]);
	}
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	_list = src._list;
	_vec = src._vec;
	_size = src._size;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs) {
		_list = rhs._list;
		_vec = rhs._vec;
		_size = rhs._size;
	}
	return *this;
}

void PmergeMe::printResult()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _size; ++i) {
		std::cout << _tab[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for (std::list< int >::iterator it = _list.begin(); it != _list.end();
		 ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// TODO : verify printed time format
	std::cout << "Time to process a range of " << _size
			  << " elements with std::list: " << _time_list << "s" << std::endl;

	std::cout << "Time to process a range of " << _size
			  << " elements with std::vector: " << _time_vec << "s"
			  << std::endl;
}

// template < typename T >
// void createPair(T &container, )

void PmergeMe::createPair(std::vector< std::pair< int, int > > &vec_pair,
						  std::vector< int > &vec, size_t size, int &reste)
{
	for (std::vector< int >::iterator it = vec.begin(); it < vec.end();
		 it += 2) {

		if (size % 2 != 0 && it == vec.end() - 1) {
			reste = *it;
			break;
		}
		vec_pair.push_back(getMinMaxPair(*it, *(it + 1)));
	}
}

std::pair< int, int > PmergeMe::getMinMaxPair(int val1, int val2)
{
	std::pair< int, int > pair;

	if (val2 == -1) {
		pair.first = -1;
		pair.second = val1;
		return pair;
	}

	if (val1 > val2) {
		pair.first = val1;
		pair.second = val2;
	}
	else {
		pair.first = val2;
		pair.second = val1;
	}
	return pair;
}

int PmergeMe::calculateNBGroup(int limit)
{
	int some_group_size = 0;
	int n = 0;

	while (some_group_size <= limit && n < _nb_group) {
		some_group_size += _group[n];
		++n;
	}
	return n;
}

int **PmergeMe::initGroup(int									nb_group,
						  std::vector< std::pair< int, int > > &vec_pair,
						  int									reste)
{
	int **group = new int *[nb_group];

	for (int i = 0; i < nb_group; ++i) {
		group[i] = new int[_group[i]];
	}

	std::vector< std::pair< int, int > >::iterator it = vec_pair.begin();


	while (it != vec_pair.end()) {
		for (int i = 0; i < nb_group; ++i) {
			for (int j = 0; j < _group[i]; ++j) {
				group[i][j] = it->second;
				++it;
			}
		}
	}

	return group;
}

void PmergeMe::mergeSortVector()
{
	std::vector< std::pair< int, int > > vec_pair;
	int									 reste = -1;

	createPair(vec_pair, _vec, _size, reste);

	// for (size_t i = 0; i < vec_pair.size(); ++i) {
	// 	std::cout << "(" << vec_pair[i].first << ", " << vec_pair[i].second
	// 			  << ") ";
	// }
	// std::cout << "reste: " << reste;
	// std::cout << std::endl;

	// TODO resursive sort on vec S_max

	std::vector< int > S;

	for (size_t i = 0; i < vec_pair.size(); ++i) {
		S.push_back(vec_pair[i].first);
	}

	S.insert(S.begin(), vec_pair[0].second);

	// for (size_t i = 0; i < S.size(); ++i) {
	// 	std::cout << S[i] << " ";
	// }
	// std::cout << std::endl;
	int size_S_min = S.size() + (reste == -1 ? 0 : 1) - 1;

	int	  nb_group = calculateNBGroup(size_S_min);
	int **group = initGroup(nb_group, vec_pair, reste);

	for (int i = 0; i < nb_group; ++i) {
		std::cout << "Group " << i << ": ";
		for (int j = 0; j < _group[i]; ++j) {
			std::cout << "id[" << j << "]: " << group[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PmergeMe::mergeSortList()
{
	// ...
}
