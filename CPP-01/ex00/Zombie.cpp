/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:32:37 by kostya            #+#    #+#             */
/*   Updated: 2022/01/04 22:01:05 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

tlucanti::Zombie::Zombie(const std::string &_name) noexcept
	: name(_name) {}

void
tlucanti::Zombie::announce() const noexcept
{
	std::cout << '<' << name << "> BraiiiiiiinnnzzzZ...\n";
}
