/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:17:34 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 13:27:48 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *_materia[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &cpy);
		virtual ~MateriaSource();
		MateriaSource &operator=(MateriaSource const &cpy);

		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
};

#endif
