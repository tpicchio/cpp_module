/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:51:52 by tpicchio          #+#    #+#             */
/*   Updated: 2024/08/31 10:52:05 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	ScavTrap scav("Scav");
	ClapTrap clap("Clap");

	scav.attack("Clap");
	clap.takeDamage(10);
	clap.beRepaired(5);
	scav.guardGate();
	return (0);
}
