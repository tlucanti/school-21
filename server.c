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
static void	print_prompt(pid_t pid);
static void print_ok(void);
static int	server(void);

volatile sig_atomic_t	g_pid_sig[2];

__attribute__((noreturn)) int	main(int argc, __attribute__((unused)) char *const *argv)
{
	struct sigaction	sig;
	int					ret;

	if (argc != 1)
		write(1, WARNING "[WARN]" TERM_WHITE " server parameters")
	print_prompt(getpid());
	sigemptyset(&sig.sa_mask);
	sig.sa_sigaction = ft_sa_sigaction;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		pause();
		ret = server();
		if (ret)
		{
			print_ok();
			kill(g_pid_sig[0], SIGUSR2);
		}
		else
			kill(g_pid_sig[0], SIGUSR1);
	}
}

static void	print_prompt(pid_t pid)
{
	static unsigned char	pattern[] = OK"[ OK ]" TERM_WHITE " server started "
		OK "successfully" RESET "\n" INFO "[INFO]"TERM_WHITE" server PID:  "
		TERM_YELLOW "[00000000]" RESET "\n";

	ft_putunbr(pattern + 0x66, pid);
	write(1, pattern, 0x74);
}

static void print_ok(void)
{
	static unsigned char	pattern[] = OK "[ OK ]" TERM_WHITE " got message "
		"from " WARNING "PID: [00000000]" RESET "\n";

	ft_putunbr(pattern + 0x33, g_pid_sig[0]);
	write(1, pattern, 0x41);
}

static void	ft_sa_sigaction(int sig, siginfo_t *info,__attribute__((unused))
				void *context)
{
	g_pid_sig[1] = sig;
	g_pid_sig[0] = info->si_pid;
}

static int	server(void)
{
	static unsigned char			buff[32];
	volatile static unsigned int	bit = 0x00u;
	int								ret;

	buff[bit / 8] |= (g_pid_sig[1] == SIGUSR1) << (bit % 8); // write bit to position buff[bit // 8][bit % 8]
	// printf("got %d\n", bit);
	if (bit == 8 * 32 - 1) // if buffer is full - write 32 bytes
	{
		ret = 0;
		if (buff[bit / 8] == 0)
		{
			buff[31] = '\n';
			ret = 1;
		}
		else
			bit = SIGUSR1;
		write(1, buff, 32);
		((uintmax_t *)buff)[0] = 0x0000000000000000u;
		((uintmax_t *)buff)[1] = 0x0000000000000000u;
		((uintmax_t *)buff)[2] = 0x0000000000000000u;
		((uintmax_t *)buff)[3] = 0x0000000000000000u;
		bit = 0x00u;
		return (ret);
	}
	if (bit % 8 != 7 || buff[bit / 8] || !bit)
	{
		++bit;
		/* if bit is in the middle of the byte or if last byte is not `\0` */
		// printf("called kill\n");
		return (0);
	}
	// if last byte is `\0` - change it to `\n` and write `bit // 8` bytes
	buff[bit >> 0x3u] = '\n';//0xAu;
	write(1, buff, (bit >> 3) + 1);
	((uintmax_t *)buff)[0] = 0x0000000000000000u;
	((uintmax_t *)buff)[1] = 0x0000000000000000u;
	((uintmax_t *)buff)[2] = 0x0000000000000000u;
	((uintmax_t *)buff)[3] = 0x0000000000000000u;
	bit = 0x00u;
	return (1);
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
