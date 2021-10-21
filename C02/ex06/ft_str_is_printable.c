/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:55:27 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/15 11:55:31 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_diap(char *str, int a, int b)
{
	while (*str)
	{
		if (*str < a | *str > b)
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/*
** {IS_UPPER} = [65 : 90]
** {IS_LOWER} = [97 : 122]
** {IS_ALPHA} = IS_LOWER + IS_UPPER
** {IS_NUM} = [48 : 57]
** {IS_PRINTABLE} = [32 : 126]
*/

int	ft_str_is_printable(char *str)
{
	return (check_diap(str, 32, 126));
}
