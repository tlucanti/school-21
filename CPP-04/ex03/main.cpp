/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:38:18 by kostya            #+#    #+#             */
/*   Updated: 2022/01/15 13:53:25 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		std::cout << "\n------------------------------------------\n"
			"testing Cure\n";
		std::cout << "cure0\n";
		tlucanti::Cure cure0;
		std::cout << cure0.getType() << std::endl;
		std::cout << "cure1\n";
		tlucanti::Cure *cure1 = dynamic_cast<tlucanti::Cure *>(cure0.clone());
		std::cout << cure1->getType() << std::endl;

		std::cout << "cure2\n";
		tlucanti::Cure *cure2 = new tlucanti::Cure;
		std::cout << "cure3\n";
		tlucanti::Cure *cure3 = dynamic_cast<tlucanti::Cure *>(cure2->clone());
		std::cout << cure3->getType() << std::endl;

		std::cout << "deleting\n";
		delete cure1;
		delete cure2;
		delete cure3;
	}
	{
		std::cout << "\n------------------------------------------\n"
			"testing Ice\n";
		std::cout << "ice0\n";
		tlucanti::Ice ice0;
		std::cout << ice0.getType() << std::endl;
		std::cout << "ice1\n";
		tlucanti::Ice *ice1 = dynamic_cast<tlucanti::Ice *>(ice0.clone());
		std::cout << ice1->getType() << std::endl;

		std::cout << "ice2\n";
		tlucanti::Ice *ice2 = new tlucanti::Ice;
		std::cout << "ice3\n";
		tlucanti::Ice *ice3 = dynamic_cast<tlucanti::Ice *>(ice2->clone());
		std::cout << ice3->getType() << std::endl;

		std::cout << "deleting\n";
		delete ice1;
		delete ice2;
		delete ice3;
	}
	{
		std::cout << "\n------------------------------------------\n"
			"testing Character and Amateria\n";
		std::cout << "cure0\n";
		tlucanti::Cure cure0;
		std::cout << "ice0\n";
		tlucanti::Ice *ice0 = new tlucanti::Ice;
		std::cout << "char0\n";
		tlucanti::Character *char0 = new tlucanti::Character("char0");
		std::cout << char0->getName() << std::endl;
		std::cout << "equiping\n";
		char0->equip(&cure0);
		char0->equip(ice0);
		char0->equip(&cure0);
		char0->equip(ice0);
		char0->equip(ice0);

		std::cout << "using\n";
		char0->use(0, *char0);
		char0->use(1, *char0);
		char0->use(2, *char0);
		char0->use(3, *char0);
		char0->use(4, *char0);

		std::cout << "char1\n";
		tlucanti::Character char1(*char0);
		std::cout << "using\n";
		char1.use(0, *char0);
		char1.use(1, *char0);
		char1.use(2, *char0);
		char1.use(3, *char0);
		char1.use(4, *char0);

		std::cout << "unequiping\n";
		char0->unequip(0);
		char0->unequip(0);
		char0->unequip(1);
		char0->unequip(2);
		char0->unequip(3);
		char0->unequip(4);

		std::cout << "self using\n";
		cure0.use(char1);
		ice0->use(char1);

		std::cout << "deleting\n";
		delete ice0;
		delete char0;
	}
	{
		std::cout << "\n------------------------------------------\n"
			"testing Materia Source\n";
		std::cout << "creating materia\n";
		tlucanti::Cure cure0;
		tlucanti::Ice ice0;
		std::cout << "creating source\n";
		tlucanti::MateriaSource source;
		std::cout << "unknown cure\n";
		source.createMateria("Cure");
		std::cout << "learn cure\n";
		source.learnMateria(&cure0);
		std::cout << "new cure\n";
		tlucanti::AMateria *new_m = source.createMateria("Cure");
		std::cout << new_m->getType() << std::endl;
		delete new_m;
		std::cout << "learn ice\n";
		source.learnMateria(&ice0);
		std::cout << "new ice\n";
		new_m = source.createMateria("Ice");
		std::cout << new_m->getType() << std::endl;
		delete new_m;
		std::cout << "learn other\n";
		source.learnMateria(&cure0);
		source.learnMateria(&ice0);
		source.learnMateria(&ice0);
		source.createMateria("lol");
		std::cout << "deleting\n";
	}
	{
		std::cout << "\n------------------------------------------\n"
			"42 test\n";
		tlucanti::IMateriaSource* src = new tlucanti::MateriaSource();
		src->learnMateria(new tlucanti::Ice());
		src->learnMateria(new tlucanti::Cure());
		tlucanti::ICharacter* me = new tlucanti::Character("me");
		tlucanti::AMateria* tmp;
		tmp = src->createMateria("Ice");
		me->equip(tmp);
		tmp = src->createMateria("Cure");
		me->equip(tmp);
		tlucanti::ICharacter* bob = new tlucanti::Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
}
