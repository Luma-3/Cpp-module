/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:00:10 by jbrousse          #+#    #+#             */
/*   Updated: 2024/11/21 19:04:02 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> class Array
{
  public:
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	~Array();

	Array &operator=(const Array &src);
	T	  &operator[](unsigned int i);

	unsigned int size() const;

	class OutOfLimitsException : public std::exception
	{
		virtual const char *what() const throw();
	};

  private:
	T			*_array;
	unsigned int _size;
};

#include "Array.tpp"

#endif // ARRAY_HPP