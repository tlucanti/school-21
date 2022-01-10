/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:52:45 by kostya            #+#    #+#             */
/*   Updated: 2022/01/10 16:45:19 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

#if __cplusplus > 199711L
# define __WUR [[nodiscard]]
#else
# define __WUR __attribute__((warn_unused_result))
# define noexcept
# define nullptr NULL
#endif

namespace tlucanti
{
	class Zombie
	{
	public:
		explicit Zombie(const std::string &_name) noexcept;
		void announce() const noexcept;
	private:
		const std::string &name;
	};

	Zombie *newZombie(const std::string &name) noexcept;
	void randomChump(const std::string &name) noexcept;
}

#endif
