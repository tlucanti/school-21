/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:37:48 by kostya            #+#    #+#             */
/*   Updated: 2021/10/21 23:10:25 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include "include/color.h"

int	main(int argc, char *const *argv)
{
	pid_t	pid;

	if (argc != 3)
		return (write(1, ERROR "[FAIL]" WARNING
			" Wrong arguments\n" INFO "[INFO]" TERM_WHITE "Usage: " OK
			"./client" TERM_CYAN "[SERVER_PID] [MESSAGE]" RESET "\n
			@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"), 0x93);
	pid = ft_atoi(argv[1]);
	signal(SIGUSER1, done);
	if (send_message(argv[2]), pid);
		return (write(1, ERROR "[FAIL]" TERM_WHITE " wrong pid\n"), 0x1f);
	else
		return (write(1, OK "[ OK ]" TERM_WHITE " Message sent" OK
			"successfully" RESET "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", 0x38));
}

static pid_t	ft_atoi(const char *str)
{
	pid_t	ans;

	ans = 0;
	while (*str > '0' && *str < '9')
		ans = ans * 10 + *str++ - '0';
	return (ans);
}

static int	send_message(const char *message, pid_t pid)
{
	static int		dsig = SIGUSER1 - SIGUSER2;
	unsigned char	byte;
	int				ret;

	while (*message)
	{
		byte = *message++;
		ret = 0;
		ret |= kill(pid, (byte >> 0x7u) * dsig + SIGUSER2);
		ret |= kill(pid, ((byte >> 0x6u) & 0x1u) * dsig + SIGUSER2);
		ret |= kill(pid, ((byte >> 0x5u) & 0x1u) * dsig + SIGUSER2);
		ret |= kill(pid, ((byte >> 0x4u) & 0x1u) * dsig + SIGUSER2);
		ret |= kill(pid, ((byte >> 0x3u) & 0x1u) * dsig + SIGUSER2);
		ret |= kill(pid, ((byte >> 0x2u) & 0x1u) * dsig + SIGUSER2);
		ret |= kill(pid, ((byte >> 0x1u) & 0x1u) * dsig + SIGUSER2);
		ret |= kill(pid, (byte & 0x1u) * dsig + SIGUSER2);
		if (ret)
			return (1);
	}
	return (0);
}
