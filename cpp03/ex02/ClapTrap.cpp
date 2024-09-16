/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:34:32 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 09:48:32 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("DefaultClapTrap"), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "\nClapTrap " << this->_name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "\nClapTrap " << this->_name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	std::cout << "\nClapTrap " << this->_name << " copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " has been destroyed.\n" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	std::cout << "\nClapTrap " << this->_name << " assignation operator called." << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hit_points < 1)
	{
		std::cout << "\nClapTrap " << this->_name << " is already dead and can't attack." << std::endl;
		return ;
	}
	if (this->_energy_points < 1)
	{
		std::cout << "\nClapTrap " << this->_name << " has not enough energy points to attack." << std::endl;
		return ;
	}
	this->_energy_points--;
	std::cout << "\nClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points < 1)
	{
		std::cout << "\nClapTrap " << this->_name << " is already dead!! Why you keep attacking??" << std::endl;
		return ;
	}
	this->_hit_points -= amount;
	if (this->_hit_points < 0)
		this->_hit_points = 0;
	std::cout << "\nClapTrap " << this->_name << " takes " << amount << " points of damage!\nHe now has " << this->_hit_points << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hit_points < 1)
	{
		std::cout << "\nClapTrap " << this->_name << " is dead and can't repair himself." << std::endl;
		return ;
	}
	this->_hit_points += amount;
	if (this->_hit_points > 10)
	{
		this->_hit_points = 10;
		std::cout << "\nClapTrap " << this->_name << " is fully repaired!\nHe now has " << this->_hit_points << " hit points." << std::endl;
	}
	else
		std::cout << "\nClapTrap " << this->_name << " is repaired by " << amount << " points!\nHe now has " << this->_hit_points << " hit points." << std::endl;
	this->_energy_points--;
}

