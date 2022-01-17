/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:02:23 by kostya            #+#    #+#             */
/*   Updated: 2022/01/17 18:07:47 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Exception.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	srand(time(nullptr));
	tlucanti::Intern intern;
	{
		tlucanti::PresidentialPardonForm *pardon =
			dynamic_cast<tlucanti::PresidentialPardonForm *>(
				intern.makeForm("PresidentialPardon", "target man"));

		std::cout << *pardon << std::endl;
		delete pardon;
	}
	{
		tlucanti::RobotomyRequestForm *rob =
			dynamic_cast<tlucanti::RobotomyRequestForm *>(
				intern.makeForm("RobotomyRequest", "target shiz"));

		std::cout << *rob << std::endl;
		delete rob;
	}
	{
		tlucanti::ShrubberyCreationForm *tree =
			dynamic_cast<tlucanti::ShrubberyCreationForm *>(
				intern.makeForm("ShrubberyCreation", "target tree"));

		std::cout << *tree << std::endl;
		delete tree;
	}
	{
		tlucanti::RobotomyRequestForm *lol =
			dynamic_cast<tlucanti::RobotomyRequestForm *>(
				intern.makeForm("lol", "target"));

		std::cout << (void *)lol << std::endl;
	}
}
