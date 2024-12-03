/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:26:55 by jbrousse          #+#    #+#             */
/*   Updated: 2024/12/03 17:09:47 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

class PmergeMe
{
  private:
	const static int _nb_group = 14;
	const static int _group[_nb_group];
	size_t			 _size;
	int				*_tab;

	std::vector< int > _vec;
	double			   _time_vec;

	std::list< int > _list;
	double			 _time_list;

	PmergeMe();

	static std::pair< int, int > getMinMaxPair(int val1, int val2);

	static void createPair(std::vector< std::pair< int, int > > &vec_pair,
						   std::vector< int > &vec, size_t size, int &reste);

	static int calculateNBGroup(int limit);

	int **initGroup(int									  nb_group,
					std::vector< std::pair< int, int > > &vec_pair, int reste);

  public:
	PmergeMe(int *tab, int size);
	PmergeMe(const PmergeMe &src);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &rhs);

	void printResult();

	void mergeSortVector();
	void mergeSortList();
};

template < typename T > std::string to_string(T val)
{
	std::stringstream ss;
	ss << val;
	return ss.str();
}

#endif // PMERGEME_HPP