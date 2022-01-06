/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:52:05 by kostya            #+#    #+#             */
/*   Updated: 2022/01/05 21:02:04 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

namespace tlucanti
{
	class HumanA
	{
	public:
		HumanA(const std::string &_name, const Weapon &_weapon) noexcept;
		void attack() const;

	private:
		const std::string name;
		const Weapon &weapon;
	};
}

#endif /* HUMANA_HPP */
