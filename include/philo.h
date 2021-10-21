/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:59:18 by kostya            #+#    #+#             */
/*   Updated: 2021/10/21 15:59:55 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# ifdef __linux__
#  include <malloc.h>
#  include <stdint.h>
# else
#  include <stdlib.h>
# endif

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <string.h>
# include "color.h"

typedef struct s_data
{
	uint			phil_num;
	uint			live_time;
	uint			eat_time;
	uint			sleep_time;
	uint			eat_num;

	pthread_t		*pthreads;
	uintmax_t		*pthread_start;
	uintmax_t		*death_time;
	pthread_mutex_t	*forks;
	uint			*eaten;

	unsigned char	stop;
	pthread_mutex_t	stdout_mutex;
}	t_data;

int					main(int argc, char *const *argv);
unsigned char		parse(t_data *restrict data, char *const *argv);
uintmax_t			ft_time(void);
t_data				*data_storage(void);
void				start(t_data *restrict data);
void				*phil_routine(size_t philo_num_ptr);
void				stop(t_data *restrict data);
void				*death_monitor(t_data *data);
uintmax_t			take_forks(uint phil_num, unsigned char action);
void				mutex_print(uintmax_t time, uint philo_num,
						const uintmax_t *restrict message);
void				ft_putunbr(char *dest, uint n);
void				pthread_create_loop(uint start,
						const t_data *restrict data);

int					ft_atoi(const char *str);

# define LFORK_MESSAGE	(unsigned long *)"\e[1;95m has taken L fork "
# define RFORK_MESSAGE	(unsigned long *)"\e[1;95m has taken R fork "
# define EATING_MESSAG	(unsigned long *)"\e[1;92m is eating        "
# define SLEEP_MESSAGE	(unsigned long *)"\e[1;96m is sleeping      "
# define THINK_MESSAGE	(unsigned long *)"\e[1;94m is thinking      "
# define DEATH_MESSAGE	(unsigned long *)"\e[1;91m died             "

# define _MY_SIZE_T	(unsigned long long
# define VOID_PTR	void *)_MY_SIZE_T

#endif // PHILO_H
