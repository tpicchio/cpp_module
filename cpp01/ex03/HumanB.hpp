/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:20:27 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/12 09:45:31 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif