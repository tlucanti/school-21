/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 00:11:07 by kostya            #+#    #+#             */
/*   Updated: 2022/01/08 16:49:27 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#if __cplusplus > 199711L
# define FixedPrivateConstructor(raw) {raw, 0}
#else
# define FixedPrivateConstructor(raw) tlucanti::Fixed(raw, 0)
#endif

__CONST unsigned short tlucanti::Fixed::_frac = 8;

tlucanti::Fixed::Fixed()
	: _number(0)
{
	std::cout << "Default constructor\n";
}

tlucanti::Fixed::Fixed(int raw, int)
	: _number(raw) {}

tlucanti::Fixed::Fixed(int val)
{
	std::cout << "Int constructor\n";
	_number = val << _frac;
}

tlucanti::Fixed::Fixed(float val)
{
	std::cout << "Float constructor\n";
	_number = (int)tlucanti::round(val * (float)(1 << _frac));
}

tlucanti::Fixed::~Fixed()
{
	std::cout << "Destructor\n";
}

tlucanti::Fixed::Fixed(__CONST Fixed &cpy)
	: _number(cpy._number)
{
	std::cout << "Copy constructor\n";
}

tlucanti::Fixed	&
tlucanti::Fixed::operator =(__CONST Fixed &cpy)
{
	std::cout << "Assignation operator\n";
	_number = cpy._number;
	return *this;
}

__WUR bool
tlucanti::Fixed::operator >(__CONST Fixed &other) __CONST
{
	return _number > other._number;
}

__WUR bool
tlucanti::Fixed::operator <(__CONST tlucanti::Fixed &other) __CONST
{
	return _number < other._number;
}

__WUR bool
tlucanti::Fixed::operator >=(__CONST tlucanti::Fixed &other) __CONST
{
	return _number >= other._number;
}

__WUR bool
tlucanti::Fixed::operator <=(__CONST tlucanti::Fixed &other) __CONST
{
	return _number <= other._number;
}

__WUR bool
tlucanti::Fixed::operator ==(__CONST tlucanti::Fixed &other) __CONST
{
	return _number == other._number;
}

__WUR bool
tlucanti::Fixed::operator !=(__CONST tlucanti::Fixed &other) __CONST
{
	return _number != other._number;
}

__WUR tlucanti::Fixed
tlucanti::Fixed::operator +(__CONST tlucanti::Fixed &other) __CONST
{
	return FixedPrivateConstructor(_number + other._number);
}

__WUR tlucanti::Fixed
tlucanti::Fixed::operator -(__CONST tlucanti::Fixed &other) __CONST
{
	return FixedPrivateConstructor(_number - other._number);
}

__WUR tlucanti::Fixed
tlucanti::Fixed::operator *(__CONST tlucanti::Fixed &other) __CONST
{
	return Fixed(toFloat() * other.toFloat());
}

__WUR tlucanti::Fixed
tlucanti::Fixed::operator /(__CONST tlucanti::Fixed &other) __CONST
{
	return Fixed(toFloat() / other.toFloat());
}

__WUR tlucanti::Fixed
tlucanti::Fixed::operator -() __CONST
{
	return FixedPrivateConstructor(-_number);
}

__WUR tlucanti::Fixed &
tlucanti::Fixed::operator ++()
{
	++_number;
	return *this;
}

__WUR tlucanti::Fixed
tlucanti::Fixed::operator ++(int)
{
	return FixedPrivateConstructor(_number++);
}

__WUR tlucanti::Fixed &
tlucanti::Fixed::operator --()
{
	--_number;
	return *this;
}

__WUR tlucanti::Fixed
tlucanti::Fixed::operator --(int)
{
	return FixedPrivateConstructor(_number--);
}

int
tlucanti::Fixed::getRawBits() __CONST
{
	std::cout << "getRawBits\n";
	return _number;
}

void
tlucanti::Fixed::setRawBits(int __CONST raw)
{
	std::cout << "setRawBits\n";
	_number = raw;
}

__WUR float
tlucanti::Fixed::toFloat() __CONST
{
	return (float)_number / (float)(1 << _frac);
}

__WUR int
tlucanti::Fixed::toInt() __CONST
{
	return _number >> _frac;
}

__WUR const tlucanti::Fixed &
tlucanti::Fixed::min(__CONST tlucanti::Fixed &a, __CONST tlucanti::Fixed &b)
{
	return a > b ? b : a;
}

__WUR tlucanti::Fixed &
tlucanti::Fixed::min(tlucanti::Fixed &a, tlucanti::Fixed &b)
{
	return a > b ? b : a;
}

__WUR const tlucanti::Fixed &
tlucanti::Fixed::max(__CONST tlucanti::Fixed &a, __CONST tlucanti::Fixed &b)
{
	return a > b ? a : b;
}

__WUR tlucanti::Fixed &
tlucanti::Fixed::max(tlucanti::Fixed &a, tlucanti::Fixed &b)
{
	return a > b ? a : b;
}

std::ostream &
operator <<(std::ostream &out, __CONST tlucanti::Fixed &fix)
{
	out << fix.toFloat();
	return out;
}
