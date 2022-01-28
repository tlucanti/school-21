/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:20:31 by kostya            #+#    #+#             */
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
# define __DEFINE
# ifndef nullptr
#  define nullptr NULL
# endif
#else
# define __WUR [[nodiscard]]
# define __DEFAULT =default;
# define __DEFINE {}
#endif

namespace tlucanti
{
	class IMateriaSource
	{
	public:
		virtual ~IMateriaSource() __DEFAULT
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria *createMateria(const std::string &type) = 0;
	};
}
