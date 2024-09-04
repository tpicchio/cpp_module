/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:52:33 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/01 11:25:04 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	// std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &other): Animal("Dog") {
	// std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog() {
	// std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &other) {
	// std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "The dog goes: Bau bau woof woof!!" << std::endl;
}

