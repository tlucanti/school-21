/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:24:56 by kostya            #+#    #+#             */
/*   Updated: 2022/01/15 15:38:59 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

tlucanti::MateriaSource::MateriaSource()
{
#if __cplusplus <= 199711L
	for (unsigned short i=0; i < 4; ++i)
		inventory[i] = nullptr;
#endif
}

tlucanti::MateriaSource::~MateriaSource()
{
	for (unsigned short i=0; i < 4; ++i)
		delete inventory[i];
}

void
tlucanti::MateriaSource::learnMateria(tlucanti::AMateria *materia)
{
	for (unsigned short i=0; i < 4; ++i)
	{
		if (inventory[i] == nullptr)
		{
			std::cout << "  learned materia of type <" << materia->getType() <<
				"> at index " << i << std::endl;
			inventory[i] = materia->clone();
			return ;
		}
	}
	std::cout << "  <MateraSource> cannot learm this spell, "
		"repository is full\n";
}

tlucanti::AMateria *
tlucanti::MateriaSource::createMateria(const std::string &type)
{
	for (unsigned short i=0; i < 4; ++i)
	{
		if (inventory[i] != nullptr and inventory[i]->getType() == type)
		{
			std::cout << "  found learend materia or type <" << type <<
				"> at index " << i << std::endl;
			return inventory[i]->clone();
		}
	}
	std::cout << "  <MateraSource> cannot create unknown materia of type <" <<
		type << ">\n";
	return nullptr;
}

