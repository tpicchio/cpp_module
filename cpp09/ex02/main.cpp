/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:21:40 by tpicchio          #+#    #+#             */
/*   Updated: 2024/10/06 12:51:27 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	std::vector<int> v1;
	std::deque<int> d1;
	struct timeval start_V, end_V, start_D, end_D;
	double time_V, time_D;
	int tmp;
	char answer = 'n';

	if (ac < 3)
		return std::cout << RED << "Error: not enough numbers." << RESET << std::endl, 1;
	if (ac >= 10000)
	{
		std::cout << YELLOW << "That's a lot of numbers, this may take a while.\nDo you want to continue? [y/n]: " << RESET;
		std::cin >> answer;
		if (answer != 'y')
			return 0;
	}
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
	gettimeofday(&start_V, NULL);
	p.sortVector();
	gettimeofday(&end_V, NULL);

	gettimeofday(&start_D, NULL);
	p.sortDeque();
	gettimeofday(&end_D, NULL);

	time_V = (end_V.tv_sec - start_V.tv_sec) * 1e6 + (end_V.tv_usec - start_V.tv_usec);
	time_V /= 1e6;

	time_D = (end_D.tv_sec - start_D.tv_sec) * 1e6 + (end_D.tv_usec - start_D.tv_usec);
	time_D /= 1e6;

	p.display(v1, time_V, time_D);
	return 0;
}
