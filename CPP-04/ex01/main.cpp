/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:22:22 by kostya            #+#    #+#             */
/*   Updated: 2022/01/12 19:59:56 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>
#include <string>
#include <vector>
int main()
{
	const int	size = 10;
	static_assert(size > 0 and !(size % 2), "array size should be positive, even");

    tlucanti::Animal **animals = new tlucanti::Animal *[size];

	for (int i=0; i < size; ++i)
		animals[i] = new tlucanti::Cat();
	for (int i=size / 2; i < size; ++i)
		animals[i] = new tlucanti::Dog();

	for (int i=0; i < size; ++i)
		delete animals[i];
	delete [] animals;

	{
		std::cout << "\n♂Deep♂ copy tester\n";
		tlucanti::Cat a;
		a[0] = "Hello";
		tlucanti::Cat b = a;
		std::cout << a[0] << " == " << b[0] << std::endl;

		tlucanti::Dog c;
		c[0] = "Holle";
		tlucanti::Dog d = c;
		std::cout << c[0] << " == " << d[0] << std::endl;
	}
}
