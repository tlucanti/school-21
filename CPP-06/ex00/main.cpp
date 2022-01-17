/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:29:49 by kostya            #+#    #+#             */
/*   Updated: 2022/01/18 00:53:42 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Converter.hpp"

template <typename type_T>
void print_float(type_T val)
{
	if (std::abs(val) <= 1e-4 or std::abs(val) >= 1e6)
	{
		std::cout << val;
		return ;
	}
	if ((long long )(val * 1e6) % 1000000 == 0)
		std::cout << (long long)val << ".0";
	else
		std::cout << val;
}

int main(int argc, char **argv)
{
	{
		if (argc > 2)
			std::cout << "extra arguments ignored\n";
		if (argc == 1)
		{
			std::cout << "need arguments\n";
			return 0;
		}

		tlucanti::Converter conv(argv[1]);
		std::cout << "char: ";
		try {
			std::cout << static_cast<char>(conv) << std::endl;
		} catch (tlucanti::Converter::ConvertationError &exc) {
			std::cout << exc.what() << std::endl;
		}
		std::cout << "int: ";
		try {
			std::cout << static_cast<int>(conv) << std::endl;
		} catch (tlucanti::Converter::ConvertationError &exc) {
			std::cout << exc.what() << std::endl;
		}
		std::cout << "float: ";
		try {
			print_float(static_cast<float>(conv));
			std::cout << "f\n";
		} catch (tlucanti::Converter::ConvertationError &exc) {
			std::cout << exc.what() << std::endl;
		}
		std::cout << "double: ";
		try {
			print_float(static_cast<double>(conv));
			std::cout << std::endl;
		} catch (tlucanti::Converter::ConvertationError &exc) {
			std::cout << exc.what() << std::endl;
		}
	}
}
