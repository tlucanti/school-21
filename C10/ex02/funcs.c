/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:30:53 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/25 17:30:55 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int		str2int(char *str)
{
	int num;

	num = 0;
	while (*str)
	{
		num = num * 10 + (*str++ - 48);
	}
	return (num);
}

void	print_err(char *str, int new_line)
{
	while (*str)
		write(2, str++, 1);
	if (new_line)
		write(2, "\n", 1);
}

void	err(int errcode, char *path)
{
	print_err("ft_tail: ", 0);
	print_err(path, 0);
	print_err(": ", 0);
	print_err(strerror(errcode), 1);
}
