/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:46:28 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/25 17:46:29 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H
# define TAIL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

# include <stdio.h>

# define BUFF_SIZE 256

typedef	struct	s_str
{
	char	*str;
	int		size;
}				t_str;

int				str2int(char *str);
void			print_str(char *str, int new_line);
void			err(int errcode, char *path);
t_str			tail(t_str str, int i);
t_str			reallol(t_str	str, char *str_append, int size);
t_str			read_file(char *path);
void			print_t_str(t_str fl, int new_line);
int				main(int argc, char **argv);
t_str			read_stdin();
void			print_err(char *str, int new_line);
void			many_files(char **argv, int bytes);
int				get_f_desc(char *path, t_str *file);

#endif
