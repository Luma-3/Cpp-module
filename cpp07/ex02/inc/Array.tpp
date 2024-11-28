/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:58:29 by jbrousse          #+#    #+#             */
/*   Updated: 2024/09/04 10:12:44 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

template<typename T>
Array<T>::Array() : _arr(NULL), _len(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _len(n) {}

template<typename T>
Array<T>::Array(const Array & src) {
	_arr = new T[src._len];
	_len = src._len;
	for (unsigned int i = 0; i < _len; ++i)
	{
		_arr[i] = src._arr[i];
	}
}

template<typename T>
Array<T> &Array<T>::operator=(const Array & src) {
	if (this != &src) {
		delete[] _arr;
		_len = src._len;
		for (unsigned int i = 0; i < _len; ++i) {
			_arr[i] = src._arr[i];
		}
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int n) {
	if (n >= _len) {
		throw (std::exception());
	}
	return _arr[n];
}

template<typename T>
unsigned int Array<T>::size() const {
	return _len;
}

template<typename T>
Array<T>::~Array() {
	if (_arr != NULL) {
		delete[] _arr;
	}
}