/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:59:27 by kostya            #+#    #+#             */
/*   Updated: 2022/01/05 20:22:31 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <cstdlib>

# if __cplusplus > 199711L
#  define __WUR [[nodiscard]]
#  define __UNUSED [[maybe_unused]]
# else /* not __cplusplus > 199711L */
#  define __WUR __attribute__((warn_unused_result))
#  define noexcept
#  define nullptr NULL
#  define __UNUSED __attribute__((unused))
# endif /* __cplusplus > 199711L */

namespace tlucanti
{
	class Zombie
	{
	public:
		Zombie();
		Zombie(const std::string &_name) noexcept;
		~Zombie();
		void announce() const noexcept;
		void set_name(const std::string &name) noexcept;
	private:
		std::string name;
	};

	__WUR Zombie*	zombieHorde(int N, std::string name);
	__WUR int		random(int start, int stop);
}

#endif /* ZOMBIE_HPP */
