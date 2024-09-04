/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:14:08 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/01 11:24:35 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	// std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other): WrongAnimal("WrongCat") {
	// std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat::~WrongCat() {
	// std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other) {
	// std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "The Cat goes: cip cip!!" << std::endl;
}

