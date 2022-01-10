/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:06:02 by kostya            #+#    #+#             */
/*   Updated: 2022/01/09 18:26:15 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    tlucanti::DiamondTrap a("trap1");
	tlucanti::DiamondTrap b(a);
	tlucanti::DiamondTrap c("trap2");
	c = b;
	c.attack("trap1");
	a.guardGate();
	a.highFivesGuys();
	a.whoAmI();
}
