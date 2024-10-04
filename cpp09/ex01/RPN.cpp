/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:54:06 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/03 17:01:05 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _stack(), _input()
{
}

RPN::RPN(const RPN &src) : _stack(src._stack), _input(src._input)
{
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &src)
{
	if (this == &src)
		return (*this);
	_stack = src._stack;
	_input = src._input;
	return (*this);
}

void RPN::_parseInput()
{
	std::stringstream ss(_input);
	std::string token;
	long long int res;

	while (std::getline(ss, token, ' '))
	{
		if (token.empty() || token == " ")
			continue;
		if (token.size() == 2)
			throw InvalidInput();
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
				throw InvalidInput();
			long long int a = _stack.top();
			_stack.pop();
			long long int b = _stack.top();
			_stack.pop();
			if (token == "+")
			{
				res = b + a;
				if (res > INT_MAX || res < INT_MIN)
					throw Overflow();
				_stack.push(res);
			}
			else if (token == "-")
			{
				res = b - a;
				if (res > INT_MAX || res < INT_MIN)
					throw Overflow();
				_stack.push(res);
			}
			else if (token == "*")
			{
				res = b * a;
				if (res > INT_MAX || res < INT_MIN)
					throw Overflow();
				_stack.push(res);
			}
			else if (token == "/")
			{
				if (a == 0)
					throw DivisionByZero();
				res = b / a;
				if (res > INT_MAX || res < INT_MIN)
					throw Overflow();
				_stack.push(res);
			}
		}
		else if (isdigit(token[0]))
		{
			_stack.push(token[0] - '0');
		}
		else
		{
			throw InvalidInput();
		}
	}
}

void RPN::run(const std::string &input)
{
	_input = input;
	_parseInput();
	if (_stack.size() != 1)
		throw InvalidInput();
	std::cout << GREEN "Result: " << _stack.top() << RESET << std::endl;
}

const char *RPN::DivisionByZero::what() const throw()
{
	return RED "Error: Division by zero." RESET;
}

const char *RPN::InvalidInput::what() const throw()
{
	return RED "Error: Invalid input." RESET;
}

const char *RPN::Overflow::what() const throw()
{
	return RED "Error: Overflow." RESET;
}
