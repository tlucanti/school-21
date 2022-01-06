/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:51:51 by kostya            #+#    #+#             */
/*   Updated: 2022/01/05 20:58:56 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

tlucanti::Weapon::Weapon(const std::string &_type) noexcept
    : type(_type) {}

std::string
tlucanti::Weapon::getType() const
{
    return type;
}

void
tlucanti::Weapon::setType(const std::string &_type)
{
    type = _type;
}

std::ostream &
operator <<(std::ostream &out, const tlucanti::Weapon &weapon)
{
	out << weapon.getType();
	return out;
}

