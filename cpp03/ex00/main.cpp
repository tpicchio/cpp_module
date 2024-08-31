/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:35:09 by tpicchio          #+#    #+#             */
/*   Updated: 2024/08/31 10:35:18 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap claptrap("Claptrap");

	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	return 0;
}
