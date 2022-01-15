/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:10:42 by kostya            #+#    #+#             */
/*   Updated: 2022/01/15 13:46:19 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "AMateria.hpp"

namespace tlucanti
{
	class Ice : public AMateria
	{
	public:
		Ice();
		~Ice() override __DEFAULT

		__WUR AMateria *clone() const override;
		void use(ICharacter &target) override;
	};
}
