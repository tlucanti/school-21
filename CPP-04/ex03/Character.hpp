/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:38:00 by kostya            #+#    #+#             */
/*   Updated: 2022/01/15 13:46:01 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "ICharacter.hpp"
#include "AMateria.hpp"

#if __cplusplus <= 199711L
# define __WUR __attribute__((warn_unused_result))
# define __DEFAULT {}
# define nullptr NULL
# define override
# define __DEFINE
#else
# define __WUR [[nodiscard]]
# define __DEFAULT =default;
# define __DEFINE {}
#endif

namespace tlucanti
{
	class Character : public ICharacter
	{
	public:
		explicit Character(const std::string &name);
		~Character() override;
		Character(const Character &cpy);
		Character &operator =(const Character &cpy);

		__WUR const std::string &getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;

	private:
		std::string name;
		AMateria *inventory[4] __DEFINE;
	};
}
