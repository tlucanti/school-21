/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:10:42 by kostya            #+#    #+#             */
/*   Updated: 2022/01/15 13:46:10 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

tlucanti::Cure::Cure()
	: AMateria("Cure") {}

tlucanti::AMateria *
tlucanti::Cure::clone() const
{
	std::cout << "  Cloning Amateria of type " << type << std::endl;
	return new Cure();
}

void
tlucanti::Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
