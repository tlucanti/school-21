/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:10:59 by kostya            #+#    #+#             */
/*   Updated: 2021/11/08 15:25:49 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <array>
namespace tlucanti {

template<typename _ForwardIter, typename _Func>
void for_each(_ForwardIter __first, _ForwardIter __last, _Func __f)
{
	for (; __first != __last; ++__first)
		*__first = __f(*__first);
}

}

int main(int, char **argv)
{
	++argv;
	if (*argv == nullptr)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (; *argv != nullptr; ++argv)
	{
		std::string argst = *argv;
		tlucanti::for_each(argst.begin(), argst.end(),
			[](char _c){return std::toupper(_c);});
		std::cout << argst << ' ';
	}
	std::cout << std::endl;
	return (0);
}
