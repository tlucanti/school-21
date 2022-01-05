/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:58:30 by kostya            #+#    #+#             */
/*   Updated: 2022/01/05 20:19:23 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::srand(time(nullptr));
	tlucanti::Zombie *cemetery = tlucanti::zombieHorde(tlucanti::random(1, 20), "");

	delete [] cemetery;
	return 0;
}
