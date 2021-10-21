/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:37:25 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/30 18:37:28 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

# include <stdio.h>

# define BUFF_SIZE 256
# define DICT_PATH "numbers.dict"

typedef struct		s_list
{
	struct s_list	*next;
	char			*number;
	char			*digit_name;
	int				size;
}					t_list;

typedef struct		s_outl
{
	struct s_outl	*next;
	char			*data;
}					t_outl;

int					main(int argc, char **argv);
void				final_print(t_outl *list);
void				print_str(char *str);
int					parcer(char *path);
char				*read_word(int f_desc, int lb, int rb);
int					skip_spaces(int f_desc);
char				*reallol(char *str, char *str_append, int size);
int					str_len(char *str);
void				push(t_list **begin_list, char *str1, char *str2, int num);
t_list				*list_last_pb(t_list *begin_list);
t_list				*create_elem(char *str1, char *str2, int num);
int					gen_push(char *number, char *digit_name);
int					defaults2(char *number);
int					defaultsn(char *number);
int					request(char *str);
int					find_number(t_list *table, char *str, int len);
int					str_cmp(char *str1, char *str2);
void				push_out_list(t_outl **begin_list, char *data);
t_outl				*outl_last(t_outl *begin_list);
t_outl				*create_elem_outl(char *data);
void				clear_t_list(t_list *begin_list);
void				clear_t_outl(t_outl *begin_list);

int					ft_units(char *str, int len);
int					ft_decimals(char *str, int len);
int					ft_million(int length);
int					ft_print_error(void);
int					request(char *num_str);
int					ft_number(char *str, int len);
void				check_zeros(char *str);
int					ft_check_num(char *str);
int					ft_hundred(char *str);

#endif
