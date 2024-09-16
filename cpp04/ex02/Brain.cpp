/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:37:29 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 11:58:41 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &cpy)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = cpy._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &cpy)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &cpy)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = cpy._ideas[i];
	}
	return *this;
}

void Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
		return ;
	this->_ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return "Invalid index";
	return this->_ideas[i];
}
