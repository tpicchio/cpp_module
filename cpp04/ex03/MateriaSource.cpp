/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:18:22 by tpicchio          #+#    #+#             */
/*   Updated: 2024/09/14 13:18:49 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &cpy) {
	for (int i = 0; i < 4; i++)
		_materia[i] = cpy._materia[i];
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (_materia[i])
			delete _materia[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &cpy) {
	if (this != &cpy) {
		for (int i = 0; i < 4; i++)
			_materia[i] = cpy._materia[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!_materia[i]) {
			_materia[i] = m;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (_materia[i] && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return NULL;
}
