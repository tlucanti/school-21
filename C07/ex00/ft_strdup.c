/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 22:05:16 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/21 22:05:20 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		str_len(char *str)
{
	int n;

	n = 0;
	while (*str++)
		n++;
	return (n);
}

char	*str_cpy_smart(char *dest, char *src)
{
	char *dest_esp;

	dest_esp = dest;
	if (dest == 0 || src == 0)
		return (0);
	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (dest_esp);
}

char	*ft_strdup(char *src)
{
	return (str_cpy_smart((char *)malloc(sizeof(char) *
		str_len(src) + 1), src));
}
