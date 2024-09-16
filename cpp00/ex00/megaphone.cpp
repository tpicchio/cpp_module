/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:29:54 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/10 12:31:37 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; av[i]; i++)
		{
			for (int j = 0; av[i][j]; j++)
				std::cout << (char)std::toupper(av[i][j]);
			if (i < ac -1)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}
