/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:46:49 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/12 11:26:23 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;
	std::string level = "DEBUG";

	while (level != "EXIT")
	{
		std::cout << "Enter a level (DEBUG, INFO, WARNING, ERROR) or EXIT to quit: ";
		std::cin >> level;
		std::cout << "\033[H\033[J";
		if (level == "EXIT")
			break ;
		harl.complain(level);
	}
	return (0);
}
