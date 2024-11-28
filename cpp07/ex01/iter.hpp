/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:51:34 by jbrousse          #+#    #+#             */
/*   Updated: 2024/11/21 18:55:21 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T> void iter(T *array, int length, void (*f)(const T &))
{
	for (int i = 0; i < length; i++) {
		f(array[i]);
	}
}

// This function is used to print the value of the array
template <typename T> void print(const T &value)
{
	std::cout << value << std::endl;
}

#endif // ITER_HPP