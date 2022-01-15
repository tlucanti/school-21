/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:11:07 by kostya            #+#    #+#             */
/*   Updated: 2022/01/15 13:45:27 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

tlucanti::AMateria::AMateria(const std::string &type)
	: type(type)
{
	std::cout << "  Created Amateria of type " << type << std::endl;
}

tlucanti::AMateria::~AMateria()
{
	std::cout << "  Deleted Amateria of type " << type << std::endl;
}

const std::string &
tlucanti::AMateria::getType() const
{
	return type;
}
