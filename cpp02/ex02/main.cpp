/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:03:13 by tpicchio          #+#    #+#             */
/*   Updated: 2024/08/31 10:28:08 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Test every operators and functions you implemented here

int main(void) {
	Fixed	a;
	Fixed	b;
	char	c = 's';

	while(c == 's')
	{
		std::cout << "\033[H\033[J";
		std::cout << "Insert a value for a: ";
		std::cin >> a;

		std::cout << "Insert a value for b: ";
		std::cin >> b;

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;

		std::cout << "a + b is " << a + b << std::endl;
		std::cout << "a - b is " << a - b << std::endl;
		std::cout << "a * b is " << a * b << std::endl;
		std::cout << "a / b is " << a / b << std::endl;

		std::cout << "a > b is " << (a > b) << std::endl;
		std::cout << "a < b is " << (a < b) << std::endl;
		std::cout << "a >= b is " << (a >= b) << std::endl;
		std::cout << "a <= b is " << (a <= b) << std::endl;
		std::cout << "a == b is " << (a == b) << std::endl;
		std::cout << "a != b is " << (a != b) << std::endl;

		std::cout << "a++ is " << a++ << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << "++a is " << ++a << std::endl;
		std::cout << "a is " << a << std::endl;

		std::cout << "--a is " << --a << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << "a-- is " << a-- << std::endl;
		std::cout << "a is " << a << std::endl;

		std::cout << "min(a, b) is " << Fixed::min(a, b) << std::endl;
		std::cout << "max(a, b) is " << Fixed::max(a, b) << std::endl;
		
		std::cout << "Do you want to insert new value? s/n: ";
		std::cin >> c;
	}
	return 0;
}
