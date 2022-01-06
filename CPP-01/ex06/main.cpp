/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:56:26 by kostya            #+#    #+#             */
/*   Updated: 2022/01/06 23:45:20 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <string>
#include <iostream>
#include <stdint.h>

#define DEBUG_HASH 802051710275061239ull
#define INFO_HASH 11068318609956848693ull
#define WARNING_HASH 12381435248833120625ull
#define ERROR_HASH 727822527486890789ull

namespace tlucanti
{
	uint64_t    Pearson64(const std::string &str)
	{
		static unsigned char    T[256] = {
		   198, 174,  59,  23,  15,  76, 146, 151, 145, 233, 215, 195, 201,
		   152, 164, 128,  29, 214, 172, 138,  57, 121,  67, 194,  53, 156,
		   108,  72, 237, 101,  46,  96, 231, 238, 122, 162, 199, 169,  83,
		    54, 206, 109, 113,  40,  26,  61, 239, 183,  48, 193, 229,  22,
		   155,  33,  63, 123, 119,  82, 153, 103,  25,  52,  10, 112, 124,
		   159,  12, 161,  98, 191, 226,  62,  69, 165, 242, 189,  95,   0,
		   116, 205,  66,  39, 247, 230, 225,  30, 245, 203, 209, 244, 208,
		   234, 251, 158,  79, 216, 220, 125,  44, 250,  13, 157,  37,  16,
		    24,  38, 185,  14,  71, 190,  21, 176, 187,  32, 217,   9, 204,
		   197,  75, 196,  36,  97,  58, 133,  77, 142, 177,  80,  91, 184,
		   181, 141,  49, 129, 254,  34,   6, 130, 160, 170, 213, 240, 149,
		    87, 200, 186,  51,  35,  65,   7, 179,  81, 147, 246, 248,   8,
		     5, 178, 144, 253,  18, 241, 192, 227, 222, 106,  92,  68,  28,
		   255,  31, 221, 210, 168,  78,  43, 163,  11, 148, 211, 212,  88,
		    74,  45,  20,  55, 252, 223, 182,  70, 219,  90, 117,   2,  84,
		    27, 110,  17, 175, 135, 228, 167, 114,  56, 105,  93, 136, 127,
		    86,  47,  99, 173, 249,   4, 131, 166, 232, 235, 207,  50, 115,
		   120, 143, 118, 140,  94, 188, 137, 154,  60,  85,  41,   1,  19,
		   150, 134, 104, 180,  73, 100, 171, 139, 126,  42, 107, 243, 132,
		   236,  64, 202,   3,  89, 218, 102, 224, 111
		};

		uint64_t hash = 0;
		unsigned char h;

		for (int i=0; i < (int)sizeof(hash); ++i)
		{
			h = T[(str[0] + i) % 256];
			for (size_t it=1; it < str.size(); ++it)
				h = T[h ^ str[it]];
			hash = (hash << 8) | h;
		}
		return hash;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Invalid arguments\n";
		return 1;
	}

	tlucanti::Karen karen;
	switch(tlucanti::Pearson64(argv[1]))
	{
		case DEBUG_HASH:  karen.complain("debug");
		case INFO_HASH:   karen.complain("info");
		case WARNING_HASH: karen.complain("warning");
		case ERROR_HASH: karen.complain("error");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
