/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:02:23 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 17:54:38 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Exception.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	srand(time(nullptr));
	{
		std::cout << "--> PresidentialPardonForm\n";
		tlucanti::PresidentialPardonForm form("murder");
		tlucanti::Bureaucrat noob("noob", 30);
		tlucanti::Bureaucrat bur("bur", 20);
		tlucanti::Bureaucrat pardoner("pardoner", 5);

		noob.signForm(form);
		form.execute(noob);
		bur.signForm(form);
		try
		{
			form.execute(bur);
		}
		catch (tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
		pardoner.signForm(form);
		form.execute(pardoner);
	}
	{
		std::cout << "\n--> ShrubberyCreationForm\n";
		tlucanti::ShrubberyCreationForm form("home");
		tlucanti::Bureaucrat noob("noob", 150);
		tlucanti::Bureaucrat bur("bur", 140);
		tlucanti::Bureaucrat pardoner("farmer", 130);

		noob.signForm(form);
		form.execute(noob);
		bur.signForm(form);
		try
		{
			form.execute(bur);
		}
		catch (tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
		pardoner.signForm(form);
		form.execute(pardoner);
	}
	{
		std::cout << "\n--> RobotomyRequestForm\n";
		tlucanti::RobotomyRequestForm form("shiz");
		tlucanti::Bureaucrat noob("noob", 80);
		tlucanti::Bureaucrat bur("bur", 70);
		tlucanti::Bureaucrat pardoner("medic", 40);

		noob.signForm(form);
		form.execute(noob);
		bur.signForm(form);
		try
		{
			form.execute(bur);
		}
		catch (tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
		pardoner.signForm(form);
		form.execute(pardoner);
	}
}
