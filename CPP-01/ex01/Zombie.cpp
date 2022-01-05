/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:58:30 by kostya            #+#    #+#             */
/*   Updated: 2022/01/05 19:14:09 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

tlucanti::Zombie::Zombie(const std::string &_name) noexcept
	: name(_name) {std::cout << "created " << _name << std::endl;}

void
tlucanti::Zombie::announce() const noexcept
{
	std::cout << '<' << name << "> BraiiiiiiinnnzzzZ...\n";
}

tlucanti::Zombie::~Zombie()
{
	std::cout << "died " << name << std::endl;
}

#if __cplusplus > 199711L

tlucanti::Zombie::Zombie() = default;

#else

tlucanti::Zombie::Zombie() {}

#endif

void
tlucanti::Zombie::set_name(const std::string &_name) noexcept
{
	name = _name;
}
