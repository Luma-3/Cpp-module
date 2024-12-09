/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:26:55 by jbrousse          #+#    #+#             */
/*   Updated: 2024/12/09 16:07:47 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

class PmergeMe
{
  private:
	const static int _precision = 5;

	int	 _nb_group;
	int *_groupSizes;

	size_t _size;
	int	  *_tab;

	std::vector< int > _vec;
	double			   _time_vec;

	std::list< int > _list;
	double			 _time_list;

	PmergeMe();

	std::vector< int > mergeSortVector(const std::vector< int > &input_vec);
	int				   createPairVector(const std::vector< int > &vec,
										std::vector< int > &S_Max, std::vector< int > &S_Min);
	int **initGroupVector(int nb_group, std::vector< int > &S_Min, int reste);

	std::list< int > mergeSortList(const std::list< int > &list);
	int	  createPairList(const std::list< int > &list, std::list< int > &S_Max,
						 std::list< int > &S_Min);
	int **initGroupList(int nb_group, std::list< int > &S_Min, int reste);

	int	 calculateNBGroup(int limit);
	void calculateGroupSize();
	void invertGroup(int **group, int nb_group);

  public:
	PmergeMe(int *tab, int size);
	PmergeMe(const PmergeMe &src);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &rhs);

	void printResult();

	void startSortVector();
	void startSortList();
};

template < typename T > std::string to_string(T val)
{
	std::stringstream ss;
	ss << val;
	return ss.str();
}

#endif // PMERGEME_HPP