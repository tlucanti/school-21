/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:02:58 by kostya            #+#    #+#             */
/*   Updated: 2022/01/12 18:28:29 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

tlucanti::Dog::Dog()
	: Animal()
{
	type = "Dog";
	brain = new Brain;
	std::cout << (void *)brain << std::endl;
	std::cout << "Glad you're here, " << type << std::endl;
}

tlucanti::Dog::~Dog()
{
	delete brain;
	std::cout << "the " << type << " thrown into outer space\n";
}

tlucanti::Dog::Dog(const Dog &cpy)
	: Animal()
{
	type = cpy.type;
	brain = new Brain;
	brain = cpy.brain;
}

void
tlucanti::Dog::makeSound() const
{
	std::cout << "<" << type << "> Bark\n";
}

std::string &
tlucanti::Dog::operator [](unsigned short at)
{
	if (at >= sizeof(brain->ideas))
	{
		std::cout << type << "'s idea is out of brain, giving first instead\n";
		return brain->ideas[0];
	}
	return brain->ideas[at];
}