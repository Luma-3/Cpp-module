/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:34:34 by jbrousse          #+#    #+#             */
/*   Updated: 2024/12/09 16:13:12 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <algorithm>
#include <cstring>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int *tab, int size) :
	_nb_group(0),
	_groupSizes(NULL),
	_size(size),
	_tab(tab),
	_time_vec(0),
	_time_list(0)
{
	for (int i = 0; i < size; i++) {
		_vec.push_back(tab[i]);
		_list.push_back(tab[i]);
	}

	calculateGroupSize();
}

PmergeMe::PmergeMe(const PmergeMe &src) :
	_nb_group(src._nb_group),
	_size(src._size),
	_tab(src._tab),
	_vec(src._vec),
	_time_vec(src._time_vec),
	_list(src._list),
	_time_list(src._time_list)
{
	calculateGroupSize();
}

PmergeMe::~PmergeMe()
{
	delete[] _groupSizes;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs) {
		calculateGroupSize();
		_size = rhs._size;
		_tab = rhs._tab;
		_vec = rhs._vec;
		_time_vec = rhs._time_vec;
		_list = rhs._list;
		_time_list = rhs._time_list;
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
			  << " elements with std::list: " << std::fixed
			  << std::setprecision(_precision) << _time_list << "s"
			  << std::endl;

	std::cout << "Time to process a range of " << _size
			  << " elements with std::vector: " << std::fixed
			  << std::setprecision(_precision) << _time_vec << "s" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////		Vector		//////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

int PmergeMe::createPairVector(const std::vector< int > &vec,
							   std::vector< int >		&S_Max,
							   std::vector< int >		&S_Min)
{
	size_t size = vec.size();
	int	   reste = -1;

	if (size % 2 != 0) {
		reste = vec[size - 1];
	}

	for (size_t i = 0; i < size - 1; i += 2) {
		if (vec[i] < vec[i + 1]) {
			S_Min.push_back(vec[i]);
			S_Max.push_back(vec[i + 1]);
		}
		else {
			S_Min.push_back(vec[i + 1]);
			S_Max.push_back(vec[i]);
		}
	}
	return reste;
}

int **PmergeMe::initGroupVector(int nb_group, std::vector< int > &S_Min,
								int reste)
{
	int **group = new int *[nb_group];

	for (int i = 0; i < nb_group; ++i) {
		group[i] = new int[_groupSizes[i]];
		memset(group[i], -1, _groupSizes[i] * sizeof(int));
	}

	std::vector< int >::iterator it = S_Min.begin();

	int i = 0;
	int j = 0;

	while (it != S_Min.end()) {

		if ((*it) == -1) {
			++it;
			continue;
		}

		if (j > _groupSizes[i] - 1) {
			++i;
			j = 0;
		}
		group[i][j] = *it;
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

std::vector< int >
PmergeMe::mergeSortVector(const std::vector< int > &input_vec)
{
	std::vector< int > S_Max;
	std::vector< int > S_Min;
	int				   reste = -1;

	reste = createPairVector(input_vec, S_Max, S_Min);

	if (S_Max.size() > 1) {
		S_Max = mergeSortVector(S_Max); // recursive call
	}

	int nb_group = calculateNBGroup(S_Min.size() + (reste == -1 ? 0 : 1));

	int **group = initGroupVector(nb_group, S_Min, reste);
	invertGroup(group, nb_group);

	for (int i = 0; i < nb_group; ++i) {
		for (int j = 0; j < _groupSizes[i]; ++j) {
			if (group[i][j] == -1) {
				continue;
			}
			S_Max.insert(
				std::lower_bound(S_Max.begin(), S_Max.end(), group[i][j]),
				group[i][j]);
		}
	}

	for (int i = 0; i < nb_group; ++i) {
		delete[] group[i];
	}
	delete[] group;

	return S_Max;
}

void PmergeMe::startSortVector()
{
	std::clock_t start = std::clock();

	_vec = mergeSortVector(_vec);
	std::clock_t end = std::clock();

	_time_vec = (double)(end - start) / CLOCKS_PER_SEC;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////	 	List		//////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

int PmergeMe::createPairList(const std::list< int > &list,
							 std::list< int > &S_Max, std::list< int > &S_Min)
{
	size_t size = list.size();
	int	   reste = -1;

	if (size % 2 != 0) {
		reste = list.back();
	}

	std::list< int >::const_iterator it = list.begin();

	while (it != list.end()) {
		if (it == list.end()) {
			break;
		}
		int a = *it;
		++it;
		if (it == list.end()) {
			break;
		}
		int b = *it;
		++it;

		if (a < b) {
			S_Min.push_back(a);
			S_Max.push_back(b);
		}
		else {
			S_Min.push_back(b);
			S_Max.push_back(a);
		}
	}
	return reste;
}

int **PmergeMe::initGroupList(int nb_group, std::list< int > &S_Min, int reste)
{
	int **group = new int *[nb_group];

	for (int i = 0; i < nb_group; ++i) {
		group[i] = new int[_groupSizes[i]];
		memset(group[i], -1, _groupSizes[i] * sizeof(int));
	}

	std::list< int >::iterator it = S_Min.begin();

	int i = 0;
	int j = 0;

	while (it != S_Min.end()) {

		if ((*it) == -1) {
			++it;
			continue;
		}

		if (j > _groupSizes[i] - 1) {
			++i;
			j = 0;
		}
		group[i][j] = *it;
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

std::list< int > PmergeMe::mergeSortList(const std::list< int > &input_list)
{
	std::list< int > S_Max;
	std::list< int > S_Min;
	int				 reste = -1;

	reste = createPairList(input_list, S_Max, S_Min);

	if (S_Max.size() > 1) {
		S_Max = mergeSortList(S_Max); // recursive call
	}

	int nb_group = calculateNBGroup(S_Min.size() + (reste == -1 ? 0 : 1));

	int **group = initGroupList(nb_group, S_Min, reste);
	invertGroup(group, nb_group);

	for (int i = 0; i < nb_group; ++i) {
		for (int j = 0; j < _groupSizes[i]; ++j) {
			if (group[i][j] == -1) {
				continue;
			}
			S_Max.insert(
				std::lower_bound(S_Max.begin(), S_Max.end(), group[i][j]),
				group[i][j]);
		}
	}

	for (int i = 0; i < nb_group; ++i) {
		delete[] group[i];
	}
	delete[] group;

	return S_Max;
}

void PmergeMe::startSortList()
{
	std::clock_t start = std::clock();

	_list = mergeSortList(_list);
	std::clock_t end = std::clock();

	_time_list = (double)(end - start) / CLOCKS_PER_SEC;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

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

void PmergeMe::invertGroup(int **group, int nb_group)
{
	for (int i = 0; i < nb_group; ++i) {
		std::reverse(group[i], group[i] + _groupSizes[i]);
	}
}

void PmergeMe::calculateGroupSize()
{
	int demi_size = _size / 2;
	int group_size = 0;

	int n = 1;
	int some_group_size = 0;

	while (some_group_size <= demi_size) {
		group_size = pow(2, n) - group_size;
		some_group_size += group_size;
		++n;
	}

	_nb_group = n - 1;
	_groupSizes = new int[_nb_group];
	for (int i = 0; i < _nb_group; ++i) {

		if (i == 0) {
			_groupSizes[i] = pow(2, i + 1);
			continue;
		}
		_groupSizes[i] = pow(2, i + 1) - _groupSizes[i - 1];
	}
}
