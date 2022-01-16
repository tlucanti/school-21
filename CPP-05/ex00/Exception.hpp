/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:18:22 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 11:14:11 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <string>

#include "defs.h"

namespace tlucanti
{
	class BureaucratException : public std::exception
	{
	public:
		explicit BureaucratException(const std::string &message);
		__OVERRIDE_VIRTUAL ~BureaucratException() noexcept override __DEFAULT
		__WUR __OVERRIDE_VIRTUAL const char *what() const noexcept override;
	protected:
		std::string message;
	};
}
