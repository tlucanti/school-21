/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:11:12 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 12:38:16 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

tlucanti::Bureaucrat::Bureaucrat(const std::string &name, unsigned short grade)
	: name(name), grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException("grade " + to_string(grade) +
			" lower than minimal 150 grade");
	if (!grade)
		throw GradeTooHighException("grade " + to_string(grade) +
			" higher than maximal 1 grade");
	std::cout << "  you made it, <" << name << ">\n";
}

tlucanti::Bureaucrat::Bureaucrat(const tlucanti::Bureaucrat &cpy)
	: name(cpy.name), grade(cpy.grade)
{
	std::cout << "  Bureaucrat <" << name << "> cloned\n";
}

const std::string &
tlucanti::Bureaucrat::getName() const
{
	return name;
}

unsigned short
tlucanti::Bureaucrat::getGrade() const
{
	return grade;
}

void
tlucanti::Bureaucrat::operator ++()
{
	if (grade - 1 == 0)
		throw GradeTooHighException("grade after increment" +
			to_string(grade - 1) + " higher than maximal 1 grade");
	--grade;
}

void
tlucanti::Bureaucrat::operator ++(int)
{
	++(*this);
}

void
tlucanti::Bureaucrat::operator --()
{
	if (grade + 1 > 150)
		throw GradeTooLowException("grade after decrement " +
			to_string(grade) + " lower than minimal 150 grade");
	++grade;
}

void
tlucanti::Bureaucrat::operator --(int)
{
	--(*this);
}

template<typename type_T>
std::string tlucanti::Bureaucrat::to_string(const type_T &_v) {
	std::stringstream ss;
	ss << _v;
	return ss.str();
}

tlucanti::Bureaucrat::GradeTooLowException::GradeTooLowException(
		const std::string &message)
	: BureaucratException(message) {}

tlucanti::Bureaucrat::GradeTooHighException::GradeTooHighException(
		const std::string &message)
	: BureaucratException(message) {}

tlucanti::Bureaucrat::GradeTooLowException::GradeTooLowException()
	: BureaucratException("grade too low") {}

tlucanti::Bureaucrat::GradeTooHighException::GradeTooHighException()
	: BureaucratException("grade too high") {}

std::ostream &
operator <<(std::ostream &out, const tlucanti::Bureaucrat &bur)
{
	out << "<" << bur.getName() << "> Bureaucrat with grade <" <<
		bur.getGrade();
	return out;
}
