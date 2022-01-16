/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:02:23 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 11:30:52 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Exception.hpp"

int main()
{
	{
		try
		{
			tlucanti::Bureaucrat bur0("name0", 0);
		}
		catch (const tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}
	{
		try
		{
			tlucanti::Bureaucrat bur0("name0", 999);
		}
		catch (const tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}
	{
		tlucanti::Bureaucrat bur0("name0", 1);
		std::cout << bur0 << std::endl;
		try
		{
			++bur0;
		}
		catch (const tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}
	{
		tlucanti::Bureaucrat bur0("name0", 150);
		std::cout << bur0 << std::endl;
		try
		{
			--bur0;
		}
		catch (const tlucanti::BureaucratException &exc)
		{
			std::cout << exc.what() << std::endl;
		}
	}
}
