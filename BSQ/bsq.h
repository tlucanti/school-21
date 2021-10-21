
#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_array_data
{
	int			**array;
	int			x;
	int			y;
	int			size;
	char		free_space;
	char		block;
	char		filled_space;
}				t_array_data;

int				main(int argc, char **argv);
void			alg(int **array, int rows, int cols);
int				min(int a, int b, int c);
t_array_data	*parcer(char *path);
int				get_line_size(int f_desc);
int				**init_array_and_move_file(int f_desc, t_array_data *data);
t_array_data	*init_array_data(void);
int				check_zero_line(int f_desc, t_array_data *data);
int				check_zero_line_loop(char *syms, int lines, int f_desc,
					t_array_data *data);
int				check_all_lines(int f_desc, t_array_data *data);
int				check_one_line(int f_desc, t_array_data *data,
					int row, int *box_flag);
void			print_out(int **array, int rows, int cols, t_array_data *d);
void			find_max(int **array, int rows, int cols, t_array_data *d);


#endif
