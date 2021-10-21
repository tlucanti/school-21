/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:20:13 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/26 16:20:17 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*start(char *str, int *sign)
{
	while ((*str == ' ' || *str == '\t' || *str == '\b'
		|| *str == '\r' || *str == '\n' || *str == '\v') && *str)
		str++;
	while (*str)
	{
		if (*str == '-')
			*sign *= -1;
		else if (*str == '+')
			*sign *= 1;
		else
			break ;
		str++;
	}
	return (str);
}

int		atoi(char *str)
{
	int sign;
	int num;

	sign = 1;
	num = 0;
	str = start(str, &sign);
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
			num = num * 10 + *str - 48;
		else
			break ;
		str++;
	}
	return (num * sign);
}
