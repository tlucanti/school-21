/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:26:39 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/26 16:26:40 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	add(int a__, int b__, int *s__)
{
	(void)*s__;
	return (a__ + b__);
}

int	sub(int a__, int b__, int *s__)
{
	(void)*s__;
	return (a__ - b__);
}

int	div(int a__, int b__, int *s__)
{
	if (b__ == 0)
	{
		write(1, "Stop : division by zero", 23);
		*s__ = 0;
		return (0);
	}
	return (a__ / b__);
}

int	mul(int a__, int b__, int *s__)
{
	(void)*s__;
	return (a__ * b__);
}

int	mod(int a__, int b__, int *s__)
{
	if (b__ == 0)
	{
		write(1, "Stop : modulo by zero", 21);
		*s__ = 0;
		return (0);
	}
	return (a__ % b__);
}
