/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:46:29 by kostya            #+#    #+#             */
/*   Updated: 2021/10/21 17:55:05 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	*phil_routine(size_t philo_num)
{
	uintmax_t	time;
	t_data		*data;

	data = data_storage();
	data->pthread_start[philo_num] = ft_time();
	while (data->eaten[philo_num] < data->eat_num && !data->stop)
	{
		time = take_forks(philo_num, 1);
		data->death_time[philo_num] = time + data->live_time;
		mutex_print(time, philo_num, EATING_MESSAG);
		ft_usleep(data->eat_time);
		take_forks(philo_num, 0);
		++data->eaten[philo_num];
		if (data->stop)
			return (NULL);
		mutex_print(time, philo_num, SLEEP_MESSAGE);
		ft_usleep(data->sleep_time);
		if (data->stop)
			return (NULL);
		mutex_print(ft_time() - data->pthread_start[philo_num], philo_num,
			THINK_MESSAGE);
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
			time = ft_time() - data->pthread_start[cnt];
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
