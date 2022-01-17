/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:42:09 by kostya            #+#    #+#             */
/*   Updated: 2022/01/18 00:58:01 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

tlucanti::Converter::Converter(const char *_str)
{
	str = _str;
	str.erase(str.begin(), find_if_not(str.begin(), str.end(), std::isspace));
	str.erase(find_if_not(str.rbegin(), str.rend(), std::isspace).base(), str.end());
	char prelast = str[str.size() - 2];
	char last = str[str.size() - 1];
	if (last == 'f' and str.size() > 1 and (std::isdigit(prelast) or prelast == '.'))
		str.erase(prev(str.end()));
}

tlucanti::Converter::operator char() const
{
	try { return _char_ss_check<char>(); } catch(std::invalid_argument &exc) {}
	try { return _char_ss_check<int>(); } catch(std::invalid_argument &exc) {}
	try { return _char_ss_check<float>(); } catch(std::invalid_argument &exc) {}
	try { return _char_ss_check<double>(); } catch(std::invalid_argument &exc){}
	throw ConvertationError("impossible");
}

tlucanti::Converter::operator int() const
{
	try { return _int_ss_check<int>(); } catch(std::invalid_argument &exc) {}
	try { return _int_ss_check<float>(); } catch(std::invalid_argument &exc) {}
	try { return _int_ss_check<double>(); } catch(std::invalid_argument &exc) {}
	throw ConvertationError("impossible");
}

tlucanti::Converter::operator float() const
{
	return _float_ss_check<float>();
}

tlucanti::Converter::operator double() const
{
	return _float_ss_check<double>();
}

