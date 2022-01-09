/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:14:56 by kostya            #+#    #+#             */
/*   Updated: 2022/01/09 17:19:07 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

tlucanti::FragTrap::FragTrap() {}

tlucanti::FragTrap::FragTrap(const std::string &_name)
	: ClapTrap(_name)
{
	hp = 100;
	energy = 100;
	damage = 30;
	std::cout << "  FragTrap <" << name << "> has come with attributes:\n";
	std::cout << "    hp <" << hp << ">, energy <" << energy << ">, damage <" <<
		damage << ">\n";
}

tlucanti::FragTrap::FragTrap(const FragTrap &cpy)
	: ClapTrap(cpy)
{
	hp = 100;
	energy = 100;
	damage = 30;
	std::cout << "  FragTrap <" << name << "> has been cloned with attributes:\n";
	std::cout << "    hp <" << hp << ">, energy <" << energy << ">, damage <" <<
		damage << ">\n";
}

void
tlucanti::FragTrap::highFivesGuys() const
{
	std::cout << "  FragTrap <" << name << "> requesting positive high five\n";
}

tlucanti::FragTrap::~FragTrap()
{
	std::cout << "  FragTrap <" << name << "> has been obliterated\n";
}
