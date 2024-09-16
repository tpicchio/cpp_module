/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:58:39 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/13 13:03:18 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	checkInput()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input" << std::endl;
		return 1;
	}
	std::cin.ignore(10000, '\n');
	return 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	Point a(0, 0);
	Point b(6, 0);
	Point c(3, 6);
	float x = 0;
	float y = 0;
	char answer = 's';

	std::cout << "\033[H\033[J";
	while (answer == 's')
	{
		std::cout << "\n\nEnter the x value of the point: ";
		std::cin >> x;
		if (checkInput())
			continue;
		std::cout << "Enter the y value of the point: ";
		std::cin >> y;
		if (checkInput())
			continue;
		Point point(x, y);
		if (bsp(a, b, c, point))
			std::cout << "\033[32mThe point " << x << "," << y << " is inside the triangle\033[0m" << std::endl;
		else
			std::cout << "\033[31mThe point " << x << "," << y << " is outside the triangle\033[0m" << std::endl;
		std::cout << "Do you want to enter another point? (s/n): ";
		std::cin >> answer;
	}
	
	return 0;
}