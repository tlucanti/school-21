/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:11:07 by kostya            #+#    #+#             */
/*   Updated: 2022/01/12 18:31:17 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

namespace tlucanti
{
	class Brain
	{
	public:
		Brain();

		std::string ideas[100];
		~Brain();
		Brain &operator =(const Brain &cpy);

	private:
		Brain(const Brain &cpy);
	};
}
