/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:10:42 by kostya            #+#    #+#             */
/*   Updated: 2022/01/15 13:46:04 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "AMateria.hpp"

namespace tlucanti
{
	class Cure : public AMateria
	{
	public:
		Cure();
		~Cure() override __DEFAULT

		__WUR AMateria *clone() const override;
		void use(ICharacter &target) override;
	};
}
