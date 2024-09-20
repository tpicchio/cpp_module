/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:20:58 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/20 09:58:21 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	checkInput()
{
	if (std::cin.eof())
	{
		std::cin.clear();
		std::cout << std::endl;
		return -1;
	}
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

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Bad number of arguments." << std::endl;
		return 1;
	}
	std::string answer = av[1];
	while (answer != "exit")
	{
		std::cout << "\033[H\033[J";
		ScalarConverter::convert(answer);
		std::cout << "\nInsert another string to convert or type exit: ";
		std::cin >> answer;
		if (checkInput() == -1)
			break;
		std::cout << std::endl << std::endl;
	}
	return 0;
}
