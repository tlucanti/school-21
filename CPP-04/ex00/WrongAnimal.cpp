/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:29:46 by kostya            #+#    #+#             */
/*   Updated: 2022/01/10 21:33:36 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

tlucanti::WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << type << " has came from nuclear waste\n";
}

tlucanti::WrongAnimal::~WrongAnimal()
{
	std::cout << "an " << type << " has decayed\n";
}

std::string
tlucanti::WrongAnimal::getType() const
{
	return type;
}

void
tlucanti::WrongAnimal::makeSound() const
{
	std::cout << "<" << type << "> R\n";
}

tlucanti::WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
	type = cpy.type;
	std::cout << "<" << type << "> was cloned\n";
}

tlucanti::WrongAnimal &
tlucanti::WrongAnimal::operator =(const WrongAnimal &cpy)
{
	type = cpy.type;
	std::cout << "<" << type << "> was reintegrated\n";
	return *this;
}
