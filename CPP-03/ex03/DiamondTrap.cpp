/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:26:47 by kostya            #+#    #+#             */
/*   Updated: 2022/01/09 19:03:54 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

tlucanti::DiamondTrap::DiamondTrap(const std::string &_name)
    : ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name)
{
	name = _name;
	std::cout << "    DiamondTrap <" << name << "> has come with attributes:\n";
	std::cout << "      hp <" << hp << ">, energy <" << energy << ">, damage <" <<
			  damage << ">\n";
}

tlucanti::DiamondTrap::DiamondTrap(const tlucanti::DiamondTrap &cpy)
	: ClapTrap(), ScavTrap(), FragTrap()
{
	name = cpy.name;
	ClapTrap::name = name + "_clap_name";
	hp = cpy.hp;
	energy = cpy.energy;
	damage = cpy.damage;
}

tlucanti::DiamondTrap::~DiamondTrap() {}

void
tlucanti::DiamondTrap::whoAmI() const
{
//	std::cout << "    DiamondTrap <" << name << "> The Diamond Trap, rose by"
//		"Frag <" << FragTrap::name << "> and Clap <" << ClapTrap::name << ">\n";
}
