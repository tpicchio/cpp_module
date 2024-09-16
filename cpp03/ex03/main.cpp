/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:00:49 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 10:02:02 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap clap("Clap");
	ScavTrap scav("Scav");
	FragTrap frag("Frag");
	DiamondTrap diamond("Diamond");

	diamond.whoAmI();
	diamond.attack("Clap");
	clap.takeDamage(10);
	clap.beRepaired(5);
	clap.attack("Scav");
	scav.takeDamage(10);
	scav.guardGate();
	for (int i = 0; i < 10; i++)
	{	
		clap.attack("Scav");
		scav.attack("Clap");
		diamond.attack("Scav");
		frag.attack("Clap");
	}
	std::cout << std::endl;
	return (0);
}