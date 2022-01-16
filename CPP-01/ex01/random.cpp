/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:32:20 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 16:13:53 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

namespace tlucanti
{
	int random(int start, int stop)
	{
		int ret;
		do {
			ret = rand();
		} while (ret >= RAND_MAX - RAND_MAX % (stop - start + 1));
		return ret % (stop - start + 1) + start;
	}
}
