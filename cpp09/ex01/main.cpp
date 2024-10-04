/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:45:17 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/03 12:08:19 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	RPN rpn;

	if (ac != 2)
	{
		std::cout << RED "Usage: ./RPN 'expression'" RESET << std::endl;
		return (1);
	}
	try
	{
		rpn.run(av[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
