/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:45:27 by kostya            #+#    #+#             */
/*   Updated: 2021/10/17 18:25:02 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_putunbr(char *dest, uint n)
{
	dest[7] = n % 10 + 48;
	n /= 10;
	dest[6] = n % 10 + 48;
	n /= 10;
	dest[5] = n % 10 + 48;
	n /= 10;
	dest[4] = n % 10 + 48;
	n /= 10;
	dest[3] = n % 10 + 48;
	n /= 10;
	dest[2] = n % 10 + 48;
	n /= 10;
	dest[1] = n % 10 + 48;
	n /= 10;
	dest[0] = n % 10 + 48;
}

uintmax_t	ft_time(void)
{
	static struct timeval	t_val;

	gettimeofday(&t_val, NULL);
	return (t_val.tv_sec * 1000000 + t_val.tv_usec);
}

t_data	*data_storage(void)
{
	static t_data	data;

	return (&data);
}
