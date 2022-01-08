/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 00:11:07 by kostya            #+#    #+#             */
/*   Updated: 2022/01/08 15:47:19 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

namespace tlucanti
{
	int round(float v)
	{
		return (int)roundf(v);
	}
}

const char *true_false(bool f)
{
	return f ? "true" : "false";
}

int main()
{
	std::cout.precision(8);
	{
		std::cout << "-----------------\n";
		std::cout << "TEST EX00\n";
		std::cout << "-----------------\n\n";
		tlucanti::Fixed a; // Default
		std::cout << "a: (0) " << a.getRawBits() << std::endl;
		a.setRawBits(1234);
		std::cout << "a: (1234) " << a.getRawBits() << std::endl;
		tlucanti::Fixed b(a); // Copy
		std::cout << "b: (1234) " << b.getRawBits() << std::endl;
		b.setRawBits(2147483647);
		std::cout << "b: (2147483647) " << b.getRawBits() << std::endl;
		std::cout << "a: (1234) " << a.getRawBits() << std::endl;
		tlucanti::Fixed c; //Default
		c = a; // Assign
		std::cout << "c: (1234) " << c.getRawBits() << std::endl;
		b = a; // Assign
		std::cout << "b: (1234) " << b.getRawBits() << std::endl;
	}
	{
		std::cout << "-----------------\n";
		std::cout << "TEST EX01\n";
		std::cout << "-----------------\n\n";
		tlucanti::Fixed a(0); //Int
		std::cout << "a: (0) " << a.getRawBits() << std::endl;
		std::cout << "int(a): (0) " << a.toInt() << std::endl;
		tlucanti::Fixed b(123); //Int
		std::cout << "b: (31488) " << b.getRawBits() << std::endl;
		std::cout << "int(b): (123) " << b.toInt() << std::endl;
		tlucanti::Fixed c(0.f); // Float
		std::cout << "c: (0) " << c.getRawBits() << std::endl;
		std::cout << "float(a): (0) " << a.toFloat() << std::endl;
		std::cout << "float(b): (123.) " << b.toFloat() << std::endl;
		tlucanti::Fixed d(1234.5678f);
		std::cout << "d: (316049) " << d.getRawBits() << std::endl;
		std::cout << "int(d) (1234) " << d.toInt() << std::endl;
		std::cout << "float(d) (1234.56640625) " << d.toFloat() << std::endl;
		std::cout << a << std::endl; // 0
		std::cout << b << std::endl; // 123
		std::cout << c << std::endl; // 0
		std::cout << d << std::endl; // 1234.5664
	}
	{
		std::cout << "-----------------\n";
		std::cout << "TEST EX02\n";
		std::cout << "-----------------\n\n";
		tlucanti::Fixed a(-123);
		std::cout << a.toInt() << std::endl;	// -123
		std::cout << a << std::endl;			// -123
		tlucanti::Fixed b(-123.456f);		// -123.456
		std::cout << b << std::endl;
		tlucanti::Fixed c(123);
		tlucanti::Fixed d(3);
		std::cout << a + c << std::endl; // 0
		std::cout << c - d << std::endl; // 120
		std::cout << c * a << std::endl; // -15129
		std::cout << c / d << std::endl; // 41
		std::cout << ++d << std::endl;
		std::cout << --d << std::endl;
		d++;
		std::cout << d << std::endl;
		d--;
		std::cout << d << std::endl;
		std::cout << -d << std::endl;
		std::cout << true_false(c > b) << std::endl; // true
		std::cout << true_false(c < b) << std::endl; // false
		tlucanti::Fixed e(123.f);
		std::cout << true_false(c == e) << std::endl; // true
		std::cout << true_false(c != e) << std::endl; // false
		std::cout << tlucanti::Fixed::max(c, d) << std::endl; // 123
		std::cout << tlucanti::Fixed::min(c, d) << std::endl; // 3
	}
	{
		std::cout << "-----------------\n";
		std::cout << "TEST CONST\n";
		std::cout << "-----------------\n\n";
		const tlucanti::Fixed a;
		tlucanti::Fixed b(a);
		b = a;
		const tlucanti::Fixed c(b);
		const tlucanti::Fixed d(a);
		(void)d;
		std::cout << a.getRawBits() << a.toInt() << a.toFloat() << std::endl;
		std::cout << a << std::endl;
	}
	{
		// ANOTHER CONST TEST
		const tlucanti::Fixed a(-123);
		std::cout << a.toInt() << std::endl;	// -123
		std::cout << a << std::endl;			// -123
		const tlucanti::Fixed b(-123.456f);		// -123.456
		std::cout << b << std::endl;
		const tlucanti::Fixed c(123);
		const tlucanti::Fixed d(3);
		std::cout << a + c << std::endl; // 0
		std::cout << c - d << std::endl; // 120
		std::cout << c * a << std::endl; // -15129
		std::cout << c / d << std::endl; // 41
		std::cout << -d << std::endl;
		std::cout << true_false(c > b) << std::endl; // true
		std::cout << true_false(c < b) << std::endl; // false
		const tlucanti::Fixed e(123.f);
		std::cout << true_false(c == e) << std::endl; // true
		std::cout << true_false(c != e) << std::endl; // false
		std::cout << tlucanti::Fixed::max(c, d) << std::endl; // 123
		std::cout << tlucanti::Fixed::min(c, d) << std::endl; // 3
	}
	{
		std::cout << "-----------------\n";
		std::cout << "42TEST EX00\n";
		std::cout << "-----------------\n\n";
		tlucanti::Fixed a;
		tlucanti::Fixed b(a);
		tlucanti::Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
		a.setRawBits(1234567);
		std::cout << a.getRawBits() << std::endl;
	}
	{
		std::cout << "-----------------\n";
		std::cout << "42TEST EX01\n";
		std::cout << "-----------------\n\n";
		tlucanti::Fixed a;
		tlucanti::Fixed const b( 10 );
		tlucanti::Fixed const c( 42.42f );
		tlucanti::Fixed const d( b );
		a = tlucanti::Fixed( 1234.4321f );
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
		(void)d;
	}
	{
		std::cout << "-----------------\n";
		std::cout << "42TEST EX02\n";
		std::cout << "-----------------\n\n";
		tlucanti::Fixed a;
		tlucanti::Fixed const b(tlucanti::Fixed(5.05f) * tlucanti::Fixed(2));
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << tlucanti::Fixed::max(a, b) << std::endl;
	}
	return 0;
}
