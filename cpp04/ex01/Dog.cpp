/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:52:33 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/01 12:01:09 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, other._brain->getIdea(i));
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, other._brain->getIdea(i));
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "The dog goes: Bau bau woof woof!!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return this->_brain;
}
