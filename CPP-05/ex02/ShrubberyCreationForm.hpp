/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:38:31 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 16:23:28 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>

#include "Form.hpp"
#include "defs.h"

namespace tlucanti
{
	class ShrubberyCreationForm : public Form
	{
	public:
		explicit ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm() override __DEFAULT

		void execute(const Bureaucrat &executor);
	};
}
