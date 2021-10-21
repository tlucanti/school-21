/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:38:50 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/16 11:39:33 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*to_find_esp;
	char	*iter_esp;
	int		n;

	to_find_esp = to_find;
	iter_esp = str;
	n = 0;
	while (*str && *iter_esp)
	{
		while (*str++ == *to_find++ && ++n)
		{
			if (!*to_find)
				return (str - n);
		}
		n = 0;
		to_find = to_find_esp;
		str = ++iter_esp;
	}
	return (0);
}
