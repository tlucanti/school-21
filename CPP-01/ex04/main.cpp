/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:16:39 by kostya            #+#    #+#             */
/*   Updated: 2022/01/06 17:10:31 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

namespace tlucanti
{
	void replace(std::string &str, const std::string &from,
		const std::string &to)
	{
		if (from == to)
			return ;
		size_t it = str.find(from, 0);
		while (it != std::string::npos)
		{
			str = str.substr(0, it) + to +
				str.substr(it + from.size(), std::string::npos);
			it += to.size() - from.size();
			it = str.find(from, it);
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: invalid arguments\n"
			"Usage: ./repl [FILENAME] [STR_FROM] [STR_TO]\n"
			"    [FILENAME] - is name of file\n"
			"    [STR_FROM] - string that will replaced with [STR_TO]\n";
			return 1;
	}
	if (!*argv[2])
	{
		std::cout << "Error: [STR_FROM] cannot be empty\n";
		return 1;
	}
	
	std::ifstream inp(argv[1]);
	if (not inp.is_open())
	{
		std::cout << "cannot open file " << argv[1] << std::endl;
		return 1;
	}
	std::ofstream outp(argv[1] + std::string(".replace"));
	if (not outp.is_open())
	{
		std::cout << "cannot create file " << argv[1] << std::endl;
		return 1;
	}

	std::string from = argv[2];
	std::string to = argv[3];
	while (true)
	{
		std::string line;
		std::getline(inp, line, '\n');
		tlucanti::replace(line, from ,to);
		outp << line;
		if (inp.eof())
			break;
		outp << std::endl;
	}
	inp.close();
	outp.close();
	std::cout << "Success\n";
	return 0;
}
