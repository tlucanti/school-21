/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:20:30 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/26 16:20:32 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

# include <stdio.h>

int		main(int argc, char **argv);
int		init_arr(char **argv, int (**op_arr)(int, int, int *));
int		add(int a__, int b__, int *s__);
int		sub(int a__, int b__, int *s__);
int		div(int a__, int b__, int *s__);
int		mul(int a__, int b__, int *s__);
int		mod(int a__, int b__, int *s__);
char	*start(char *str, int *sign);
int		atoi(char *str);
void	print_digit(int a);
int		defaults(int *nb);
void	print_int(int nb);

#endif
