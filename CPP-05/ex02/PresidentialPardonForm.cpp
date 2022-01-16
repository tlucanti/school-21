/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:02:03 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 16:59:21 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

tlucanti::PresidentialPardonForm::PresidentialPardonForm(
		const std::string &target)
	: Form("PresidentialPardonForm", target, 25, 5) {}

void
tlucanti::PresidentialPardonForm::execute(const tlucanti::Bureaucrat &executor)
{
	if (check_sign())
		return ;
	check_exec(executor);
	std::cout << "<" << target <<
		"> has been pardoned by Zafod Beeblebrox.\n";
}
