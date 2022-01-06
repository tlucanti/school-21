/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:51:51 by kostya            #+#    #+#             */
/*   Updated: 2022/01/06 14:22:15 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

tlucanti::HumanB::HumanB(const std::string &_name, const Weapon &_weapon) noexcept
    : name(_name), weapon(const_cast<Weapon *>(&_weapon)) {}

tlucanti::HumanB::HumanB(const std::string &_name) noexcept
	: name(_name), weapon(nullptr) {}

void
tlucanti::HumanB::attack() const
{
    std::cout << name << " attacks with his " << (weapon ? weapon->getType() : "bare hands") << std::endl;
}

void
tlucanti::HumanB::setWeapon(const Weapon &_weapon)
{
	weapon = const_cast<Weapon *>(&_weapon);
}

