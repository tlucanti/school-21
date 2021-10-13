/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:23:16 by kostya            #+#    #+#             */
/*   Updated: 2021/10/13 15:27:52 by kostya           ###   ########.fr       */
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
# include <stdint.h>
# include <sys/types.h>

typedef	struct s_data
{
	uint_fast32_t	phil_num;
	uint_fast32_t	die_time;
	uint_fast32_t	eat_time;
	uint_fast32_t	sleep_time;
	uint_fast32_t	eat_num;

	uint_fast64_t	pthread_start;
	uint_fast64_t	*death_time;

	uint_fast8_t	stop;

	pthread_mutex_t	stdout_mutex;
} t_data;

int				main(int argc, char *const *argv);
uint_fast8_t	parse(t_data *restrict data, char *const *argv);
uint_fast64_t	ft_time(void);
void			start(t_data *restrict data);
void			*phil_routine(void *philo_num_ptr);
t_data			*data_storage(void);
void			stop(t_data *restrict data);
void			*death_monitor(__attribute__((unused)) void *_);
void			take_forks(uint_fast32_t phil_num, uint_fast8_t action, uint_fast64_t pthread_start);
void			mutex_print(uint_fast64_t time, uint_fast32_t phil_num, const char *restrict message);

int				ft_atoi(const char *str);

#endif // PHILO_H
