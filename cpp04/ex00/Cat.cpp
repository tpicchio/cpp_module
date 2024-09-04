/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:54:27 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/01 11:24:56 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	// std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &other): Animal("Cat") {
	// std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat() {
	// std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other) {
	// std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "The cat goes: Meow meow!!" << std::endl;
}

