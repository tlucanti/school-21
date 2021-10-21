/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:49:39 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/25 17:49:41 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	print_err(char *str, int newline)
{
	while (*str)
		write(2, str++, 1);
	if (newline)
		write(2, "\n", 1);
}

int		err(int errcode, char *path)
{
	print_str("ft_hexdunp: ", 0);
	print_str(path, 0);
	print_str(": ", 0);
	print_str(strerror(errcode), 1);
	return (0);
}
