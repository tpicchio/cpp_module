/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:52:33 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 11:17:25 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &cpy): Animal(cpy.getType()) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &cpy) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &cpy)
		_type = cpy._type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "The dog goes: Bau bau woof woof!!" << std::endl;
}

