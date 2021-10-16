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

uintmax_t	ft_time(void)
{
	struct timeval	t_val;

	gettimeofday(&t_val, NULL);
	return (t_val.tv_sec * 1000000 + t_val.tv_usec);
}

t_data	*data_storage(void)
{
	static t_data	data;

	return (&data);
}

void	start(t_data *restrict data)
{
	uint	i;

	data->death_time = (uintmax_t *)malloc(sizeof(uintmax_t) * data->phil_num);
	data->pthreads = (pthread_t *)malloc(sizeof(pthread_t) * (data->phil_num + 1));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_lock) * data->phil_num);
	data->eaten = (uint *)malloc(sizeof(uint) * data->phil_num);
	memset(data->death_time, 0xff, data->phil_num * sizeof(uintmax_t));
	i = 0;
	data->pthread_start = ft_time();
	while (i < data->phil_num / 2)
	{
		pthread_create(data->pthreads + i * 2, NULL, phil_routine, (VOID_PTR)(i * 2));
		++i;
	}
	i = 0;
	while (i < data->phil_num / 2 + data->phil_num % 2)
	{
		pthread_create(data->pthreads + i * 2 + 1, NULL, phil_routine, (VOID_PTR)(i * 2 + 1));
		++i;
	}
	pthread_create(data->pthreads + data->phil_num, NULL, death_monitor, NULL);
}

void	*phil_routine(void *philo_num_ptr)
{
	uintmax_t	time;
	t_data		*data;
	uint        philo_num;

	philo_num = (uint)(size_t)philo_num_ptr;
	mutex_print(0, philo_num, "created", 7);
	data = data_storage();
	while (data->eaten[philo_num] < data->eat_num && !data->stop)
	{
		time = ft_time() - data->pthread_start;
		if (time > data->death_time[philo_num])
			return (NULL);
		data->death_time[philo_num] = time + data->live_time;
		take_forks(philo_num, 1, time);
		mutex_print(time, philo_num, "eating", 6);
		usleep(data->eat_time);
		time = ft_time() - data->pthread_start;
		take_forks(philo_num, 0, time);
		++data->eaten[philo_num];
		if (data->stop)
			return (NULL);
		mutex_print(time, philo_num, "sleeping", 8);
		usleep(data->sleep_time);
		if (data->stop)
			return (NULL);
		mutex_print(ft_time() - data->pthread_start, philo_num, "thinking", 8);
	}
	return (NULL);
}

void	stop(t_data *restrict data)
{
	uint	i;

	i = data->phil_num + 1;
	while (i > 0)
		pthread_join(data->pthreads[--i], NULL);
	free(data->death_time);
	free(data->pthreads);
	free(data->forks);
	free(data->eaten);
}

void	*death_monitor(__attribute__((unused)) void *_)
{
	t_data		*data;
	uint		cnt;
	uintmax_t	time;

	data = data_storage();
	while (!data->stop)
	{
		cnt = 0;
		while (cnt < data->phil_num)
		{
			time = ft_time() - data->pthread_start;
			if (time > data->death_time[cnt])
			{
				data->stop = 1;
				mutex_print(time, cnt, "died", 4);
				return (NULL);
			}
			++cnt;
		}
	}
	return (NULL);
}

void	take_forks(uint phil_num, unsigned char action, uintmax_t time)
{
	t_data  *restrict   data;

	data = data_storage();
	if (action)
	{
		pthread_mutex_lock(data->forks + phil_num);
		mutex_print(time, phil_num, "has taken left fork", 19);
		pthread_mutex_lock(data->forks + phil_num + 1);
		mutex_print(time, phil_num, "has taken right fork", 21);
	}
	else
	{
		pthread_mutex_lock(data->forks + phil_num);
		pthread_mutex_lock(data->forks + phil_num + 1);
	}
}

void	mutex_print(uintmax_t time, uint philo_num, const char *restrict message, unsigned char message_size)
{
	static pthread_mutex_t	stdout_mutex = PTHREAD_MUTEX_INITIALIZER;
	uint					_;

	pthread_mutex_lock(&stdout_mutex);
	printf("[%08ld]: %s %d\n", time, message, philo_num); (void)message_size;
	// _ = write(1, "[", 1);
	// ft_putunbr((uint)time, ']');
	// _ = write(1, ": ", 2);
	// ft_putunbr(philo_num + 1, ' ');
	// _ = write(1, message, message_size);
	// write(1, "\n", 1);
	pthread_mutex_unlock(&stdout_mutex);
	(void)_;
}

void	ft_putunbr(uint n, unsigned char last)
{
	static unsigned char	ans[9];

	ans[8] = last;
	ans[7] = n % 10 + 48;
	n /= 10;
	ans[6] = n % 10 + 48;
	n /= 10;
	ans[5] = n % 10 + 48;
	n /= 10;
	ans[4] = n % 10 + 48;
	n /= 10;
	ans[3] = n % 10 + 48;
	n /= 10;
	ans[2] = n % 10 + 48;
	n /= 10;
	ans[1] = n % 10 + 48;
	n /= 10;
	ans[0] = n % 10 + 48;
	write(1, ans, 10);
}
