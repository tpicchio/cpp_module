/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:21:40 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/04 17:59:12 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// int jacobsthal(int n)
// {
// 	if(n == 0)
// 		return 0;

// 	if (n == 1)
// 		return 1;

// 	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
// }

int main(int ac, char **av)
{
	std::vector<int> v1;
	std::deque<int> d1;
	int tmp;

	if (ac < 3)
		return std::cout << RED << "Error: not enough numbers." << RESET << std::endl, 1;
	if (ac > 5000)
		return std::cout << RED << "Error: too many numbers." << RESET << std::endl, 1;
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
			if (!isdigit(av[i][j]))
				return std::cout << RED << "Error: invalid number in the sequence." << RESET << std::endl, 1;
		tmp = atoi(av[i]);
		if (tmp < 0)
			return std::cout << RED << "Error: overflow." << RESET << std::endl, 1;
		v1.push_back(tmp);
		d1.push_back(tmp);
	}
	PmergeMe p(v1, d1);
	p.sortVector();
	// for (int i = 0; i < 10 ; i++)
	// 	std::cout << jacobsthal(i) << std::endl;
	// p.sortDeque();
	// p.display();
	return 0;
}
