/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:02:58 by kostya            #+#    #+#             */
/*   Updated: 2022/01/10 21:38:59 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

namespace tlucanti
{
	class Animal
	{
	public:
		Animal();
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const;

	protected:
		Animal(const Animal &);
		Animal &operator =(const Animal &);
		std::string type;
	};
}
