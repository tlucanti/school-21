/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:06:41 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/15 12:06:43 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** {IS_UPPER} = [65 : 90]
** {IS_LOWER} = [97 : 122]
** {IS_ALPHA} = IS_LOWER + IS_UPPER
** {IS_NUM} = [48 : 57]
** {IS_PRINTABLE} = [32 : 126]
** to upper -> +32
** to lower -> -32
*/

void	*up(char *str, int w_start, int w_end)
{
	if (str[w_start] >= 97 & str[w_start] <= 122)
	{
		str[w_start] += -32;
	}
	while (w_end - ++w_start)
	{
		if (str[w_start] >= 65 & str[w_start] <= 90)
		{
			str[w_start] += 32;
		}
	}
	return (str);
}

void	check_char(char c, int *word, int i, char *str)
{
	if ((c >= 65 & c <= 90) | (c >= 97 & c <= 122))
	{
		if (*word == -1)
			*word = i;
	}
	if (!((c >= 65 & c <= 90) | (c >= 97 & c <= 122)) & !(c >= 48 & c <= 57))
	{
		if (*word > -1)
			up(str, *word, i);
		*word = -1;
	}
	if (c >= 48 & c <= 57)
		*word = -2;
}

char	*ft_strcapitalize(char *str)
{
	int word;
	int i;

	word = -1;
	i = 0;
	while (str[i])
	{
		check_char(str[i], &word, i, str);
		i++;
	}
	if (word != -1)
		up(str, word, i + 1);
	return (str);
}
