/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:49:23 by jbrousse          #+#    #+#             */
/*   Updated: 2024/09/04 10:06:44 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstdlib>
#include <exception>

template <typename T>
class Array {
private:
	T *_arr;
	size_t _len;

public:
	Array<T>();
	Array<T>(unsigned int n);
	
	Array(const Array & src);

	
	Array &operator=(const Array & src);
	T &operator[](unsigned int n);

	unsigned int size() const;
	
	~Array();

};

#include <Array.tpp>


#endif // ARRAY_HPP