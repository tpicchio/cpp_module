/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:51:52 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 09:50:28 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("Clap");
	ScavTrap scav("Scav");

	scav.attack("Clap");
	clap.takeDamage(10);
	clap.beRepaired(5);
	clap.attack("Scav");
	scav.takeDamage(10);
	scav.guardGate();
	for (int i = 0; i < 10; i++)
	{	
		clap.attack("Scav");
		scav.attack("Clap");
		clap.takeDamage(10);
	}
	std::cout << std::endl;
	return (0);
}
