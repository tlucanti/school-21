/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:19:38 by kostya            #+#    #+#             */
/*   Updated: 2022/01/17 13:29:56 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "defs.h"

namespace tlucanti
{
	class Intern
	{
	public:
		Intern() __DEFAULT
		~Intern() __DEFAULT
		Intern(__UNUSED const Intern &cpy) __DEFAULT
		Intern &operator =(__UNUSED const Intern &cpy) __DEFAULT_ASSIGN

		__WUR Form *makeForm(const std::string &name,
			const std::string &target);

	private:
		static Form *_make_pres(const std::string &target);
		static Form *_make_rob(const std::string &target);
		static Form *_make_shrub(const std::string &target);

		static Form *(*funcs[3])(const std::string &target);
		static const char *names[3];
	};
}
