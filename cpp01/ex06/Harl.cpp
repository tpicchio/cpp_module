/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:44:29 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/12 11:25:23 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	
	while (i < 4 && levels[i] != level)
		i++;
	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ] " << std::endl;
			this->debug();
		case 1:
			std::cout << "[ INFO ] " << std::endl;
			this->info();
		case 2:
			std::cout << "[ WARNING ] " << std::endl;
			this->warning();
		case 3:
			std::cout << "[ ERROR ] " << std::endl;
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
			break;
	}
	
}
