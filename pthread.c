/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:46:29 by kostya            #+#    #+#             */
/*   Updated: 2021/10/18 20:37:57 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	*phil_routine(size_t philo_num)
{
	uintmax_t	time;
	t_data		*data;

	data = data_storage();
	while (data->eaten[philo_num] < data->eat_num && !data->stop)
	{
		time = ft_time() - data->pthread_start;
		if (time > data->death_time[philo_num])
			return (NULL);
		data->death_time[philo_num] = time + data->live_time;
		take_forks(philo_num, 1, time);
		mutex_print(time, philo_num, EATING_MESSAGE);
		usleep(data->eat_time);
		time = ft_time() - data->pthread_start;
		take_forks(philo_num, 0, time);
		++data->eaten[philo_num];
		if (data->stop)
			return (NULL);
		mutex_print(time, philo_num, SLEEP_MESSAGE);
		usleep(data->sleep_time);
		if (data->stop)
			return (NULL);
		mutex_print(ft_time() - data->pthread_start, philo_num, THINK_MESSAGE);
	}
	return (NULL);
}

void	*death_monitor(t_data *data)
{
	uintmax_t	time;
	uint		cnt;

	while (!data->stop)
	{
		cnt = 0;
		while (cnt < data->phil_num)
		{
			if (data->eaten[cnt] >= data->eat_num)
			{
				data->stop = 1;
				return (NULL);
			}
			time = ft_time() - data->pthread_start;
			if (time > data->death_time[cnt])
			{
				data->stop = 1;
				mutex_print(time, cnt, DEATH_MESSAGE);
				return (NULL);
			}
			++cnt;
		}
	}
	return (NULL);
}
