/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:21:24 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/26 16:21:26 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int argc, char **argv)
{
	int op_num;
	int status;
	int ans;
	int (*op_arr[5])(int, int, int *);

	if (argc != 4)
		return (1);
	status = 1;
	op_num = init_arr(argv, op_arr);
	if (op_num == -1)
	{
		return (1);
	}
	ans = op_arr[op_num](atoi(argv[1]), atoi(argv[3]), &status);
	if (status)
		print_int(ans);
	write(1, "\n", 1);
	return (0);
}

int	init_arr(char **argv, int (**op_arr)(int, int, int *))
{
	int op_num;

	if (argv[2][0] == '+' && argv[2][1] == 0)
		op_num = 0;
	else if (argv[2][0] == '-' && argv[2][1] == 0)
		op_num = 1;
	else if (argv[2][0] == '/' && argv[2][1] == 0)
		op_num = 2;
	else if (argv[2][0] == '*' && argv[2][1] == 0)
		op_num = 3;
	else if (argv[2][0] == '%' && argv[2][1] == 0)
		op_num = 4;
	else
	{
		write(1, "0\n", 2);
		return (-1);
	}
	op_arr[0] = add;
	op_arr[1] = sub;
	op_arr[2] = div;
	op_arr[3] = mul;
	op_arr[4] = mod;
	return (op_num);
}
