/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:35:09 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/13 16:59:45 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap claptrap("Robottone");

	claptrap.attack("R2D2");
	claptrap.takeDamage(5);
	claptrap.beRepaired(13);
	for (int i = 0; i < 10; i++)
		claptrap.attack("R2D2");
	claptrap.takeDamage(10);
	claptrap.beRepaired(10);
	return 0;
}
