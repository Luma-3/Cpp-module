/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:23:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/11/28 14:39:32 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Span.hpp"

#define TEST(NAME) std::cout << "Test " << NAME << std::endl;
#define EXPECT_EQ(A, B)                                          \
	if (A != B)                                                  \
	{                                                            \
		std::cout << "Error: " << A << " != " << B << std::endl; \
	}                                                            \
	else                                                         \
	{                                                            \
		std::cout << "OK" << std::endl;                          \
	}

int main()
{
	TEST("42 main")
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		EXPECT_EQ(sp.shortestSpan(), 2);
		EXPECT_EQ(sp.longestSpan(), 14);
	}

	TEST("100 num")
	{
		Span sp = Span(100);
		std::vector<int> v(100);
		for (int i = 0; i < 100; i++)
			v[i] = i;
		sp.addNumber(v.begin(), v.end());
		EXPECT_EQ(sp.shortestSpan(), 1);
		EXPECT_EQ(sp.longestSpan(), 99);
	}

	TEST("10000 num")
	{
		Span sp = Span(10000);
		std::vector<int> v(10000);
		for (int i = 0; i < 10000; i++)
			v[i] = i;
		sp.addNumber(v.begin(), v.end());
		EXPECT_EQ(sp.shortestSpan(), 1);
		EXPECT_EQ(sp.longestSpan(), 9999);
	}

	TEST("100000 num")
	{
		Span sp = Span(100000);
		std::vector<int> v(100000);
		for (int i = 0; i < 100000; i++)
			v[i] = i;
		sp.addNumber(v.begin(), v.end());
		EXPECT_EQ(sp.shortestSpan(), 1);
		EXPECT_EQ(sp.longestSpan(), 99999);
	}

	TEST("short == long")
	{
		Span sp = Span(100);
		std::vector<int> v(100);
		for (int i = 0; i < 100; i++)
			v[i] = 42;
		sp.addNumber(v.begin(), v.end());
		EXPECT_EQ(sp.shortestSpan(), 0);
		EXPECT_EQ(sp.longestSpan(), 0);
	}

	return 0;
}