/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:54:27 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 10:27:47 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &cpy) : Animal(cpy.getType()) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &cpy) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &cpy)
		_type = cpy._type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "The cat goes: Meow meow!!" << std::endl;
}

