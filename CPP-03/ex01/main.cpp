/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:06:02 by kostya            #+#    #+#             */
/*   Updated: 2022/01/09 13:35:35 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    tlucanti::ScavTrap a("trap1");
    a.attack("himself");
	tlucanti::ScavTrap b(a);
	a = b;
	a.guardGate();
}
