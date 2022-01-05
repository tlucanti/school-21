/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:53:26 by kostya            #+#    #+#             */
/*   Updated: 2022/01/04 22:01:01 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

namespace tlucanti
{
    void randomChump(const std::string &name) noexcept
    {
        Zombie(name).announce();
    }
}

