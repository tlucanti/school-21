/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:23:16 by kostya            #+#    #+#             */
/*   Updated: 2021/10/13 22:57:14 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# ifdef __linux__
#  include <malloc.h>
# else
#  include <stdlib.h>
# endif

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <string.h>

typedef	struct s_data
{
	uint						phil_num;
	uint						live_time;
	uint						eat_time;
	uint						sleep_time;
	uint						eat_num;

	pthread_t				*pthreads;
	uintmax_t				pthread_start;
	uintmax_t				*death_time;

	unsigned char		stop;
	pthread_mutex_t	stdout_mutex;
} t_data;

int						main(int argc, char *const *argv);
unsigned char	parse(t_data *restrict data, char *const *argv);
uintmax_t			ft_time(void);
void					start(t_data *restrict data);
void					*phil_routine(void *philo_num_ptr);
void					stop(t_data *restrict data);
void					*death_monitor(__attribute__((unused)) void *_);
void					take_forks(uint phil_num, unsigned char action, uintmax_t pthread_start);
void					mutex_print(uintmax_t time, uint phil_num, const char *restrict message);

int						ft_atoi(const char *str);

#endif // PHILO_H
