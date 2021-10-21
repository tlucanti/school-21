
#ifndef HEXDUMP_H
# define HEXDUMP_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

# include <stdio.h>

#define BUFF_SIZE 256

typedef	struct	s_str
{
	char	*str;
	int		size;
}				t_str;

char	*dec2hex(int num);
int		err(int errcode, char *path);
void	print_str(char *str, int newline);
void	print_dump(t_str str);
char	*dec_to_base(long nbr, char *base, int *digits);
t_str	reallol(t_str str, char *str_append, int size);
t_str	read_file(char *path);
t_str	file_cat(char **argv);
int		main(int argc, char ** argv);
int		str_n_copy_buff(char *dest, t_str str, int str_i, int n);
void	print_err(char *str, int newline);
void	print_3_num(int n);
void	print_81_num(int n);
void	print_82_num(int n);
void	put_np_char(char c);


#endif