/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:31:34 by kostya            #+#    #+#             */
/*   Updated: 2021/11/09 13:47:58 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP

# include <ostream>
# include <string>


namespace tlucanti {
	class color {
	public:
		static char *black;		// k
		static char *red;			// r
		static char *green;		// g
		static char *yellow;	// y
		static char *blue;		// b
		static char *purple;	// p
		static char *cyan;		// c
		static char *white;		// w
	
		static char *tlucanti;

		static char *reset;		// s
	};

	char *color::black		= (char *) "\033[1;90m";
	char *color::red		= (char *) "\033[1;91m";
	char *color::green		= (char *) "\033[1;92m";
	char *color::yellow		= (char *) "\033[1;93m";
	char *color::blue		= (char *) "\033[1;94m";
	char *color::purple		= (char *) "\033[1;95m";
	char *color::cyan		= (char *) "\033[1;96m";
	char *color::white		= (char *) "\033[1;97m";
	char *color::reset		= (char *) "\033[0m";   

	char *color::tlucanti	= (char *) "\033[19;1;96;21;6m";
}

#ifndef ROFLAN_OLD98

std::string operator ""_black(const char *str, std::size_t)
{
	return std::string() + tlucanti::color::black + str + tlucanti::color::reset;
}

std::string operator ""_red(const char *str, std::size_t)
{
	return std::string() + tlucanti::color::red + str + tlucanti::color::reset;
}

std::string operator ""_green(const char *str, std::size_t)
{
	return std::string() + tlucanti::color::green + str + tlucanti::color::reset;
}

std::string operator ""_yellow(const char *str, std::size_t)
{
	return std::string() + tlucanti::color::yellow + str + tlucanti::color::reset;
}

std::string operator ""_blue(const char *str, std::size_t)
{
	return std::string() + tlucanti::color::blue + str + tlucanti::color::reset;
}

std::string operator ""_purple(const char *str, std::size_t)
{
	return std::string() + tlucanti::color::purple + str + tlucanti::color::reset;
}

std::string operator ""_cyan(const char *str, std::size_t)
{
	return std::string() + tlucanti::color::cyan + str + tlucanti::color::reset;
}

std::string operator ""_white(const char *str, std::size_t)
{
	return std::string() + tlucanti::color::white + str + tlucanti::color::reset;
}

std::string operator ""_reset(const char *str, std::size_t)
{
	return std::string() + str + tlucanti::color::reset;
}
# endif
#endif
