/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:41:54 by tlucanti          #+#    #+#             */
/*   Updated: 2021/10/17 13:48:12 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

static long long	ft_atol(const char *str);
int					ft_isspace(int __c);
int					ft_isdigit(int __c);

int	ft_atoi(const char *str)
{
	return ((int)ft_atol(str));
}

static long long	ft_atol(const char *str)
{
	long long	ans;
	long long	sign;

	if (str == NULL)
		return (0);
	ans = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		ans = ans * 10 + (*str++ - 48);
	return (ans * sign);
}

inline int	ft_isspace(int __c)
{
	return (__c == ' ' || __c == '\t' || __c == '\n'
		|| __c == '\v' || __c == '\f' || __c == '\r');
}

inline int	ft_isdigit(int __c)
{
	return (__c >= '0' && __c <= '9');
}
