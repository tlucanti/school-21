/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 20:30:55 by droslyn           #+#    #+#             */
/*   Updated: 2020/08/29 20:38:02 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		ft_print_bad_num(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int		ft_check_num(char *str)
{
	int		len;
	char	*str_esp;

	str_esp = str;
	while (*str != '\0' && *str >= '0' && *str <= '9')
		str++;
	if (*str != '\0')
		return (ft_print_bad_num());
	check_zeros(str_esp);
	len = str_len(str_esp);
	if (len == 1)
	{
		if (request(str_esp))
			return (ft_print_error());
		return (0);
	}
	return (ft_number(str_esp, len));
}

void	check_zeros(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] != 48)
			return ;
	}
	str[1] = 0;
}
