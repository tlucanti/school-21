/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:59:40 by kostya            #+#    #+#             */
/*   Updated: 2022/01/09 13:39:39 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

namespace tlucanti
{
	class ClapTrap
	{
	public:
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &cpy);
		~ClapTrap();
		ClapTrap &operator =(const ClapTrap &cpy);

		virtual void attack(const std::string &target) const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		ClapTrap();
		std::string		name;
		unsigned int	hp;
		unsigned int	energy;
		unsigned int	damage;

	};
}
