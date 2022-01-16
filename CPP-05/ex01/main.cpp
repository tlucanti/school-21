/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:02:23 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 13:32:35 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Exception.hpp"

int main()
{
	std::cout << "--> invalid create\n";
	{
		try
		{
			tlucanti::Form frm0("name0", 0, 10);
		}
		catch (const tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}
	{
		try
		{
			tlucanti::Form frm0("name0", 999, 10);
		}
		catch (const tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}
	{
		try
		{
			tlucanti::Form frm0("name0", 10, 0);
		}
		catch (const tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}
	{
		try
		{
			tlucanti::Form frm0("name0", 10, 999);
		}
		catch (const tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}
	std::cout << "\n--> Form signing\n";
	{
		tlucanti::Form frm0("name0", 10, 10);
		std::cout << frm0 << std::endl;
		tlucanti::Bureaucrat bur0("bur0", 50);
		tlucanti::Bureaucrat bur1("bur1", 5);

		try
		{
			frm0.beSigned(bur0);
		}
		catch (const tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
		frm0.beSigned(bur1);
		frm0.beSigned(bur1);
	}
	std::cout << "\n--> Bureaucrat signing\n";
	{
		tlucanti::Form frm0("name0", 10, 10);
		std::cout << frm0 << std::endl;
		tlucanti::Bureaucrat bur0("bur0", 50);
		tlucanti::Bureaucrat bur1("bur1", 5);

		try
		{
			bur0.signForm(frm0);
		}
		catch (const tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
		bur1.signForm(frm0);
		bur1.signForm(frm0);
	}
}
