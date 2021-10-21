#include "bsq.h"

t_array_data	*parcer(char *path)
{
	int				f_desc;
	t_array_data	*data;

	data = init_array_data();
	if ((f_desc = open(path, O_RDONLY)) == -1)
		return (0);
	if (check_zero_line(f_desc, data))
		return (0);
	printf("%d %c %c %c\n", data->y, data->free_space, data->filled_space, data->block);
	if ((data->x = get_line_size(f_desc)) == 0)
		return (0);
	close(f_desc);
	if ((f_desc = open(path, O_RDONLY)) == -1)
		return (0);
	data->array = init_array_and_move_file(f_desc, data);
	if (check_all_lines(f_desc, data))
		return (0);
	close(f_desc);
	return (data);
}

int				get_line_size(int f_desc)
{
	char	buff;
	int		lines;

	lines = 0;
	while (read(f_desc, &buff, 1))
	{
		if (buff == '\n')
			return (lines);
		lines++;
	}
	return (0);
}

int				**init_array_and_move_file(int f_desc, t_array_data *data)
{
	char	buff;
	int		**array;

	read(f_desc, &buff, 1);
	while (buff != '\n')
		read(f_desc, &buff, 1);
	array = (int **)malloc(sizeof(int *) * data->y);
	return (array);
}


t_array_data	*init_array_data(void)
{
	t_array_data *d;

	d = (t_array_data *)malloc(sizeof(t_array_data));
	d->array = 0;
	d->free_space = 0;
	d->filled_space = 0;
	d->block = 0;
	d->x = 0;
	d->y = 0;
	d->size = -1;
	return (d);
}