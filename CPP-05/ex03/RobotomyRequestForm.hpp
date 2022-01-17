/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:38:44 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 16:20:30 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <unistd.h>

#include "Form.hpp"
#include "defs.h"

namespace tlucanti
{
	class RobotomyRequestForm : public Form
	{
	public:
		explicit RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm() override __DEFAULT

		void execute(const Bureaucrat &executor);

	private:
		static int random(int start, int stop);
	};
}
