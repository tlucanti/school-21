/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:21:48 by kostya            #+#    #+#             */
/*   Updated: 2022/01/09 16:37:21 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

tlucanti::ScavTrap::ScavTrap() {}

tlucanti::ScavTrap::ScavTrap(const std::string &_name)
	: ClapTrap(_name)
{
	hp = 100;
	energy = 50;
	damage = 20;
	std::cout << "  ScavTrap <" << name << "> has come with attributes:\n";
	std::cout << "    hp <" << hp << ">, energy <" << energy << ">, damage <" <<
		damage << ">\n";
}

tlucanti::ScavTrap::ScavTrap(const ScavTrap &cpy)
	: ClapTrap(cpy)
{
	hp = 100;
	energy = 50;
	damage = 20;
	std::cout << "  ScavTrap <" << name << "> has been cloned with attributes:\n";
	std::cout << "    hp <" << hp << ">, energy <" << energy << ">, damage <" <<
		damage << ">\n";
}

void
tlucanti::ScavTrap::attack(const std::string &target) const
{
	std::cout << "  ScavTrap <" << name << "> attack <" << target << ">, causing "
		"<" << damage << "> points of damage!\n";
}

void
tlucanti::ScavTrap::guardGate() const
{
	std::cout << "  ScavTrap <" << name << "> have enterred in GateKeeper mode\n";
}

tlucanti::ScavTrap::~ScavTrap()
{
	std::cout << "  ScavTrap <" << name << "> has been obliterated\n";
}