/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:03:25 by jbrousse          #+#    #+#             */
/*   Updated: 2024/11/21 19:04:46 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T> Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array &src) : _array(new T[src._size]), _size(src._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template <typename T> Array<T>::~Array()
{
	delete[] _array;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &src)
{
	if (this != &src) {
		delete[] _array;
		_array = new T[src._size];
		_size = src._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = src._array[i];
	}
	return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size) throw OutOfLimitsException();
	return _array[i];
}

template <typename T> unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
const char *Array<T>::OutOfLimitsException::what() const throw()
{
	return "Error: out of limits";
}

#endif // ARRAY_TPP