/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:43:24 by kostya            #+#    #+#             */
/*   Updated: 2022/01/15 15:36:56 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

tlucanti::Character::Character(const std::string &name)
	: name(name)
{
#if __cplusplus <= 199711L
	for (unsigned short i=0; i < 4; ++i)
		inventory[i] = nullptr;
#endif
	std::cout << "  <" << name << "> character created\n";
}

tlucanti::Character::Character(const tlucanti::Character &cpy)
	: name(cpy.name)
{
	std::cout << "  <" << name << "> character copied\n";
	for (unsigned short i=0; i < 4; ++i)
	{
		if (cpy.inventory[i])
			inventory[i] = cpy.inventory[i]->clone();
	}
}

tlucanti::Character::~Character()
{
	std::cout << "  <" << name << "> defeated\n";
	for (unsigned short i=0; i < 4; ++i)
		delete inventory[i];
}

tlucanti::Character &
tlucanti::Character::operator =(const tlucanti::Character &cpy)
{
	if (this == &cpy)
		return *this;
	for (unsigned short i=0; i < 4; ++i)
	{
		delete inventory[i];
		inventory[i] = nullptr;
		if (cpy.inventory[i])
			inventory[i] = cpy.inventory[i]->clone();
	}
	return *this;
}

const std::string &
tlucanti::Character::getName() const
{
	return name;
}

void
tlucanti::Character::equip(AMateria* m)
{
	for (unsigned short i=0; i < 4; ++i)
	{
		if (inventory[i] == nullptr)
		{
			std::cout << "  spell <" << m->getType() << "> equiped at index " <<
				i << std::endl;
			inventory[i] = m;
			return ;
		}
	}
	std::cout << "  <" << name << "> cannot equip this spell, "
		"inventory is full\n";
}

void
tlucanti::Character::unequip(int idx)
{
	if ((unsigned)idx < 4 and inventory[idx])
	{
		std::cout << "  spell <" << inventory[idx]->getType() << "> unequiped "
			"from index " << idx << std::endl;
		inventory[idx] = nullptr;
	}
	else
		std::cout << "  <" << name << "> cannot unequip this spell, "
			"not in inventory\n";
}

void
tlucanti::Character::use(int idx, ICharacter& target)
{
	if ((unsigned)idx >= 4 or inventory[idx] == nullptr)
		std::cout << "  <" << name << "> cannot use this spell, "
			"not in inventory\n";
	else
		inventory[idx]->use(target);
}
