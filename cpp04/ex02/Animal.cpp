/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:51:27 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 10:28:15 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "\nAnimal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "\nAnimal type constructor called" << std::endl;
}

Animal::Animal(Animal const &cpy) : _type(cpy.getType()) {
	std::cout << "\nAnimal copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called\n" << std::endl;
}

Animal &Animal::operator=(Animal const &cpy) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &cpy)
		_type = cpy._type;
	return *this;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "The Animal goes: nothing it's just a parent class." << std::endl;
}

