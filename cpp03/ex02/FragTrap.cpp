/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:58:43 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 09:48:21 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("DefaultFragTrap")
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap " << _name << " is now alive!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap " << _name << " is now alive!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	_name = copy._name;
	_hit_points = copy._hit_points;
	_energy_points = copy._energy_points;
	std::cout << "FragTrap " << _name << " copy constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	_name = copy._name;
	_hit_points = copy._hit_points;
	_energy_points = copy._energy_points;
	_attack_damage = copy._attack_damage;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " is now dead!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}

