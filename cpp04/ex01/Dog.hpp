/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:50:12 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/01 12:02:39 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Implement a Brain class. It contains an array of 100 std::string called ideas.
This way, Dog and Cat will have a private Brain* attribute.
Upon construction, Dog and Cat will create their Brain using new Brain();
Upon destruction, Dog and Cat will delete their Brain*/

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &other);
		virtual ~Dog();
		Dog &operator=(Dog const &other);
		virtual void makeSound() const;
		Brain *getBrain() const;

	private:
		Brain *_brain;
};

#endif