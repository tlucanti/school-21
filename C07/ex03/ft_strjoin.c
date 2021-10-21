/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 22:07:55 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/21 22:07:57 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_len_j(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*str_append(char *dest, char *src)
{
	char *strtmp;
	char *strtmpesp;

	strtmp = (char *)malloc(sizeof(char) *
		(str_len_j(dest) + str_len_j(src) + 1));
	if (strtmp == 0)
		return (0);
	strtmpesp = strtmp;
	while (*dest)
		*strtmp++ = *dest++;
	while (*src)
		*strtmp++ = *src++;
	*strtmp = 0;
	return (strtmpesp);
}

char	*str_cpy_smart_j(char *dest, char *src)
{
	if (dest == 0 || src == 0)
		return (0);
	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (dest);
}

char	*str_join(char *str1, char *sep, char *str2)
{
	char *strtmp;

	strtmp = (char *)malloc(sizeof(char) * (str_len_j(str1) + 1));
	if (strtmp == 0)
		return (0);
	str_cpy_smart_j(strtmp, str1);
	strtmp = str_append(strtmp, sep);
	return (str_append(strtmp, str2));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *strtmp;

	strtmp = (char *)malloc(sizeof(char));
	strtmp[0] = 0;
	if (size == 0 || strtmp == 0)
		return (strtmp);
	strtmp = str_append(strtmp, *strs++);
	if (strtmp == 0)
		return (0);
	while (--size)
	{
		strtmp = str_join(strtmp, sep, *strs++);
		if (strtmp == 0)
			return (0);
	}
	return (strtmp);
}
