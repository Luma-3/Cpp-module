/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:30:52 by jbrousse          #+#    #+#             */
/*   Updated: 2024/09/03 14:46:28 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstdlib>

template <typename T, typename U>
void iter(T array[], size_t len, U *function) {
	for (size_t i = 0; i < len; ++i) {
		function(array[i]);
	}
}

#endif // ITER_HPP