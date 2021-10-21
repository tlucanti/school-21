/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:37:05 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/30 18:37:06 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*reallol(char *str, char *str_append, int size)
{
	char	*new_str;
	char	*new_str_esp;
	char	*old_str_esp;
	int		i;
	int		str_size;

	str_size = str_len(str);
	old_str_esp = str;
	new_str = (char *)malloc(sizeof(char) * (str_size + size + 1));
	if (!new_str)
		return (0);
	new_str_esp = new_str;
	i = -1;
	while (++i < str_size)
		*new_str++ = *(str)++;
	i = -1;
	while (++i < size)
		*new_str++ = *str_append++;
	*new_str = 0;
	free(old_str_esp);
	return (new_str_esp);
}

int		str_len(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str++)
		i++;
	return (i);
}
