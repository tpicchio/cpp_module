/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:52:33 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 12:00:26 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &cpy): Animal(cpy.getType()) {
	if (cpy._brain)
		this->_brain = new Brain(*cpy._brain);
	else
		this->_brain = new Brain();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &cpy) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &cpy)
		this->_type = cpy._type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "The dog goes: Bau bau woof woof!!" << std::endl;
}

void Dog::setIdea(int i, std::string idea) {
	this->_brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const {
	return this->_brain->getIdea(i);
}
