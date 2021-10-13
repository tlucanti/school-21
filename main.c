/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:37:05 by kostya            #+#    #+#             */
/*   Updated: 2021/10/13 17:04:08 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

pthread_mutex_t stdout_mutex;

int	main(int argc, char *const *argv)
{
	t_data	*restrict data;

	pthread_mutex_init(&stdout_mutex, NULL);
	data = data_storage();
	if (argc < 5 || argc > 6 || parse(data, argv))
		return (printf("Bad arguments\n"));
	start(data);
	stop(data);
}

uint_fast8_t	parse(t_data *restrict data, char *const *argv)
{
	data->phil_num = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]) * 1000;
	data->eat_time = ft_atoi(argv[3]) * 1000;
	data->sleep_time = ft_atoi(argv[4]) * 1000;
	data->eat_num = ft_atoi(argv[5]);
	if ((int)data->phil_num <= 0 || (int)data->die_time <= 0
		|| (int)data->eat_time <= 0 || (int)data->sleep_time <= 0
		|| (int)data->eat_num)
		return (1);
	return (0);
}

uint_fast64_t	ft_time(void)
{
	static struct timeval	t_val;

	gettimeofday(&t_val, NULL);
	return (t_val.tv_sec * 1000000 + t_val.tv_usec);
}

void	start(t_data *restrict data)
{
	uint_fast32_t	i;
	uint_fast32_t	phil_num;
	pthread_t		thread;

	i = 0;
	phil_num = data->phil_num;
	data->pthread_start = ft_time();
	data->death_time = (uint_fast64_t *)malloc(sizeof(uint_fast32_t)
		* data->phil_num);
	pthread_mutex_init(&data->stdout_mutex, NULL);
	while (i < phil_num / 2)
		pthread_create(&thread, NULL, phil_routine, (void *)(size_t)((i++) * 2));
	i = 0;
	while (i < phil_num / 2 + phil_num % 2)
		pthread_create(&thread, NULL, phil_routine, (void *)(size_t)((i++) * 2 + 1));
}

void	*phil_routine(void *philo_num_ptr)
{
	uint_fast32_t	phil_num;
	uint_fast32_t	eaten;
	uint_fast64_t	pthread_start;
	t_data			*data;

	phil_num = (size_t)philo_num_ptr;
	mutex_print(ft_time(), phil_num, "created");
	eaten = 0;
	data = data_storage();
	pthread_start = data->pthread_start;
	while (eaten < data->eat_num && !data->stop)
	{
		take_forks(phil_num, 1, pthread_start);
		data->death_time[phil_num] = ft_time() + data->die_time;
		mutex_print(ft_time() - pthread_start, phil_num, "eating");
		usleep(data->eat_time);
		if (data->stop)
			return (NULL);
		++eaten;
		take_forks(phil_num, 0, pthread_start);
		usleep(data->sleep_time);
		if (data->stop)
			return (NULL);
		mutex_print(ft_time() - pthread_start, phil_num, "thinking");
	}
	return (NULL);
}

t_data	*data_storage(void)
{
	static t_data	*data = NULL;

	if (!data)
		data = malloc(sizeof(data));
	return (data);
}

void	stop(t_data *restrict data)
{
	free(data->death_time);
}

void	*death_monitor(__attribute__((unused)) void *_)
{
	t_data			*data;
	uint_fast32_t	phil_num;
	uint_fast32_t	cnt;

	data = data_storage();
	phil_num = data->phil_num;
	while (!data->stop)
	{
		cnt = 0;
		while (cnt < data->phil_num)
		{
			if (ft_time() > data->death_time[cnt])
			{
				data->stop = 1;
				mutex_print(ft_time() - data->pthread_start, phil_num, "died");
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	take_forks(uint_fast32_t phil_num, uint_fast8_t action, uint_fast64_t pthread_start)
{
	if (action)
	{
		mutex_print(ft_time() - pthread_start, phil_num, "taked left fork");
		mutex_print(ft_time() - pthread_start, phil_num, "taked right fork");
	}
	else
	{
		mutex_print(ft_time() - pthread_start, phil_num, "released left fork");
		mutex_print(ft_time() - pthread_start, phil_num, "released right fork");
	}
}

void	mutex_print(uint_fast64_t time, uint_fast32_t phil_num, const char *restrict message)
{
	// static pthread_mutex_t stdout_mutex = PTHREAD_MUTEX_INITIALIZER;
	// t_data *data = data_storage();

	pthread_mutex_lock(&stdout_mutex);
	printf("[%ld]: %s %ld\n", time, message, phil_num);
	pthread_mutex_unlock(&stdout_mutex);
}
