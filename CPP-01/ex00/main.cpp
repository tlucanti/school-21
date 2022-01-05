/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:52:46 by kostya            #+#    #+#             */
/*   Updated: 2022/01/04 22:00:48 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	srand(time(nullptr));
	tlucanti::Zombie z("zomba");
	z.announce();

	tlucanti::randomChump("another");

	tlucanti::Zombie *grave = tlucanti::newZombie("rottenman");
	grave->announce();
	delete grave;
}
