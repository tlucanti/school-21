/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:02:58 by kostya            #+#    #+#             */
/*   Updated: 2022/01/12 18:25:36 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Brain.hpp"

namespace tlucanti
{
	class Animal
	{
	public:
		Animal();
		virtual ~Animal() = 0;
		virtual std::string getType() const;
		virtual void makeSound() const = 0;
		Animal(const Animal &);

	protected:
		std::string type;
	};
}
