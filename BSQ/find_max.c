#include "bsq.h"

void	find_max(int **array, int rows, int cols, t_array_data *d)
{
	int row;
	int col;

	d->size = 0;
	d->x = 0;
	d->y = 0;
	row = 0;
	while (row < rows)
	{
		col = 0;
		while (col < cols)
		{
			if (array[row][col] > d->size)
			{
				d->x = col;
				d->y = row;
				d->size = array[row][col];
			}
			col++;
		}
		row++;
	}
}
