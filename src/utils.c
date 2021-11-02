/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kostya <kostya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:18:56 by kostya            #+#    #+#             */
/*   Updated: 2021/11/02 16:19:25 by kostya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include "../inc/color.h"

void	print_prompt(pid_t pid)
{
	static unsigned char	pattern[] = OK"[ OK ]" TERM_WHITE " server started "
		OK "successfully" RESET "\n" INFO "[INFO]"TERM_WHITE" server PID:  "
		TERM_YELLOW "[00000000]" RESET "\n";

	ft_putunbr(pattern + 0x66, pid);
	write(1, pattern, 0x74);
}

void	print_ok(void)
{
	static unsigned char	pattern[] = OK "[ OK ]" TERM_WHITE " got message "
		"from " WARNING "PID: [00000000]" RESET "\n";

	ft_putunbr(pattern + 0x33, g_pid_sig[0]);
	write(1, pattern, 0x41);
}
