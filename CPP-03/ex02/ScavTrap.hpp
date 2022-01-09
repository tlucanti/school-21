/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:21:48 by kostya            #+#    #+#             */
/*   Updated: 2022/01/09 16:31:29 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "ClapTrap.hpp"

namespace tlucanti
{
	class ScavTrap : public ClapTrap
	{
	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &cpy);
		~ScavTrap();

		void attack(const std::string &target) const;
		void guardGate() const;
	private:
		ScavTrap();
	};
}
