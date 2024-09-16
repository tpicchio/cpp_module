/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:54:00 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 12:08:50 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(Cat const &cpy);
		~Cat();

		Cat &operator=(Cat const &cpy);

		virtual void makeSound() const;
		void setIdea(int i, std::string idea);
		std::string getIdea(int i) const;
};

#endif