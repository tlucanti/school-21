/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:19:22 by kostya            #+#    #+#             */
/*   Updated: 2021/10/22 14:24:28 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	ft_malloc_(t_data *restrict data)
{
	data->dt = (uintmax_t *)malloc(sizeof(uintmax_t) * data->phil_num);
	data->pthreads = (pthread_t *)malloc(sizeof(pthread_t) * (data->phil_num
				+ 1));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->phil_num);
	data->eaten = (uint *)malloc(sizeof(uint) * data->phil_num);
	data->pthread_start = (uintmax_t *)malloc(sizeof(uintmax_t)
			* data->phil_num);
	if ((uintmax_t)data->dt & (uintmax_t)data->pthreads & (uintmax_t)
		data->forks & (uintmax_t)data->eaten & (uintmax_t)data->pthread_start)
		return (0);
	ft_free_(data);
	return (1);
}

void	ft_free_(t_data *restrict data)
{
	free(data->pthreads);
	free(data->pthread_start);
	free(data->dt);
	free(data->forks);
	free(data->eaten);
}

int	check_stop(t_data *restrict data)
{
	int	ret;

	pthread_mutex_lock(&data->stop_mutex);
	ret = data->stop;
	pthread_mutex_unlock(&data->stop_mutex);
	return (ret);
}
