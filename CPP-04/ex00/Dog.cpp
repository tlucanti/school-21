/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:02:58 by kostya            #+#    #+#             */
/*   Updated: 2022/01/10 21:24:23 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

tlucanti::Dog::Dog()
	: Animal()
{
	type = "Dog";
	std::cout << "Glad you you're here " << type << std::endl;
}

tlucanti::Dog::~Dog()
{
	std::cout << "the " << type << " thrown into outer space\n";
}

void
tlucanti::Dog::makeSound() const
{
	std::cout << "<" << type << "> Bark\n";
}
