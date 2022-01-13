/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:02:58 by kostya            #+#    #+#             */
/*   Updated: 2022/01/12 13:20:57 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

#if __cplusplus <= 199711L
# define override
#endif

namespace tlucanti
{
	class Cat : public Animal
	{
	public:
		Cat();
		~Cat();
		Cat(const Cat &cpy);
		void makeSound() const override;
		std::string &operator [](unsigned short at);

	private:
		tlucanti::Brain *brain;
	};
}
