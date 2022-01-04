/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:10:59 by kostya            #+#    #+#             */
/*   Updated: 2022/01/04 19:50:00 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

namespace tlucanti {

	template<typename ForwardIter_T, typename Func_T>
	void for_each(ForwardIter_T _first, ForwardIter_T _last, Func_T _f)
	{
		for (; _first != _last; ++_first)
			*_first = _f(*_first);
	}

}

#if __cplusplus <= 199711L

# define nullptr NULL

char roflan_lambda(char c)
{
	return static_cast<char>(std::toupper(c));
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
		tlucanti::for_each(argst.begin(), argst.end(), roflan_lambda);
		std::cout << argst << ' ';
	}
	std::cout << std::endl;
	return (0);
}

#else

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

#endif
