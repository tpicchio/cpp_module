/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:54:27 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/01 11:46:15 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other) {
	this->_brain = new Brain();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
	if (this == &other)
		return *this;
	Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "The cat goes: Meow meow!!" << std::endl;
}

