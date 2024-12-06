/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:26:55 by jbrousse          #+#    #+#             */
/*   Updated: 2024/12/06 15:21:19 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <sstream>
#include <vector>

class PmergeMe
{
  private:
	class Pair
	{
	  public:
		int max;
		int min;

		Pair();
		Pair(int min, int max);
		Pair(const Pair &src);
		~Pair();

		static void sortPair(Pair &pair);
		Pair	   &operator=(const Pair &rhs);
	};

	typedef struct Pair_s Pair_s;

	const static int _nb_group = 14;
	const static int _groupSizes[_nb_group];
	size_t			 _size;
	int				*_tab;

	std::vector< int > _vec;
	double			   _time_vec;

	std::list< int > _list;
	double			 _time_list;

	PmergeMe();

	std::vector< Pair * > createPair(const std::vector< Pair * > &vec,
									 size_t size, int &reste);

	static int calculateNBGroup(int limit);

	int **initGroup(int nb_group, std::vector< Pair * > &S_min, int reste);

	void invertGroup(int **group, int nb_group);

	void dicotomicInsertion(std::vector< Pair * > &vec, int val);

	static bool comparePairVal(const Pair *a, int val);

  public:
	PmergeMe(int *tab, int size);
	PmergeMe(const PmergeMe &src);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &rhs);

	void printResult();

	std::vector< Pair * >
		 mergeSortVector(const std::vector< Pair	  *> &input_vec);
	void startSortVector();
	void mergeSortList();
};

template < typename T > std::string to_string(T val)
{
	std::stringstream ss;
	ss << val;
	return ss.str();
}

#endif // PMERGEME_HPP