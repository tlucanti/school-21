/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 18:37:16 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/15 18:37:27 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	unsigned int n;

	n = 0;
	while (*str++)
	{
		n++;
	}
	return (n);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	char *src_esp;

	src_esp = src;
	while (--n && *src)
	{
		*dest++ = *src++;
	}
	while (n-- + 1)
	{
		*dest++ = '\0';
	}
	return (str_len(src_esp));
}
