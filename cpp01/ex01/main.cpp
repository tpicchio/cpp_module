/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:50:27 by tpicchio          #+#    #+#             */
/*   Updated: 2024/08/27 10:53:43 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name);

int		main(void)
{
	Zombie		*horde;
	std::string	name;
	int			n;

	std::cout << "Enter the number of zombies you want to create: ";
	std::cin >> n;
	std::cout << "Enter the name of the zombies: ";
	std::cin >> name;
	horde = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
		horde[i].announce();
	// for (int i = 0; i < n; i++)
	// 	delete &horde[i];
	delete[] horde;
	return (0);
}