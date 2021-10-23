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
	t_data		*data;

	data = data_storage();
	data->pthread_start[philo_num] = ft_time();
	data->dt[philo_num] = data->live_time;
	while (data->eaten[philo_num] < data->eat_num && !check_stop(data))
	{
		data->dt[philo_num] = take_forks(philo_num, 1, data) + data->live_time;
		mutex_print(data->dt[philo_num] - data->live_time, philo_num,
			EATING_MESSAG);
		ft_usleep(data->eat_time);
		take_forks(philo_num, 0, data);
		++data->eaten[philo_num];
		if (check_stop(data))
			return (NULL);
		mutex_print(ft_time() - data->pthread_start[philo_num], philo_num,
			SLEEP_MESSAGE);
		ft_usleep(data->sleep_time);
		if (check_stop(data))
			return (NULL);
		mutex_print(ft_time() - data->pthread_start[philo_num], philo_num,
			THINK_MESSAGE);
	}
	return (NULL);
}

void	*death_monitor(t_data *data)
{
	uint		cnt;
	uint		all_eat;

	while (!check_stop(data) && all_eat < data->phil_num)
	{
		all_eat = 0;
		cnt = 0;
		while (cnt < data->phil_num)
		{
			all_eat += data->eaten[cnt] >= data->eat_num;
			if (data->eaten[cnt] >= data->eat_num && ++cnt)
				continue ;
			if (ft_time() - data->pthread_start[cnt] > data->dt[cnt])
			{
				pthread_mutex_lock(&data->stop_mutex);
				data->stop = 1;
				pthread_mutex_unlock(&data->stop_mutex);
				mutex_print(ft_time() - data->pthread_start[cnt], cnt,
					DEATH_MESSAGE);
				return (NULL);
			}
			++cnt;
		}
	}
	return (NULL);
}
