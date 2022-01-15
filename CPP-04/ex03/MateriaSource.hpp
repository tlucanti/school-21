/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:20:31 by kostya            #+#    #+#             */
/*   Updated: 2022/01/15 09:36:31 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "IMateriaSource.hpp"

namespace tlucanti
{
	class MateriaSource : public IMateriaSource
	{
	public:
		MateriaSource();
		~MateriaSource() override;
		void learnMateria(AMateria *materia) override;
		AMateria *createMateria(const std::string &type) override;
	
	private:
		MateriaSource(const MateriaSource &cpy);
		MateriaSource &operator =(const MateriaSource &cpy);
		AMateria *inventory[4] __DEFINE;
	};
}
