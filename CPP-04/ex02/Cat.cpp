/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:02:58 by kostya            #+#    #+#             */
/*   Updated: 2022/01/10 21:41:03 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

tlucanti::Cat::Cat()
	: Animal()
{
	type = "Cat";
	brain = new Brain;
	std::cout << type << " just slid into room\n";
}

tlucanti::Cat::~Cat()
{
	std::cout << "the " << type << " was blown up\n";
	delete brain;
}

tlucanti::Cat::Cat(const Cat &cpy)
	: Animal()
{
	type = cpy.type;
	brain = new Brain;
	*brain = *cpy.brain;
}

void
tlucanti::Cat::makeSound() const
{
	std::cout << "<" << type << "> Mew\n";
}

std::string &
tlucanti::Cat::operator [](unsigned short at)
{
	if (at >= sizeof(brain->ideas))
	{
		std::cout << type << "'s idea is out of brain, giving first instead\n";
		return brain->ideas[0];
	}
	return brain->ideas[at];
}