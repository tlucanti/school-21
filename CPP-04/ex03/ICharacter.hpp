/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:18:50 by kostya            #+#    #+#             */
/*   Updated: 2022/01/15 13:46:20 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "AMateria.hpp"

#if __cplusplus <= 199711L
# define __WUR __attribute__((warn_unused_result))
# define __DEFAULT {}
#else
# define __WUR [[nodiscard]]
# define __DEFAULT =default;
#endif

namespace tlucanti
{
	class AMateria;

	class ICharacter
	{
	public:
		virtual ~ICharacter() __DEFAULT
		__WUR virtual std::string const & getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
	};
}
