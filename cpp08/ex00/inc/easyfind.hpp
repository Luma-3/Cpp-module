/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:30:04 by jbrousse          #+#    #+#             */
/*   Updated: 2024/09/04 10:55:58 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HH
# define EASYFIND_HH

#include <algorithm>
#include <exception>

// template<typename T>
// class ExceptionNotFound : public std::exception {
// 	public:
// 		virtual const char *what() const throw() {
// 			return "Element not found";
// 		}
// };	


template<typename T>
typename T::iterator easyfind(T container, int n) {
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), n);
	if (it == container.end()) {
		throw (std::exception());
	}
	return it;
}

#endif // EASYFIND_HH
