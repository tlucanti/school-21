/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:41:02 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/16 11:41:05 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	unsigned int n;

	n = 0;
	while (*str++)
		n++;
	return (n);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int n;

	n = 0;
	while (*dest++)
	{
		n++;
		size--;
	}
	dest--;
	while (--size)
	{
		*dest++ = *src++;
		n++;
	}
	*dest = '\0';
	return (n + str_len(src));
}
