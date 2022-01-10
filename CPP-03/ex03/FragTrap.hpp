/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:06:10 by kostya            #+#    #+#             */
/*   Updated: 2022/01/09 17:14:33 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

namespace tlucanti
{
	class FragTrap : virtual public ClapTrap
	{
	public:
		FragTrap(const std::string &_name);
		FragTrap(const FragTrap &cpy);
		~FragTrap();

		void highFivesGuys() const;
	protected:
		FragTrap();
	};
}
