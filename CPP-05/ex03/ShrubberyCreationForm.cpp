/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:08:44 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 17:00:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

tlucanti::ShrubberyCreationForm::ShrubberyCreationForm(
		const std::string &target)
	: Form("ShrubberyCreationForm", target, 145, 137) {}

void
tlucanti::ShrubberyCreationForm::execute(const tlucanti::Bureaucrat &executor)
{
	if (check_sign())
		return ;
	check_exec(executor);
	std::ofstream outf;
	outf.open((target + "_shrubbery").c_str());
	if (not outf.is_open())
	{
		std::cout << "cannot execute <" << target << "> form, file error\n";
		return ;
	}
	outf << (
		"                      *_                    \n"
		"  __      _*    *       \\    __*           \n"
		" *  \\ ___/      |     ___\\ _/     *\\  _/*\n"
		"     *         /    _/    *       _| /      \n"
		"     |        /    /        _____/ *\\___   \n"
		"     *       /     |     __/_      /    \\  \n"
		"    /       *      *    /  * \\_   * __   * \n"
		"   *        |     /|    \\      \\ __/  \\* \n"
		"  / \\       |___ /  \\    \\__*   *_______ \n"
		"  |  *      *   *    *   *      |       *   \n"
		"  |     __ /  *  \\    \\ /_      *      /  \n"
		"  *    *  *    \\_/     *  \\___ _      *   \n"
		" / \\__/    \\          /       * \\__      \n"
		" *   \\     |         *       /     *       \n"
		"      *    *                *               \n"
	);
	outf.close();
}
