#include "bsq.h"

int		check_zero_line(int f_desc, t_array_data *data)
{
	char	syms[4];
	int		lines;
	char	buff;

	lines = 0;
	if (!(read(f_desc, &buff, 1) && read(f_desc, syms, 1) &&
		read(f_desc, syms + 1, 1) && read(f_desc, syms + 2, 1)))
		return (1);
	if (buff >= 47 && buff <= 57)
		lines = buff - 48;
	else
		return (1);
	if (check_zero_line_loop(syms, lines, f_desc, data))
		return (1);
	return (0);
}

int		check_zero_line_loop(char *syms, int lines,
	int f_desc, t_array_data *data)
{
	char	buff;

	while (read(f_desc, &buff, 1))
	{
		if (buff == '\n')
		{
			data->y = lines;
			data->free_space = syms[0];
			data->block = syms[1];
			data->filled_space = syms[2];
			return (0);
		}
		if (!(buff > 31 && buff <= 126) || !((syms[0] >= 47 && syms[0] <= 57)))
			return (1);
		lines = lines * 10 + syms[0] - 48;
		syms[0] = syms[1];
		syms[1] = syms[2];
		syms[2] = buff;
	}
	return (1);
}

int		check_all_lines(int f_desc, t_array_data *data)
{
	int		row;
	int		box_flag;
	char	buff;

	box_flag = 0;
	row = 0;
	while (row < data->y)
	{
		data->array[row] = (int *)malloc(sizeof(int) * data->x);
		if (check_one_line(f_desc, data, row, &box_flag))
			return (1);
		row++;
	}
	if (box_flag == 0 || read(f_desc, &buff, 1) != 0)
		return (1);
	return (0);
}

int		check_one_line(int f_desc, t_array_data *data, int row, int *box_flag) 
{
	char	buff;
	int		col;

	col = 0;
	while (col < data->x)
	{
		if (read(f_desc, &buff, 1) == 0)
			return (1);
		if (!(buff == data->free_space || buff == data->filled_space
			|| buff == data->block))
			return (1);
		data->array[row][col] = (buff == data->free_space ? 1 : 0);
		if (buff == data->block)
			*box_flag = 1;
		col++;
	}
	read(f_desc, &buff, 1);
	if (buff != '\n')
		return (1);
	return (0);
}
