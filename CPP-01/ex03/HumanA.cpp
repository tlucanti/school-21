/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:51:51 by kostya            #+#    #+#             */
/*   Updated: 2022/01/06 14:19:16 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

tlucanti::HumanA::HumanA(const std::string &_name, const Weapon &_weapon) noexcept
    : name(_name), weapon(_weapon) {}

void
tlucanti::HumanA::attack() const
{
    std::cout << name << " attacks with his " << weapon << std::endl;
}
