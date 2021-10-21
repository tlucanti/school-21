/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:56:38 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/15 11:56:40 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*cesar(char *str, int a, int b, int s)
{
	char *ans;

	ans = str;
	while (*str)
	{
		if (*str >= a & *str <= b)
		{
			*str += s;
		}
		str++;
	}
	return (ans);
}

/*
** {IS_UPPER} = [65 : 90]
** {IS_LOWER} = [97 : 122]
** {IS_ALPHA} = IS_LOWER + IS_UPPER
** {IS_NUM} = [48 : 57]
** {IS_PRINTABLE} = [32 : 126]
** to upper -> +32
** to lower -> -32
*/

char	*ft_strupcase(char *str)
{
	return (cesar(str, 97, 122, -32));
}
