/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:08:41 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 17:56:12 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

tlucanti::RobotomyRequestForm::RobotomyRequestForm(
		const std::string &target)
	: Form("RobotomyRequestForm", target, 72, 45) {}

void
tlucanti::RobotomyRequestForm::execute(const tlucanti::Bureaucrat &executor)
{
	const unsigned int sleep_t = 1000000;

	if (check_sign())
		return ;
	check_exec(executor);
	for (unsigned short i=0; i < 5; ++i)
	{
		std::cout << "DrrdRDrDDrrdrRRRDDddDRDd\n";
		usleep(sleep_t / (random(2, 8) - 0.5));
	}
	if (random(0, 1) == 1)
		std::cout << "<" << target <<
			"> has been robotomized successfully\n";
	else
		std::cout << "<" << target << "> died during robotomy\n";
}

int
tlucanti::RobotomyRequestForm::random(int start, int stop)
{
	int		ret;
	do {
		ret = rand();
	} while (ret >= RAND_MAX - RAND_MAX % (stop - start + 1));
	return ret % (stop - start + 1) + start;
}
