/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:33:51 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/15 11:33:53 by tlucanti         ###   ########.fr       */
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

int	ft_str_is_numeric(char *str)
{
	return (check_diap(str, 48, 57));
}
