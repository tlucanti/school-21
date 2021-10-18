/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:37:05 by kostya            #+#    #+#             */
/*   Updated: 2021/10/18 18:05:05 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char *const *argv)
{
	t_data	*restrict	data;

	data = data_storage();
	if ((argc != 6 && argc != 5) || parse(data, argv))
		return (printf("Bad arguments\n"));
	start(data);
	stop(data);
}

unsigned char	parse(t_data *restrict data, char *const *argv)
{
	data->stop = 0;
	data->phil_num = ft_atoi(argv[1]);
	data->live_time = ft_atoi(argv[2]) * 1000;
	data->eat_time = ft_atoi(argv[3]) * 1000;
	data->sleep_time = ft_atoi(argv[4]) * 1000;
	if (argv[5] != NULL)
	{
		data->eat_num = ft_atoi(argv[5]);
		if ((int)data->phil_num <= 0 || (int)data->live_time <= 0
			|| (int)data->eat_time <= 0 || (int)data->sleep_time <= 0
			|| data->eat_num <= 0)
			return (1);
		else
			return (0);
	}
	data->eat_num = -1;
	if ((int)data->phil_num <= 0 || (int)data->live_time <= 0
		|| (int)data->eat_time <= 0 || (int)data->sleep_time <= 0)
		return (1);
	return (0);
}

void	start(t_data *restrict data)
{
	uint	i;

	data->death_time = (uintmax_t *)malloc(sizeof(uintmax_t) * data->phil_num);
	data->pthreads = (pthread_t *)malloc(sizeof(pthread_t) * (data->phil_num
				+ 1));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->phil_num);
	data->eaten = (uint *)malloc(sizeof(uint) * data->phil_num);
	memset(data->death_time, 0xff, data->phil_num * sizeof(uintmax_t));
	i = 0;
	while (i < data->phil_num)
		pthread_mutex_init(data->forks + i++, NULL);
	data->pthread_start = ft_time();
	while (i++ < data->phil_num / 2)
		pthread_create(data->pthreads + (i - 1) * 2, NULL, (void *(*)(void *))
			phil_routine, (VOID_PTR)((i - 1) * 2));
	i = 0;
	while (i++ < data->phil_num / 2 + data->phil_num % 2)
		pthread_create(data->pthreads + (i - 1) * 2 + 1, NULL,
			(void *(*)(void *))phil_routine, (VOID_PTR)((i - 1) * 2 + 1));
	pthread_create(data->pthreads + data->phil_num, NULL, (void *(*)(void *))
		death_monitor, data);
}

void	stop(t_data *restrict data)
{
	uint	i;

	i = 0;
	while (i < data->phil_num)
	{
		pthread_join(data->pthreads[i], NULL);
		pthread_mutex_destroy(data->forks + i);
		++i;
	}
	pthread_join(data->pthreads[data->phil_num], NULL);
	free(data->death_time);
	free(data->pthreads);
	free(data->forks);
	free(data->eaten);
}
