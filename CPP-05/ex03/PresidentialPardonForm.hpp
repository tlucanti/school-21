/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:38:54 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 16:07:26 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include "defs.h"

namespace tlucanti
{
	class PresidentialPardonForm : public Form
	{
	public:
		explicit PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm() override __DEFAULT

		void execute(const Bureaucrat &executor);
	};
}
