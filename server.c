/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:20:53 by kostya            #+#    #+#             */
/*   Updated: 2021/10/22 23:45:32 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include "include/color.h"

ssize_t	write(int fd, const void *buf, size_t count);
static void	ft_sa_sigaction(int sig, siginfo_t *info, __attribute__((unused)) void *context);
static void	ft_putunbr(unsigned char *start, pid_t pid);

__attribute__((noreturn)) int	main(void)
{
	static unsigned char	pattern[] = OK"[ OK ]" TERM_WHITE " server started "
		OK "successfully" RESET "\n" INFO "[INFO]"TERM_WHITE" server PID:  "
		TERM_YELLOW "[00000000]" RESET "\n";
	struct sigaction		sig;
	pid_t					pid;

	pid = getpid();
	printf("%d\n", pid);
	ft_putunbr(pattern + 0x66, pid);
	write(1, pattern, 0x74);
	sigemptyset(&sig.sa_mask);
	sig.sa_sigaction = ft_sa_sigaction;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}

static void	ft_sa_sigaction(int sig, siginfo_t *info,__attribute__((unused)) void *context)
{
	static unsigned char			buff[32];
	volatile static unsigned int	bit = 0x00u;

	sig = sig == SIGUSR1;
	buff[bit / 8] |= sig << (bit % 8); // write bit to position buff[bit // 8][bit % 8]
	// printf("got %d\n", bit);
	if (bit == 8 * 32 - 1) // if buffer is full - write 32 bytes
	{
		if (buff[bit / 8] == 0)
		{
			buff[31] = '\n';
			kill(info->si_pid, SIGUSR2);
		}
		else
			bit = SIGUSR1;
		write(1, buff, 32);
		((uintmax_t *)buff)[0] = 0x0000000000000000u;
		((uintmax_t *)buff)[1] = 0x0000000000000000u;
		((uintmax_t *)buff)[2] = 0x0000000000000000u;
		((uintmax_t *)buff)[3] = 0x0000000000000000u;
		bit = 0x00u;
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	if (bit % 8 != 7 || buff[bit / 8] || !bit)
	{
		++bit;
		/* if bit is in the middle of the byte or if last byte is not `\0` */
		// printf("called kill\n");
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	// if last byte is `\0` - change it to `\n` and write `bit // 8` bytes
	buff[bit >> 0x3u] = '\n';//0xAu;
	write(1, buff, (bit >> 3) + 1);
	((uintmax_t *)buff)[0] = 0x0000000000000000u;
	((uintmax_t *)buff)[1] = 0x0000000000000000u;
	((uintmax_t *)buff)[2] = 0x0000000000000000u;
	((uintmax_t *)buff)[3] = 0x0000000000000000u;
	bit = 0x00u;
	kill(info->si_pid, SIGUSR2);
}

static void	ft_putunbr(unsigned char *start, pid_t pid)
{
	start[7] = pid % 10 + 48;
	pid /= 10;
	start[6] = pid % 10 + 48;
	pid /= 10;
	start[5] = pid % 10 + 48;
	pid /= 10;
	start[4] = pid % 10 + 48;
	pid /= 10;
	start[3] = pid % 10 + 48;
	pid /= 10;
	start[2] = pid % 10 + 48;
	pid /= 10;
	start[1] = pid % 10 + 48;
	pid /= 10;
	start[0] = pid % 10 + 48;
}
