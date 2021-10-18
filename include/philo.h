/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:23:16 by kostya            #+#    #+#             */
/*   Updated: 2021/10/18 18:07:03 by kostya           ###   ########.fr       */
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

typedef struct s_data
{
	uint			phil_num;
	uint			live_time;
	uint			eat_time;
	uint			sleep_time;
	uint			eat_num;

	pthread_t		*pthreads;
	uintmax_t		pthread_start;
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
void				take_forks(uint phil_num, unsigned char action,
						uintmax_t pthread_start);
void				mutex_print(uintmax_t time, uint philo_num,
						const uintmax_t *restrict message);
void				ft_putunbr(char *dest, uint n);

int					ft_atoi(const char *str);

# define _MY_SIZE_T	(unsigned long long
# define VOID_PTR	void *)_MY_SIZE_T

# define LFORK_MESSAGE		(unsigned long *)"has taken left fork     "
# define RFORK_MESSAGE		(unsigned long *)"has taken right fork    "
# define EATING_MESSAGE		(unsigned long *)"is eating               "
# define SLEEP_MESSAGE		(unsigned long *)"is sleeping             "
# define THINK_MESSAGE		(unsigned long *)"is thinking             "
# define DEATH_MESSAGE		(unsigned long *)"died                    "
# define PRINT_PATTERN		"[00000000]: 00000000 @@@@@@@@@@@@@@@@@@@@@@@@  \n"

#endif // PHILO_H
