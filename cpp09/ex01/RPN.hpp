/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:41:53 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/03 12:30:22 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <exception>
#include <climits>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

class RPN
{
	private:
		std::stack<int> _stack;
		std::string _input;

	private:
		void _parseInput();

	public:
		RPN();
		RPN(const RPN &src);
		~RPN();

		RPN &operator=(const RPN &src);

		void run(const std::string &input);

	class DivisionByZero : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class InvalidInput : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class Overflow : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif