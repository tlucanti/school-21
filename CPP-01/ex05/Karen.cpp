/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:55:56 by kostya            #+#    #+#             */
/*   Updated: 2022/01/06 21:10:45 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

tlucanti::Karen::Karen()
{
#if __cplusplus > 199711L
	for (auto &func : funcs)
		func = &invalid_level;
#else
	for (short i=0; i < 255; ++i)
		funcs[i] = &invalid_level;
#endif
	funcs[hash("debug")] = &debug;
	funcs[hash("DEBUG")] = &debug;
	funcs[hash("info")] = &info;
	funcs[hash("INFO")] = &info;
	funcs[hash("warning")] = &warning;
	funcs[hash("WARNING")] = &warning;
	funcs[hash("error")] = &error;
	funcs[hash("ERROR")] = &error;
}

void
tlucanti::Karen::complain(std::string level)
{
	(funcs[hash(level)])();
}

void
tlucanti::Karen::debug()
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-"
		"pickle-special-ketchup burger. I just love it!\n";
}

void
tlucanti::Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. You "
		"don’t put enough! If you did I would not have to ask for it!\n";
}

void
tlucanti::Karen::invalid_level()
{
	std::cout << "Invalid level selected\n";
}

void
tlucanti::Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve "
		"been coming here for years and you just started working here last "
		"month.\n";
}

void
tlucanti::Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now.\n";
}

unsigned char
tlucanti::Karen::hash(const std::string &str)
{
	static unsigned char perm_table[] = {
       164, 232,  46, 116, 224, 182, 133, 185,  74, 147, 219, 135,  78,
       104,  58,  30, 115,   3,  57, 239, 252, 171, 118, 180, 253, 196,
        84,   0, 201,  73,  42,  70, 244, 197, 131, 172,  62, 157, 233,
       246, 113, 241, 136, 107,  66,  38, 220,  37,  61,  53,  52,  89,
       222, 161,  41, 103,  69, 110, 121, 153, 167,  96,  92, 132,  49,
       142,  82, 203,  21, 151, 111, 245, 144, 191, 156, 130,  87,  24,
        16, 238,  27, 148,  33, 168,  20, 187, 137,  55, 174, 229, 208,
       123, 146, 254,  65,  95,  51, 234,  97, 158,  63,  17,  29,  93,
       108,  47,   5, 125, 214, 143, 193, 178,   6, 230, 205,  68,  40,
       188, 204,  48, 243, 207, 117,   4, 221, 141,   9,   7, 122, 213,
         8, 198,  75, 162, 184,  83, 240, 112, 152, 101,  54, 102, 166,
       177, 149,  94, 150,  77,  15,  81, 183,  60, 159, 173,  12,  19,
        23, 195,  11, 223, 154, 215,  13, 237, 181, 212,  88, 228,  59,
       134,  64, 250,  28, 129, 202, 248, 206, 190,  25,  18, 186, 176,
       216, 200,  35,  71,  36, 235, 126, 225,  32,  98, 242,  22,  79,
       114,  99,  67, 165, 160, 170,  91, 236, 100, 124, 192,  43, 217,
       163, 249, 210, 155, 169, 247,   2,  76, 231, 255, 218,  45,  14,
       226, 175,  10,  39,  56, 138, 140, 127, 106, 109, 145, 209, 211,
        90,   1,  44, 128, 139,  86,  26, 194,  34,  80,  85,  31, 120,
       105, 227, 119, 179, 199, 251,  50,  72, 189
	};
	unsigned char hs = str.size();

#if __cplusplus > 199711L
	for (unsigned char c : str)
		hs = perm_table[hs ^ c];
#else
	for (size_t i=0; i < str.size(); ++i)
		hs = perm_table[hs ^ str[i]];
#endif
	return hs;
}
