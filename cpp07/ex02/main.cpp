/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:04:20 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/23 09:41:06 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	try
	{
		Array<int> a(5);

		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i;
		Array<int> b(a);
		for (unsigned int i = 0; i < b.size(); i++)
			std::cout << b[i] << std::endl;


		Array<std::string> c(3);
		c[0] = "Hello";
		c[1] = "World";
		c[2] = "!";
		for (unsigned int i = 0; i < c.size(); i++)
			std::cout << c[i] << std::endl;
		std::cout << c[3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
