/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:13:07 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 10:33:32 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "\nWrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "\nWrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &cpy) : _type(cpy.getType()) {
	std::cout << "\nWrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called\n" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &cpy) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &cpy)
		_type = cpy._type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const {
	std::cout << "The WrongAnimal goes: nothing it's just a wrong parent class." << std::endl;
}

