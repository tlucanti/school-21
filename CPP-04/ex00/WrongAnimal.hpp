/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:29:31 by kostya            #+#    #+#             */
/*   Updated: 2022/01/10 21:34:03 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

namespace tlucanti
{
	class WrongAnimal
	{
	public:
		WrongAnimal();
		~WrongAnimal();
		std::string getType() const;
		void makeSound() const;

	protected:
		WrongAnimal(const WrongAnimal &);
		WrongAnimal &operator =(const WrongAnimal &);
		std::string type;
	};
}
