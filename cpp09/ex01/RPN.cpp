/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:07:06 by jbrousse          #+#    #+#             */
/*   Updated: 2024/12/02 17:18:49 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rpn)
{
	if (this != &rpn) {
		_stack = rpn._stack;
	}
	return *this;
}

void RPN::push(int value)
{
	_stack.push(value);
}

void RPN::calculate(char op)
{
	if (_stack.size() < 2) {
		throw std::runtime_error("invalid expression (not enough operands)");
	}

	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();

	switch (op) {
		case '+':
			_stack.push(b + a);
			break;
		case '-':
			_stack.push(b - a);
			break;
		case '*':
			_stack.push(b * a);
			break;
		case '/':
			if (a == 0) throw std::runtime_error("division by zero");
			_stack.push(b / a);
			break;
		default:
			throw std::runtime_error("invalid operator");
	}
}

long RPN::takeResult() const
{
	if (_stack.size() != 1) {
		throw std::runtime_error("invalid expression (too many operands)");
		return 0;
	}
	return _stack.top();
}

void RPN::printStack() const
{
	std::stack< int > tmp = _stack;

	while (!tmp.empty()) {
		std::cout << tmp.top() << " ";
		tmp.pop();
	}
	std::cout << std::endl;
}

bool RPN::isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}