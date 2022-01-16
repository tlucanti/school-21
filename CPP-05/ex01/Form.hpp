/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:30:43 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 13:58:52 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

namespace tlucanti
{
	class Bureaucrat;

	class Form
	{
	public:
		Form(const std::string &name, unsigned short grade_to_sign,
			unsigned short grade_to_execute);
		Form(const Form &cpy);
		~Form() __DEFAULT

		__WUR const std::string &getName() const;
		__WUR unsigned short getExecuteGrade() const;
		__WUR unsigned short getSignGrade() const;

		void beSigned(const Bureaucrat &bur);

	private:
		class GradeTooLowException : public BureaucratException
		{
		public:
			explicit GradeTooLowException(const std::string &message);
			GradeTooLowException();
		};

		class GradeTooHighException : public BureaucratException
		{
		public:
			explicit GradeTooHighException(const std::string &message);
			GradeTooHighException();
		};

		Form();
		Form &operator =(const Form &cpy);

		const std::string name;
		bool is_signed __DEFINE;
		const unsigned short grade_to_sign __DEFINE;
		const unsigned short grade_to_execute __DEFINE;

		void check_grade(unsigned short grade) const;

		template <typename type_T>
		static std::string to_string(const type_T &_v);
	};
}

std::ostream &operator <<(std::ostream &out, const tlucanti::Form &frm);
