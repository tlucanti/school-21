/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:54:35 by kostya            #+#    #+#             */
/*   Updated: 2022/01/04 22:00:55 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

namespace tlucanti
{
    __WUR
    Zombie *newZombie(const std::string &name) noexcept
    {
		return new Zombie(name);
    }
}
