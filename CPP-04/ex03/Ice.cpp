/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:10:42 by kostya            #+#    #+#             */
/*   Updated: 2022/01/15 13:46:14 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

tlucanti::Ice::Ice()
	: AMateria("Ice") {}

tlucanti::AMateria *
tlucanti::Ice::clone() const
{
	std::cout << "  Cloning Amateria of type " << type << std::endl;
	return new Ice();
}

void
tlucanti::Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
