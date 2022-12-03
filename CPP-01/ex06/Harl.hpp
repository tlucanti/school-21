/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:54:37 by kostya            #+#    #+#             */
/*   Updated: 2022/01/10 19:52:46 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# if __cplusplus <= 199711L
#  define noexcept
#  define __FALLTHROUGH __attribute__((fallthrough))
# else
#  define __FALLTHROUGH [[fallthrough]]
# endif

# include <string>
# include <iostream>

namespace tlucanti
{
	class Harl
	{
	public:
		Harl();
		void	complain(std::string level);
		static unsigned char hash(const std::string &str);

	private:
		static void	debug();
		static void	info();
		static void	warning();
		static void	error();
		static void	invalid_level();

		void (*funcs[255])();
	};
}

#endif /* KAREN_HPP */
