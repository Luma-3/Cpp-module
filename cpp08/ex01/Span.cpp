/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:31:59 by jbrousse          #+#    #+#             */
/*   Updated: 2024/11/28 14:37:54 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

#define MAX_INT 2147483647

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const &span)
{
	_n = span._n;
	_v = span._v;
}

Span::~Span() {}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_v = rhs._v;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_v.size() >= _n)
	{
		throw std::out_of_range("Span: Span is overloaded !");
	}
	_v.push_back(n);
}

#include <iostream>

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if ((_v.size() + std::distance(begin, end)) > _n)
	{
		std::cout << (_v.size() + std::distance(begin, end)) << std::endl;
		throw std::out_of_range("Span: Span is overloaded !");
	}
	_v.insert(_v.end(), begin, end);
}

int Span::shortestSpan()
{
	std::vector<int> copy = _v;

	std::vector<int>::iterator it = copy.begin(), ite = copy.end();

	std::sort(it, ite);

	int min = MAX_INT;
	int tmp;
	for (size_t i = 1; i < copy.size(); i++)
	{
		tmp = copy[i] - copy[i - 1];
		min = (tmp < min) ? tmp : min;
	}
	return min;
}

int Span::longestSpan()
{
	std::vector<int> copy = _v;

	std::vector<int>::iterator it = copy.begin(), ite = copy.end();
	std::sort(it, ite);

	return (copy[copy.size() - 1] - copy[0]);
}