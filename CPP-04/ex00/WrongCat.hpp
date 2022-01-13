/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:34:19 by kostya            #+#    #+#             */
/*   Updated: 2022/01/10 21:34:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "WrongAnimal.hpp"

#if __cplusplus <= 199711L
# define override
#endif

namespace tlucanti
{
	class WrongCat : public WrongAnimal
	{
	public:
		WrongCat();
		~WrongCat();
	};
}
