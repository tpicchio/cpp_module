/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:50:12 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 12:09:24 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(Dog const &cpy);
		~Dog();

		Dog &operator=(Dog const &cpy);

		virtual void makeSound() const;
		void setIdea(int i, std::string idea);
		std::string getIdea(int i) const;
};

#endif