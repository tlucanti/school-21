/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:35:06 by kostya            #+#    #+#             */
/*   Updated: 2022/01/22 20:04:52 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace tlucanti
{
	template <typename type_T>
	void swap(type_T &a, type_T &b)
	{
		const type_T c = a;
		a = b;
		b = c;
	}

	template <typename type_T>
	const type_T &min(const type_T &a, const type_T &b)
	{
		return a < b ? a : b;
	}

	template <typename type_T>
	const type_T &max(const type_T &a, const type_T &b)
	{
		return a > b ? a : b;
	}
}
