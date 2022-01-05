/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:59:53 by kostya            #+#    #+#             */
/*   Updated: 2022/01/05 20:18:12 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

namespace tlucanti
{
    Zombie* zombieHorde(int N, __UNUSED std::string name)
    {
        static const char *names[] =
        {
            "Ash Williams", "Billy Butcherson", "Bub", "Dr. Hill",
            "Detective Roger Mortis", "Ed", "Eddie", "Evil Ash", "Fido",
            "Frankenstein", "Ghoulia Yelps", "Jason Todd", "Jason Voorhees",
            "Judge Hopkins", "Julie", "Karen Cooper", "Liv Moore", "M",
            "Madeline Ashton", "Merle Dixon", "Murphy", "Pete", "R",
            "Randall Skeffington", "She", "Sheila Hammond", "Solomon Grundy",
            "Sophia Peletier", "Tarman", "White Walker", "Albert Francis",
            "Boston Brand", "Cassidy", "Deathlok", "Eric Draven",
            "Frank Castle", "Hannibal King", "Jim Corrigan",
            "Jonathan Osterman", "Mitchell Shelley", "Moonbeam", "Ralph Dibney",
            "Simon Dark", "Simon William Garth", "Sue Dibney", "Abdulbaith",
            "Ajal", "Amara", "Arius", "Azrail", "Dabria", "Dearil", "Javaraya",
            "Kalabhiti", "Kalakuta", "Khalida", "Lorelai", "Mayhem", "Morrigan",
            "Mirthunjayan", "Omisha", "Tuwile", "Thanatos", "Yamajit",
            "Yamaraj", "Aeron", "Libitina", "Marduk", "Merikh", "Mirrikh",
            "Morana", "Mortimer", "Mort", "Morty", "Than", "Thana", "Thanatos",
            "Valdis", "Valadis", "Waldeburg", "Jiangshi", "Amy", "Andrea",
            "Deanna Monroe", "Enid", "Ezekiel", "Hershel Greene",
            "Jessie Anderson", "Merle Dixon", "Lori Grimes", "Olivia",
            "Philip Blake", "Rosita Espinosa", "Sasha Williams", "Shane Walsh",
            "Sophia Peletier", "Siddiq", "Simon", "Spencer Monroe",
            "Tara Chambler", "Tyreese"
        };

#if __cplusplus > 199711L
        auto horde = new Zombie [N];
#else
        Zombie *horde = new Zombie [N];
#endif
        for (int i=0; i < N; ++i)
        {
			horde[i].set_name(names[random(0, 101)]);
            horde[i].announce();
        }
        return horde;
    }
}
