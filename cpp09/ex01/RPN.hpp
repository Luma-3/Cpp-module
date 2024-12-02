/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:53:30 by jbrousse          #+#    #+#             */
/*   Updated: 2024/12/02 17:19:01 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
  private:
	std::stack< int > _stack;

  public:
	RPN();
	RPN(const RPN &rpn);
	~RPN();

	RPN &operator=(const RPN &rpn);

	static bool isOperator(char c);

	void calculate(char op);
	void push(int value);

	long takeResult() const;
	void printStack() const;
};

#endif // RPN_HPP