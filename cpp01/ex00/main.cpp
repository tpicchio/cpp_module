/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:13:05 by tpicchio          #+#    #+#             */
/*   Updated: 2024/08/27 11:39:13 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);

void randomChump(std::string name);

int main(void)
{
	Zombie *zombie = newZombie("Gianpiero");
	zombie->announce();
	delete zombie;
	randomChump("Paolino");
	zombie = newZombie("Genoveffa");
	zombie->announce();
	delete zombie;
	randomChump("Giovannino");
	return (0);
}