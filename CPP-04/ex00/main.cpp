/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:02:27 by kostya            #+#    #+#             */
/*   Updated: 2022/01/10 21:47:54 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const tlucanti::Animal *meta = new tlucanti::Animal();
		const tlucanti::Animal *j = new tlucanti::Dog();
		const tlucanti::Animal *i = new tlucanti::Cat();

		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		std::cout << meta->getType() << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	{
		const tlucanti::WrongAnimal *wr = new tlucanti::WrongAnimal();
		const tlucanti::WrongCat *wc = new tlucanti::WrongCat();

		std::cout << wr->getType() << std::endl;
		std::cout << wc->getType() << std::endl;

		wr->makeSound();
		wc->makeSound();

		delete wr;
		delete wc;
	}
	return 0;
}
