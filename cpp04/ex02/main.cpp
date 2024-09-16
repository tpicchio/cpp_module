/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:56:28 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 12:17:09 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const int n = 10;
	Animal* animals[n];
	char	answer = 's';
	int		i = 0;

	// Decommenta la riga seguente per vedere che la classe Animal non è più istanziabile
	// Animal animal;
	std::cout << "\033[H\033[J";
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	while (answer != 'n')
	{
		std::cout << "\n\n10 animals created, odd indexes are cats, even indexes are dogs." << std::endl;
		std::cout << "\nOption:\n'm' to make a sound\n'n' to exit" << std::endl;
		std::cin >> answer;
		std::cout << "\033[H\033[J";
		switch (answer)
		{
			case 'm':
				std::cout << "Index of the animal you want to make a sound: ";
				std::cin >> answer;
				i = answer - '0' - 1;
				if (i < 0 || i >= n)
					std::cout << "Invalid index" << std::endl;
				else
					animals[i]->makeSound();
				break;
			case 'n':
				break;
			default:
				std::cout << "Invalid input" << std::endl;
				break;
		}
	}

	
	std::cout << "\033[H\033[J";
	std::cout << "\n\n\tTest deep copy\n" << std::endl;
	Cat *cat = new Cat();
	std::cout << std::endl;
	cat->setIdea(0, "I'm a cat");
	cat->setIdea(1, "I'm hungry");
	cat->setIdea(2, "I'm sleepy");
	std::cout << cat->getIdea(1) << std::endl;
	std::cout << cat->getIdea(2) << std::endl;
	std::cout << cat->getIdea(0) << std::endl;
	std::cout << std::endl;
	Cat *cat2 = new Cat(*cat);
	delete cat;
	std::cout << std::endl;
	std::cout << cat2->getIdea(1) << std::endl;
	std::cout << cat2->getIdea(2) << std::endl;
	std::cout << cat2->getIdea(0) << std::endl;
	std::cout << std::endl;
	delete cat2;
	std::cout << std::endl;
	for (int i = 0; i < n; i++)
		delete animals[i];
	return 0;
}
