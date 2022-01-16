/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:30:43 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 17:01:09 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

tlucanti::Form::Form(const std::string &name, const std::string &target,
		unsigned short grade_to_sign, unsigned short grade_to_execute)
	: name(name), target(target),  is_signed(false),
		grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	check_grade(grade_to_sign);
	check_grade(grade_to_execute);
	std::cout << "  form <" << name << "> created\n";
}

tlucanti::Form::Form(const Form &cpy)
	: name(cpy.name), target(cpy.target), is_signed(cpy.is_signed),
		grade_to_sign(cpy.grade_to_sign), grade_to_execute(cpy.grade_to_execute)
{
	check_grade(grade_to_sign);
	check_grade(grade_to_execute);
	std::cout << "form <" << name << "> created\n";
}

const std::string &
tlucanti::Form::getName() const
{
	return name;
}

unsigned short
tlucanti::Form::getExecuteGrade() const
{
	return grade_to_execute;
}

unsigned short
tlucanti::Form::getSignGrade() const
{
	return grade_to_sign;
}

void
tlucanti::Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > grade_to_sign)
		throw GradeTooLowException("grade of Bureaucrat <" + bur.getName() +
			"> too low to sign form <" + name + ">");
	if (is_signed)
		std::cout << "form <" << name << "> already signed, nothing happened\n";
	is_signed = true;
}

void
tlucanti::Form::check_grade(unsigned short grade) const
{
	if (grade > 150)
		throw GradeTooLowException("grade " + to_string(grade) +
			" lower than minimal 150 grade");
	if (!grade)
		throw GradeTooHighException("grade " + to_string(grade) +
			" higher than maximal 1 grade");
}

void
tlucanti::Form::check_exec(const tlucanti::Bureaucrat &bur) const
{
	if (bur.getGrade() > grade_to_execute)
		throw GradeTooLowException("grade of Bureaucrat <" + bur.getName() +
			"> too low to execute form <" + name + ">");
}

bool
tlucanti::Form::check_sign() const
{
	if (not is_signed)
	{
		std::cout << "form <" << name << "> should be siged before exeution\n";
		return true;
	}
	return false;
}

tlucanti::Form::GradeTooLowException::GradeTooLowException(
		const std::string &message)
	: BureaucratException(message) {}

tlucanti::Form::GradeTooHighException::GradeTooHighException(
		const std::string &message)
	: BureaucratException(message) {}

tlucanti::Form::GradeTooLowException::GradeTooLowException()
	: BureaucratException("grade too low") {}

tlucanti::Form::GradeTooHighException::GradeTooHighException()
	: BureaucratException("grade too high") {}

template<typename type_T>
std::string tlucanti::Form::to_string(const type_T &_v) {
	std::stringstream ss;
	ss << _v;
	return ss.str();
}

std::ostream &
operator <<(std::ostream &out, const tlucanti::Form &frm)
{
	out << "<" << frm.getName() << "> form, grade to sign: <" << frm.getSignGrade() <<
		">, grade to execute: <" << frm.getExecuteGrade() << ">";
	return out;
}
