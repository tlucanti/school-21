/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:11:14 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 20:34:42 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <sstream>

#include "Exception.hpp"
#include "defs.h"

namespace tlucanti
{
	class Bureaucrat
	{
	public:
		Bureaucrat(const std::string &name, unsigned short grade);
		~Bureaucrat() __DEFAULT
		Bureaucrat(const Bureaucrat &cpy);

		__WUR const std::string &getName() const;
		__WUR unsigned short getGrade() const;

		void operator ++();
		void operator ++(int);
		void operator --();
		void operator --(int);

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

		Bureaucrat() __DEFAULT
		Bureaucrat &operator =(const Bureaucrat &cpy);

		const std::string name;
		unsigned short grade __DEFINE;

		template <typename type_T>
		static std::string to_string(const type_T &_v);
	};
}

std::ostream &operator <<(std::ostream &out, const tlucanti::Bureaucrat &bur);
