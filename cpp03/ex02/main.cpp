/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:59:11 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 09:50:50 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("Clap");
	ScavTrap scav("Scav");
	FragTrap frag("Frag");

	frag.attack("Clap");
	frag.takeDamage(10);
	frag.beRepaired(5);
	frag.highFivesGuys();
	for (int i = 0; i < 10; i++)
	{	
		clap.attack("Frag");
		frag.attack("Clap");
		scav.attack("Frag");
	}
	std::cout << std::endl;
	return (0);
}
