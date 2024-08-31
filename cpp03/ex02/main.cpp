/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:59:11 by tpicchio          #+#    #+#             */
/*   Updated: 2024/08/31 10:59:27 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap frag("Frag");

	frag.attack("Clap");
	frag.takeDamage(10);
	frag.beRepaired(5);
	frag.highFivesGuys();
	return (0);
}
