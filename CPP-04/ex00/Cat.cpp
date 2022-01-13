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
	std::cout << type << " just slid into room\n";
}

tlucanti::Cat::~Cat()
{
	std::cout << "the " << type << " was blown up\n";
}

void
tlucanti::Cat::makeSound() const
{
	std::cout << "<" << type << "> Mew\n";
}
