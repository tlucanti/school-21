#include "bsq.h"

void	print_out(int **array, int rows, int cols, t_array_data *d)
{
	int row;
	int col;

	row = 0;
	while (row < rows)
	{
		col = 0;
		while (col < cols)
		{
			if (array[row][col] == 0)
				write(1, &d->block, 1);
			else
				write(1, col > d->x || col <= d->x - d->size || row > d->y ||
				row <= d->y - d->size ? &d->free_space : &d->filled_space, 1);
			col++;
			//write(1, " ", 1);
		}
		row++;
		write(1, "\n", 1);
	}
}
