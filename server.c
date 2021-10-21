/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:20:53 by kostya            #+#    #+#             */
/*   Updated: 2021/10/21 22:28:47 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

ssize_t write(int fd, const void *buf, size_t count);

int	main(void)
{
	static char			pattern[] = TERM_YELLOW "[0000000]:" TERM_GREEN " server\n";
	struct sigaction	sig;
	pid_t				pid;

	pid = getpid();
	ft_putunbr(pattern + 8, pid);
	write(1, pattern, 0x20);
	sigemptyset(&sig.sa_mask);
	sig.sa_sighandler = sa_sigaction;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSER1, &sig, NULL);
	sigaction(SIGUSER2, &sig, NULL);
	while (1)
		pause();
}

static void	sa_sigaction(int sig, siginfo_t *info, void *context)
{
	static unsigned char	buff[4];
	static unsigned char	bit;

	sig = sig == SIGUSER1;
	buff[bit >> 0x3u] |= sig << (bit & 0x8u);
	if (bit == 0xffu)
	{
		write(1, buff, 0xffu);
		buff[0] = 0x0000000000000000u;
		buff[1] = 0x0000000000000000u;
		buff[2] = 0x0000000000000000u;
		buff[3] = 0x0000000000000000u;
		bit = 0x00u;
		return ;
	}
	if (bit++ & 0x7u || buff[bit - 0x1u >> 0x3u])
		return ;
	buff[bit >> 0x3u] = 0xAu;
	write(1, buff, bit >> 3);
	kill(info->si_pid, SIGUSER1);
	buff[0] = 0x0000000000000000u;
	buff[1] = 0x0000000000000000u;
	buff[2] = 0x0000000000000000u;
	buff[3] = 0x0000000000000000u;
	bit = 0x00u;
	(void)context;
}

static void	ft_putunbr(char *start, pid_t pid)
{
	start[7] = pid % 10;
	pid /= 10;
	start[6] = pid % 10;
	pid /= 10;
	start[5] = pid % 10;
	pid /= 10;
	start[4] = pid % 10;
	pid /= 10;
	start[3] = pid % 10;
	pid /= 10;
	start[2] = pid % 10;
	pid /= 10;
	start[1] = pid % 10;
	pid /= 10;
	start[0] = pid % 10;
}
