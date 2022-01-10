/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:25:31 by kostya            #+#    #+#             */
/*   Updated: 2022/01/09 17:31:58 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

namespace tlucanti
{
	class DiamondTrap : public ScavTrap, public FragTrap
	{
	public:
		DiamondTrap(const std::string &_name);
		explicit DiamondTrap(const DiamondTrap &cpy);
		~DiamondTrap();

		void whoAmI() const;

	private:
		std::string name;

		DiamondTrap();
	};
}
