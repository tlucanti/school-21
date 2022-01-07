/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 00:11:07 by kostya            #+#    #+#             */
/*   Updated: 2022/01/07 16:07:29 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

#define __CONST const
#define PRIVATE_CONSTRUCTOR 0
#if __cplusplus > 199711L
# define __WUR [[nodiscard]]
#else
# define __WUR __attribute__((warn_unused_result))
#endif

namespace tlucanti
{
	class Fixed
	{
	public:
		Fixed();
		explicit Fixed(int val);
		explicit Fixed(float val);

		~Fixed();
		Fixed(__CONST Fixed &cpy);
		Fixed	&operator =(__CONST Fixed &cpy);

		__WUR bool	operator >(__CONST Fixed &other) __CONST;
		__WUR bool	operator <(__CONST Fixed &other) __CONST;
		__WUR bool	operator >=(__CONST Fixed &other) __CONST;
		__WUR bool	operator <=(__CONST Fixed &other) __CONST;
		__WUR bool	operator ==(__CONST Fixed &other) __CONST;
		__WUR bool	operator !=(__CONST Fixed &other) __CONST;

		__WUR Fixed	operator +(__CONST Fixed &other) __CONST;
		__WUR Fixed	operator -(__CONST Fixed &other) __CONST;
		__WUR Fixed	operator *(__CONST Fixed &other) __CONST;
		__WUR Fixed	operator /(__CONST Fixed &other) __CONST;

		__WUR Fixed	operator -() __CONST;	// -x
		Fixed	&operator ++();			// ++x
		Fixed operator ++(int);		// x++
		Fixed	&operator --();			// --x
		Fixed operator --(int);		// x--

		__WUR static __CONST Fixed	&min(__CONST Fixed &a, __CONST Fixed &b);
		__WUR static Fixed	&min(Fixed &a, Fixed &b);
		__WUR static __CONST Fixed	&max(__CONST Fixed &a, __CONST Fixed &b);
		__WUR static Fixed	&max(Fixed &a, Fixed &b);

		__WUR int	getRawBits() __CONST;
		void		setRawBits(int raw);

		__WUR float	toFloat() __CONST;
		__WUR int	toInt() __CONST;

	private:
		Fixed(int raw, int);
		int								_number;
		static __CONST unsigned short	_frac;
	};

	int round(float v);
}

std::ostream &operator <<(std::ostream &out, __CONST tlucanti::Fixed &fix);
