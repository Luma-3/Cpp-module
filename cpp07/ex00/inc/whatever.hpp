/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:05:56 by jbrousse          #+#    #+#             */
/*   Updated: 2024/09/03 13:31:25 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b) {
	return (a < b ? a : b);
}

template <typename T>
T max(T a, T b) {
	return (a > b ? a : b);
}

#endif // WHATEVER_HPP
