/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:45:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/11/21 18:48:04 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
#define SWAP_HPP

template <typename T> void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
};

template <typename T> T min(T &a, T &b)
{
	return (a < b ? a : b);
};

template <typename T> T max(T &a, T &b)
{
	return (a > b ? a : b);
};

#endif // SWAP_HPP