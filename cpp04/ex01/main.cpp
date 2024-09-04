/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:56:28 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/01 11:49:42 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*In your main function, create and fill an array of Animal objects. Half of it will
be Dog objects and the other half will be Cat objects. At the end of your program
execution, loop over this array and delete every Animal. You must delete directly dogs
and cats as Animals. The appropriate destructors must be called in the expected order.
Don’t forget to check for memory leaks.
A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test that your copies
are deep copies!*/

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const int n = 10;
	Animal* animals[n];

	for (int i = 0; i < n / 2; i++)
		animals[i] = new Dog();
	for (int i = n / 2; i < n; i++)
		animals[i] = new Cat();

	//print some random ideas
	animals[0].

	for (int i = 0; i < n; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}

	return 0;
}



// int main()
// {
// 	const Animal* animal = new Animal();
// 	const Animal* dog = new Dog();
// 	const Animal* cat = new Cat();
// 	const WrongAnimal* anomal = new WrongAnimal();
// 	const WrongAnimal* catfish = new WrongCat();

// 	std::cout << "Type: " << animal->getType() << std::endl;
// 	animal->makeSound();
// 	std::cout << "\nType: " << dog->getType() << std::endl;
// 	dog->makeSound();
// 	std::cout << "\nType: " << cat->getType() << std::endl;
// 	cat->makeSound();
// 	std::cout << "\nType: " << anomal->getType() << std::endl;
// 	anomal->makeSound();
// 	std::cout << "\nType: " << catfish->getType() << std::endl;
// 	catfish->makeSound();

// 	delete animal;
// 	delete dog;
// 	delete cat;
// 	delete anomal;
// 	delete catfish;
// 	return 0;
// }