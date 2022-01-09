/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:05:56 by kostya            #+#    #+#             */
/*   Updated: 2022/01/09 15:41:57 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

tlucanti::ClapTrap::ClapTrap(const std::string &_name)
	: name(_name), hp(10), energy(10), damage(0)
{
	std::cout << "ClapTrap <" << name << "> constructored\n";
}

tlucanti::ClapTrap::ClapTrap() {}

tlucanti::ClapTrap::ClapTrap(const tlucanti::ClapTrap &cpy)
	: name(cpy.name), hp(cpy.hp), energy(cpy.energy), damage(cpy.damage)
{
	std::cout << "Clap trap <" << name << "> copied\n";
}

tlucanti::ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap <" << name << "> has been decomposed\n";
}

tlucanti::ClapTrap &
tlucanti::ClapTrap::operator =(const tlucanti::ClapTrap &cpy)
{
	name = cpy.name;
	hp = cpy.hp;
	energy = cpy.energy;
	damage = cpy.damage;
	return *this;
}

void
tlucanti::ClapTrap::attack(const std::string &target) const
{
	std::cout << "ClapTrap <" << name << "> attack <" << target << ">, causing "
		"<" << damage << "> points of damage!\n";
}

void
tlucanti::ClapTrap::takeDamage(unsigned int amount)
{
	if (amount == 0)
		return ;
	if (hp > amount)
	{
		std::cout << "ClapTrap <" << name << "> bruh, I caught an masline of" <<
			" <" << amount << ">\n";
		hp -= amount;
		std::cout << "    now I'm on " << hp << " from death\n";
	}
	else
	{
		std::cout << "ClapTrap <" << name << "> ✝✝✝ RIP ✝✝✝\n";
		hp = 0;
	}
}


void
tlucanti::ClapTrap::beRepaired(unsigned int amount)
{
	if (amount == 0)
		return ;
	if (hp + amount < hp)
	{
		std::cout << "ClapTrap <" << name << "> I AM FULL OF HEALTH\n";
		hp = (unsigned)(-1);
	}
	else
	{
		std::cout << "ClapTrap <" << name << "> thanks God, I'm back to <" <<
			amount << ">\n";
		hp += amount;
		std::cout << "    now I'm on " << hp << " from death\n";
	}
}
