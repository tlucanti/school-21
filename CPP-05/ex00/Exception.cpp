/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:13:26 by kostya            #+#    #+#             */
/*   Updated: 2022/01/16 11:14:39 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exception.hpp"

tlucanti::BureaucratException::BureaucratException(const std::string &message)
    : message(message) {}

const char *
tlucanti::BureaucratException::what() const noexcept
{
    return message.c_str();
}
