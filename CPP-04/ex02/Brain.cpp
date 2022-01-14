/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:59:18 by kostya            #+#    #+#             */
/*   Updated: 2022/01/12 19:59:22 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

tlucanti::Brain::Brain() {}

tlucanti::Brain::~Brain() {}

tlucanti::Brain &
tlucanti::Brain::operator =(const Brain &cpy)
{
	if (&cpy == this)
		return *this;
	for (unsigned short i=0; i < (unsigned short)sizeof(ideas) / sizeof(std::string); ++i)
		ideas[i] = cpy.ideas[i];
	return *this;
}