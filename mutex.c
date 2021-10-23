/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:47:17 by kostya            #+#    #+#             */
/*   Updated: 2021/10/21 15:58:24 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

uintmax_t	take_forks(uint phil_num, unsigned char action,
				t_data *restrict data)
{
	uintmax_t					time;

	if (action)
	{
		pthread_mutex_lock(data->forks + phil_num);
		if (data->phil_num == 1)
		{
			ft_usleep(data->live_time + 100);
			return (0);
		}
		mutex_print(ft_time() - data->pthread_start[phil_num], phil_num,
			LFORK_MESSAGE);
		pthread_mutex_lock(data->forks + (phil_num + 1) % data->phil_num);
		time = ft_time() - data->pthread_start[phil_num];
		mutex_print(time, phil_num, RFORK_MESSAGE);
		return (time);
	}
	else
	{
		pthread_mutex_unlock(data->forks + phil_num);
		pthread_mutex_unlock(data->forks + (phil_num + 1) % data->phil_num);
		return (0);
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
	static char				pattern[] = TERM_YELLOW "[00000.000]: " TERM_WHITE
						"000000000 COLTKEN@@@@@@@@@@@@@@@@@" TERM_RESET "  \n"
;
	uint					_;

	pthread_mutex_lock(&stdout_mutex);
	if (pattern[0] == 0)
	{
		pthread_mutex_unlock(&stdout_mutex);
		return ;
	}
	ft_putunbr(pattern + 8, (uint)time);
	ft_putunbr(pattern + 0x1b, philo_num + 1);
	*(unsigned long long *)(pattern + 0x25) = message[0];
	*(unsigned long long *)(pattern + 0x2d) = message[1];
	*(unsigned long long *)(pattern + 0x35) = message[2];
	_ = write(1, pattern, 0x48);
	if (*message == *DEATH_MESSAGE)
		pattern[0] = 0;
	pthread_mutex_unlock(&stdout_mutex);
	(void)_;
}
