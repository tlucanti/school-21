/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issmth1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:45:30 by tlucanti          #+#    #+#             */
/*   Updated: 2020/11/16 12:45:30 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c__)
{
	return (c__ == ' ' || c__ == '\t' || c__ == '\n' ||
			c__ == '\v' || c__ == '\f' || c__ == '\r');
}

int		ft_isdigit(int c__)
{
	return (c__ >= '0' && c__ <= '9');
}

int		ft_isupper(int c__)
{
	return (c__ >= 'A' && c__ <= 'Z');
}

int		ft_islower(int c__)
{
	return (c__ >= 'a' && c__ <= 'z');
}

int		ft_isalpha(int c__)
{
	return (ft_islower(c__) || ft_isupper(c__));
}
