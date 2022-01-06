/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:52:05 by kostya            #+#    #+#             */
/*   Updated: 2022/01/05 21:08:06 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

namespace tlucanti
{
	class HumanB
	{
	public:
		HumanB(const std::string &_name, const Weapon &_weapon) noexcept;
		HumanB(const std::string &_name) noexcept;
		void attack() const;
		void setWeapon(const Weapon &_weapon);

	private:
		const std::string name;
		Weapon *weapon;
	};
}

#endif /* HUMANB_HPP */
