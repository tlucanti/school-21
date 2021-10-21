#include "bsq.h"

void	alg(int **array, int rows, int cols)
{
	int col;
	int row;

	row = 1;
	while (row < rows)
	{
		col = 1;
		while (col < cols)
		{
			if (array[row][col] != 0)
				array[row][col] = min(array[row - 1][col], array[row][col - 1],
					array[row - 1][col - 1]) + 1;
			col++;
		}
		row++;
	}
}

int		min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= c && b <= a)
		return (b);
	else
		return (c);
}