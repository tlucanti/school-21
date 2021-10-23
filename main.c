/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:37:05 by kostya            #+#    #+#             */
/*   Updated: 2021/10/22 14:55:12 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char *const *argv)
{
	t_data	*restrict	data;
	int					error;

	data = data_storage();
	if ((argc != 6 && argc != 5) || parse(data, argv))
		return (printf("Bad arguments\n"));
	error = start(data);
	if (error == -1)
		return (write(1, ERROR"[FAIL] "WARNING "malloc error"RESET "\n", 0x26));
	stop(data);
	if (error)
		return (write(1, ERROR"[FAIL] "WARNING "pthread or mutex cannot be "
				"created" RESET "\n", 0x3c));
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

int	start(t_data *restrict data)
{
	uint	i;
	int		pthread_error;

	if (ft_malloc_(data))
		return (-1);
	memset(data->dt, 0xff, data->phil_num * sizeof(uintmax_t));
	memset(data->eaten, 0x00, data->phil_num * sizeof(uint));
	i = 0;
	pthread_error = pthread_mutex_init(&data->stop_mutex, NULL);
	while (i < data->phil_num)
		pthread_error |= pthread_mutex_init(data->forks + i++, NULL);
	pthread_error |= pthread_create_loop(0, data);
	ft_usleep(data->eat_time / 2);
	pthread_error |= pthread_create_loop(1, data);
	pthread_error |= pthread_create(data->pthreads + data->phil_num, NULL,
			(void *(*)(void *))death_monitor, data);
	return (pthread_error);
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
	pthread_mutex_destroy(&data->stop_mutex);
	ft_free_(data);
}

int	pthread_create_loop(uint start, const t_data *restrict data)
{
	int	pthread_error;

	pthread_error = 0;
	while (start < data->phil_num)
	{
		pthread_error |= pthread_create(data->pthreads + start, NULL,
				(void *(*)(void *))phil_routine, (VOID_PTR)start);
		ft_usleep(50);
		start += 2;
	}
	return (pthread_error);
}
