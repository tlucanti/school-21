/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:34:19 by kostya            #+#    #+#             */
/*   Updated: 2022/01/10 21:43:48 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

tlucanti::WrongCat::WrongCat()
    : WrongAnimal()
{
	type = "WrongCat";
    std::cout << type << " materialized\n";
}

tlucanti::WrongCat::~WrongCat()
{
    std::cout << "the " << type << " dematerialized\n";
}
