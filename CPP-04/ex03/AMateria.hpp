/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:47:57 by kostya            #+#    #+#             */
/*   Updated: 2022/01/15 13:45:30 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "ICharacter.hpp"

#if __cplusplus <= 199711L
# define __WUR __attribute__((warn_unused_result))
# define __DEFAULT {}
# define override
#else
# define __WUR [[nodiscard]]
# define __DEFAULT =default;
#endif

namespace tlucanti
{
	class ICharacter;

	class AMateria
	{
	public:
		explicit AMateria(const std::string &type);
		virtual ~AMateria();

		__WUR virtual const std::string &getType() const;
		__WUR virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target) = 0;

	protected:
		std::string type;

		AMateria() __DEFAULT
		AMateria(const AMateria &cpy);
		AMateria &operator =(const AMateria &cpy);
	};
}
