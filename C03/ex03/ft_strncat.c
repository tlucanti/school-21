/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:36:31 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/16 11:36:33 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *dest_esp;

	dest_esp = dest;
	while (*dest++)
	{
	}
	dest--;
	while (nb--)
		*dest++ = *src++;
	return (dest_esp);
}
