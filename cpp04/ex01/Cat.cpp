/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:54:27 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 11:57:11 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &cpy) : Animal(cpy.getType()) {
	if (cpy._brain)
		this->_brain = new Brain(*cpy._brain);
	else
		this->_brain = new Brain();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &cpy) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &cpy)
		this->_type = cpy._type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "The cat goes: Meow meow!!" << std::endl;
}

void Cat::setIdea(int i, std::string idea) {
	this->_brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const {
	return this->_brain->getIdea(i);
}

