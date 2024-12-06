/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:34:34 by jbrousse          #+#    #+#             */
/*   Updated: 2024/12/06 15:23:45 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <cstring>

const int PmergeMe::_groupSizes[14] = {2,	2,	 6,	  10,	22,	  42,	86,
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

std::vector< PmergeMe::Pair * >
PmergeMe::createPair(const std::vector< PmergeMe::Pair * > &vec, size_t size,
					 int &reste)
{
	std::vector< PmergeMe::Pair * > S;

	for (std::vector< PmergeMe::Pair * >::const_iterator it = vec.begin();
		 it < vec.end(); it += 2) {

		if (size % 2 != 0 && it == vec.end() - 1) {
			reste = (*it)->max;
			break;
		}

		S.push_back(new PmergeMe::Pair((*it)->max, (*(it + 1))->max));
		PmergeMe::Pair::sortPair(*S.back());
	}

	return S;
}

int PmergeMe::calculateNBGroup(int limit)
{
	int some_group_size = 0;
	int n = 0;

	while (some_group_size < limit && n < _nb_group) {
		some_group_size += _groupSizes[n];
		++n;
	}
	return n;
}

int **PmergeMe::initGroup(int nb_group, std::vector< PmergeMe::Pair * > &S,
						  int reste)
{
	int **group = new int *[nb_group];

	for (int i = 0; i < nb_group; ++i) {
		group[i] = new int[_groupSizes[i]];
		memset(group[i], -1, _groupSizes[i] * sizeof(int));
	}

	std::vector< PmergeMe::Pair * >::iterator it = S.begin();

	int i = 0;
	int j = 0;

	while (it != S.end()) {

		if ((*it)->min == -1) {
			++it;
			continue;
		}

		if (j > _groupSizes[i] - 1) {
			++i;
			j = 0;
		}
		group[i][j] = (*it)->min;
		++j;
		++it;
	}
	if (reste != -1) {
		if (j > _groupSizes[i] - 1) {
			++i;
			j = 0;
		}
		group[i][j] = reste;
	}

	return group;
}

void PmergeMe::invertGroup(int **group, int nb_group)
{
	for (int i = 0; i < nb_group; ++i) {
		std::reverse(group[i], group[i] + _groupSizes[i]);
	}
}

void PmergeMe::dicotomicInsertion(std::vector< PmergeMe::Pair * > &vec, int val)
{
	std::vector< PmergeMe::Pair * >::iterator it =
		std::lower_bound(vec.begin(), vec.end(), val, comparePairVal);
	vec.insert(it, new PmergeMe::Pair(-1, val));
	// (*it)->min = -1;
}

std::vector< PmergeMe::Pair * >
PmergeMe::mergeSortVector(const std::vector< PmergeMe::Pair * > &input_vec)
{
	std::vector< PmergeMe::Pair * > S;
	int								reste = -1;

	S = createPair(input_vec, input_vec.size(), reste);

	if (S.size() > 1) {
		S = mergeSortVector(S); // recursive call
	}

	if (reste != -1 && S[S.size() - 1]->max < reste) {
		S.insert(S.begin(), new PmergeMe::Pair(-1, reste));
		reste = -1;
	}

	S.insert(S.begin(), new PmergeMe::Pair(-1, S[0]->min));

	int nb_group = calculateNBGroup(S.size() + (reste == -1 ? 0 : 1) - 1);

	int **group = initGroup(nb_group, S, reste);
	invertGroup(group, nb_group);

	for (int i = 0; i < nb_group; ++i) {
		for (int j = 0; j < _groupSizes[i]; ++j) {
			if (group[i][j] == -1) {
				continue;
			}
			dicotomicInsertion(S, group[i][j]);
		}
	}

	return S;
}

void PmergeMe::startSortVector()
{
	// _vec = mergeSortVector(_vec);
	std::vector< PmergeMe::Pair * > S;
	for (size_t i = 0; i < _size; ++i) {
		S.push_back(new PmergeMe::Pair(-1, _vec[i]));
	}

	S = mergeSortVector(S);

	for (size_t i = 0; i < _size; ++i) {
		_vec[i] = S[i]->max;
	}

	for (size_t i = 0; i < _size; ++i) {
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::mergeSortList()
{
	// ...
}

bool PmergeMe::comparePairVal(const PmergeMe::Pair *a, int val)
{
	return a->max < val;
}

//////////////////////
//		Utils		//
//////////////////////

PmergeMe::Pair::Pair() : max(0), min(0) {}

PmergeMe::Pair::Pair(int min, int max) : max(max), min(min) {}

void PmergeMe::Pair::sortPair(Pair &pair)
{
	if (pair.min > pair.max) {
		std::swap(pair.min, pair.max);
	}
}

PmergeMe::Pair::Pair(const Pair &src)
{
	max = src.max;
	min = src.min;
}

PmergeMe::Pair::~Pair() {}

PmergeMe::Pair &PmergeMe::Pair::operator=(const Pair &rhs)
{
	if (this != &rhs) {
		max = rhs.max;
		min = rhs.min;
	}
	return *this;
}
