/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:35:15 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/16 11:35:25 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char *dest_esp;

	dest_esp = dest;
	while (*dest++)
	{
	}
	dest--;
	while (*src)
		*dest++ = *src++;
	return (dest_esp);
}
