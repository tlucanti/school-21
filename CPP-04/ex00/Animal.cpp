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

tlucanti::Animal::Animal()
{
	type = "Animal";
	std::cout << "A wild " << type << " appeared\n";
}

tlucanti::Animal::~Animal()
{
	std::cout << "an " << type << " went to jungle\n";
}

std::string
tlucanti::Animal::getType() const
{
	return type;
}

void
tlucanti::Animal::makeSound() const
{
	std::cout << "<" << type << "> R\n";
}

tlucanti::Animal::Animal(const Animal &cpy)
	: type(cpy.type)
{
	std::cout << "<" << type << "> was cloned\n";
}

tlucanti::Animal &
tlucanti::Animal::operator =(const Animal &cpy)
{
	type = cpy.type;
	std::cout << "<" << type << "> was reintegrated\n";
	return *this;
}
