/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:47:17 by kostya            #+#    #+#             */
/*   Updated: 2021/10/17 19:02:47 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	take_forks(uint phil_num, unsigned char action, uintmax_t time)
{
	static t_data	*restrict	data = NULL;

	if (!data)
		data = data_storage();
	if (action)
	{
		pthread_mutex_lock(data->forks + phil_num);
		mutex_print(time, phil_num, LFORK_MESSAGE);
		pthread_mutex_lock(data->forks + (phil_num + 1) % data->phil_num);
		mutex_print(time, phil_num, RFORK_MESSAGE);
	}
	else
	{
		pthread_mutex_unlock(data->forks + phil_num);
		pthread_mutex_unlock(data->forks + (phil_num + 1) % data->phil_num);
	}
}

void	mutex_print(uintmax_t time, uint philo_num,
			const uintmax_t *restrict message)
/*
** copying numbers (time and philosopher id) to static patternt string
** then copying message (of length 0x18 = 24) to center of pattern string
** then locking output stream mutex, and print whole message by single syscall
** (of length 0x30 = 48: 0x15 = 21 symbols for two numbers, 0x18 for message,
** 0x1 = 1 for `\n` and addition - 0x2 = 2 spaces for alignment: 0x18 + 0x15 +
** 0x1 + 0x2 = 0x30 = 48 = 0x8 * 0x6)
*/
{
	static pthread_mutex_t	stdout_mutex = PTHREAD_MUTEX_INITIALIZER;
	static char				pattern[] = "[00000000]: 00000000 @@@@@@@@@@@@@@@@@@@@@@@@  \n";
	uint					_;

	ft_putunbr(pattern + 1, (uint)time);
	ft_putunbr(pattern + 12, philo_num + 1);
	*(unsigned long long *)(pattern + 0x15) = message[0];
	*(unsigned long long *)(pattern + 0x1d) = message[1];
	*(unsigned long long *)(pattern + 0x25) = message[2];
	pthread_mutex_lock(&stdout_mutex);
	// printf("[%08d]: %8d %s\n", (uint)time, philo_num, (char *)message);
	_ = write(1, pattern, 0x30);
	if (message == DEATH_MESSAGE)
		return ;
	pthread_mutex_unlock(&stdout_mutex);
	(void)_;
}
