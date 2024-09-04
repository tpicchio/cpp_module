/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:37:29 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/01 12:04:27 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Idea number " + std::to_string(i + 1);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return this->_ideas[0];
	return this->_ideas[i];
}

void Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
		return ;
	this->_ideas[i] = idea;
}
