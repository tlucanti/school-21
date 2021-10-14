/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:37:05 by kostya            #+#    #+#             */
/*   Updated: 2021/10/13 23:45:29 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char *const *argv)
{
	t_data	*restrict data;

	if ((argc != 6 && argc != 5) || parse(data, argv))
		return (printf("Bad arguments\n"));
	start(data);
	stop(data);
}

unsigned char	parse(t_data *restrict data, char *const *argv)
{
	data->phil_num = ft_atoi(argv[1]);
	data->live_time = ft_atoi(argv[2]) * 1000;
	data->eat_time = ft_atoi(argv[3]) * 1000;
	data->sleep_time = ft_atoi(argv[4]) * 1000;
	if (argv[5] == NULL)
		data->eat_num = ft_atoi(argv[5]);
	else
		data->eat_num = -1;
	data->stop = 0;
	if ((int)data->phil_num <= 0 || (int)data->live_time <= 0
		|| (int)data->eat_time <= 0 || (int)data->sleep_time <= 0
		|| data->eat_num == 0)
		return (1);
	return (0);
}

uintmax_t	ft_time(void)
{
	struct timeval	t_val;

	gettimeofday(&t_val, NULL);
	return (t_val.tv_sec * 1000000 + t_val.tv_usec);
}

void	start(t_data *restrict data)
{
	uint	i;
	uint	phil_num;

	phil_num = data->phil_num;
	data->death_time = (uintmax_t *)malloc(sizeof(uintmax_t) * phil_num);
	data->pthreads = (pthread_t *)malloc(sizeof(pthread_t) * (phil_num + 1));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_lock * phil_num));
	data->eaten = (uint *)malloc(sizeof(uint) * phil_num);
	memset(data->death_time, 0xff);
	i = 0;
	data->pthread_start = ft_time();
	while (i < phil_num / 2)
	{
		pthread_create(data->pthreads + i * 2, NULL, phil_routine, (size_t)(i * 2));
		++i;
	}
	i = 0;
	while (i < phil_num / 2 + phil_num % 2)
	{
		pthread_create(data->pthreads + i * 2 + 1, NULL, phil_routine, (size_t)(i * 2 + 1));
		++i;
	}
	pthread_create(data->pthreads + phil_num, NULL, death_monitor, NULL);
}

void	*phil_routine(void *philo_num_ptr)
{
	uint	phil_num;
	uint	eaten;
	uintmax_t	time;
	uintmax_t	pthread_start;
	t_data			*data;

	phil_num = (size_t)philo_num_ptr;
	eaten = 0;
	data = data_storage();
	pthread_start = data->pthread_start;
	mutex_print(pthread_start, phil_num, "created");
	while (eaten < data->eat_num && !data->stop)
	{
		time = ft_time() - pthread_start;
		if (time > data->death_time[phil_num])
			return (NULL);
		data->death_time[phil_num] = time + data->live_time;
		mutex_print(data->death_time[phil_num], phil_num, "will die");
		take_forks(phil_num, 1, time);
		mutex_print(time, phil_num, "eating");
		usleep(data->eat_time);
		time = ft_time() - pthread_start;
		take_forks(phil_num, 0, time);
		++eaten;
		if (data->stop)
			return (NULL);
		mutex_print(time, phil_num, "sleeping");
		usleep(data->sleep_time);
		if (data->stop)
			return (NULL);
		mutex_print(ft_time() - pthread_start, phil_num, "thinking");
	}
	return (NULL);
}

void	stop(t_data *restrict data)
{
	uint	phil_num;

	phil_num = data->phil_num;
	pthread_join(data->pthreads[phil_num], NULL);
	while (phil_num--)
		pthread_join(data->pthreads[phil_num], NULL);
	free(data->death_time);
	free(data->pthreads);
}

void	*death_monitor(__attribute__((unused)) void *_)
{
	t_data			*data;
	uint	phil_num;
	uint	cnt;
	uintmax_t	time;

	data = data_storage();
	phil_num = data->phil_num;
	while (!data->stop)
	{
		cnt = 0;
		while (cnt < phil_num)
		{
			time = ft_time() - data->pthread_start;
			if (time > data->death_time[cnt])
			{
				data->stop = 1;
				mutex_print(data->death_time[cnt], cnt, "need");
				mutex_print(time, cnt, "died");
				return (NULL);
			}
			++cnt;
		}
	}
	return (NULL);
}

void	take_forks(__attribute__((unused)) uint phil_num, __attribute__((unused)) unsigned char action, __attribute__((unused)) uintmax_t time)
{
//	if (action)
//	{
		// mutex_print(time, phil_num, "taked left fork");
		// mutex_print(time, phil_num, "taked right fork");
//	}
//	else
//	{
		// mutex_print(time, phil_num, "released left fork");
		// mutex_print(time, phil_num, "released right fork");
//	}
}

void	mutex_print(uintmax_t time, uint phil_num, const char *restrict message)
{
	static pthread_mutex_t stdout_mutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&stdout_mutex);
	printf("[%08ld]: %s %d\n", time, message, phil_num);
	pthread_mutex_unlock(&stdout_mutex);
}
