/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:52:05 by kostya            #+#    #+#             */
/*   Updated: 2022/01/06 14:39:04 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>
# if __cplusplus > 199711L
#  define __WUR [[nodiscard]]
# else
#  define __WUR __attribute__((warn_unused_result))
#  define noexcept
#  define nullptr NULL
# endif

namespace tlucanti
{
	class Weapon
	{
	public:
		Weapon(const std::string &_type) noexcept;

		__WUR std::string getType() const;
		void setType(const std::string &_type);

	private:
		std::string type;
	};

}

std::ostream &operator <<(std::ostream &out, const tlucanti::Weapon &weapon);

#endif /* WEAPON_HPP */
