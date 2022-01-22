/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:10:46 by kostya            #+#    #+#             */
/*   Updated: 2022/01/22 20:16:13 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace tlucanti
{
	template <typename type_T, typename size_T, typename func_T>
	void iter(type_T *array, const size_T &size, func_T func)
	{
		for (size_T i=0; i != size; ++i)
			array[i] = func(array[i]);
	}
}
