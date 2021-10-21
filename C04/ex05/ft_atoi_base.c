/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:10:30 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/18 12:11:02 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		in_str(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_atoi_b(char *str, char *base, int *sign)
{
	char *num_esp;
	char *str_esp;

	str_esp = str;
	num_esp = str;
	while (*str == ' ' && *str)
		str++;
	while (*str)
	{
		if (*str == '-')
			*sign *= -1;
		else if (*str == '+')
			*sign *= 1;
		else if (in_str(*str, base) + 1)
			*str_esp++ = *str;
		else
		{
			*str_esp++ = '\0';
			break ;
		}
		str++;
	}
	*str_esp = '\0';
	return (num_esp);
}

int		check_str_atoi(char *str, int *bas)
{
	char hash[256] = {0};

	while (*str)
	{
		if (*str == '-' || *str == '+')
			return (0);
		hash[(int)*str]++;
		if (hash[(int)*str] == 2)
			return (0);
		str++;
		(*bas)++;
	}
	if (*bas <= 1)
		return (0);
	return (1);
}

int		power(int a, int n)
{
	int s;

	s = 1;
	while (n--)
	{
		s *= a;
	}
	return (s);
}

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int digits;
	int base_number;
	int i;
	int bus;

	sign = 1;
	bus = 0;
	if (!check_str_atoi(base, &bus))
		return (0);
	str = ft_atoi_b(str, base, &sign);
	digits = 0;
	base_number = 0;
	i = 0;
	while (str[i++])
		digits++;
	i = 0;
	while (i < digits)
	{
		base_number += power(bus, i) * (in_str(str[digits - i - 1], base));
		i++;
	}
	return (base_number * sign);
}
