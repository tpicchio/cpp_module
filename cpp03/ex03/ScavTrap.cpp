/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:51:13 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 10:04:27 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("DefaultScavTrap")
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap " << _name << " is now alive!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_name = name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap " << _name << " is now alive!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	_name = copy._name;
	_hit_points = copy._hit_points;
	_energy_points = copy._energy_points;
	_attack_damage = copy._attack_damage;
	std::cout << "ScavTrap " << _name << " copy constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	_name = copy._name;
	_hit_points = copy._hit_points;
	_energy_points = copy._energy_points;
	_attack_damage = copy._attack_damage;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " is now dead!" << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	if (_hit_points < 1)
	{
		std::cout << "\nScavTrap " << _name << " is already dead and can't attack." << std::endl;
		return ;
	}
	if (_energy_points < 1)
	{
		std::cout << "\nScavTrap " << _name << " has not enough energy points to attack." << std::endl;
		return ;
	}
	_energy_points -= 5;
	std::cout << "\nScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "\nScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}

