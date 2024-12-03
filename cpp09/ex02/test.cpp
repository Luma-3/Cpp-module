/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:47:37 by jbrousse          #+#    #+#             */
/*   Updated: 2024/12/03 16:57:03 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <vector>

int main()
{
	int size = 300000 / 2;

	std::vector< int > groups;
	groups.push_back(0);

	int n = 1;
	int some_group_size = 0;

	while (some_group_size <= size) {
		int group_size = pow(2, n) - groups[n - 1];
		groups.push_back(group_size);
		some_group_size += group_size;
		++n;
	}

	for (size_t i = 0; i < groups.size(); ++i) {
		std::cout << "Group " << i << ": " << groups[i] << std::endl;
	}
	std::cout << "Total: " << some_group_size << std::endl;
	std::cout << "nb of group: " << n - 1 << std::endl;

	return 0;
}