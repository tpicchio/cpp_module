/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:03:13 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/13 12:58:00 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	checkInput()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input" << std::endl;
		return 1;
	}
	return 0;
}

int main(void) {
	Fixed	a;
	Fixed	b;
	char	c = 's';

	while(c == 's')
	{
		std::cout << "\033[H\033[J";
		std::cout << "Insert a value for a: ";
		std::cin >> a;
		if (checkInput())
			continue;

		std::cout << "Insert a value for b: ";
		std::cin >> b;
		if (checkInput())
			continue;

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
