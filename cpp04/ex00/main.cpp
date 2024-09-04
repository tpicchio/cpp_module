/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:56:28 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/01 11:30:38 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* anomal = new WrongAnimal();
	const WrongAnimal* catfish = new WrongCat();

	std::cout << "Type: " << animal->getType() << std::endl;
	animal->makeSound();
	std::cout << "\nType: " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << "\nType: " << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << "\nType: " << anomal->getType() << std::endl;
	anomal->makeSound();
	std::cout << "\nType: " << catfish->getType() << std::endl;
	catfish->makeSound();

	delete animal;
	delete dog;
	delete cat;
	delete anomal;
	delete catfish;
	return 0;
}