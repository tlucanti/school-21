/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:51:57 by kostya            #+#    #+#             */
/*   Updated: 2022/01/17 16:13:26 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

tlucanti::Form *(*tlucanti::Intern::funcs[3])(const std::string &target) = {
	_make_pres, _make_rob, _make_shrub};
const char *tlucanti::Intern::names[3] = {"PresidentialPardon",
	"RobotomyRequest", "ShrubberyCreation"};

tlucanti::Form *
tlucanti::Intern::makeForm(const std::string &name,
	const std::string &target)
{
	for (unsigned short i=0; i < 3; ++i)
	{
		if (names[i] == name)
		{
			std::cout << "Intern creates <" << name << ">\n";
			return funcs[i](target);
		}
	}
	std::cout << "Intern: form <" << name << "> is unknown\n";
	return nullptr;
}

tlucanti::Form *
tlucanti::Intern::_make_pres(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

tlucanti::Form *
tlucanti::Intern::_make_rob(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

tlucanti::Form *
tlucanti::Intern::_make_shrub(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}
