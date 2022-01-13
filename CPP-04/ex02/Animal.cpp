/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:02:58 by kostya            #+#    #+#             */
/*   Updated: 2022/01/10 21:31:06 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

tlucanti::Animal::Animal() {}

tlucanti::Animal::~Animal() {}

std::string
tlucanti::Animal::getType() const
{
	return type;
}

tlucanti::Animal::Animal(const Animal &cpy)
	: type(cpy.type)
{
	std::cout << "<" << type << "> was cloned\n";
}
