/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:32:45 by kostya            #+#    #+#             */
/*   Updated: 2022/01/05 20:41:34 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string st = "HI, THIS IS BRAIN";
    std::string *stringPTR = &st;
    std::string &stringREF = st;

    std::cout << "address of string:    " << stringPTR << std::endl;
    std::cout << "address of reference: " << &stringREF << std::endl;
    std::cout << "address of reference is equal to address of string: ";
    std::cout << ((&stringREF == stringPTR) ? "true" : "false") << std::endl;
    std::cout << "value of pointer:   " << *stringPTR << std::endl;
    std::cout << "value of reference: " << stringREF << std::endl;
}
