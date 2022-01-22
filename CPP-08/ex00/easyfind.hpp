/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:05:55 by kostya            #+#    #+#             */
/*   Updated: 2022/01/23 00:30:04 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>

namespace tlucanti
{
	template <typename cont_T>
	typename cont_T::const_iterator easyfind(const cont_T &cont, int val)
	{
		return std::find(cont.cbegin(), cont.cend(), val);
	}
}
