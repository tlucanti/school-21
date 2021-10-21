#include "bsq.h"

#include <time.h>

void print_a(int **a, int r, int c);
int **map_generator(int r, int c);


int		main(int argc, char **argv)
{
	t_array_data	*data;
	int rows;
	int cols;

	if (argc == 1)
		return (0);
	while (--argc)
	{
		if ((data = parcer(*++argv)) != 0)
		{
			rows = data->y;
			cols = data->x;
			data->size = -1;
				print_a(data->array, rows, cols);
				print_out(data->array, rows, cols, data);
				write(1, "\n", 1);
			alg(data->array, rows, cols);
			find_max(data->array, rows, cols, data);
			//if (data->size > 0)
				print_out(data->array, rows, cols, data);
		}
		else
			write(2, "map error", 9);
		if (argc > 0)
			write(1, "\n", 1);
	}
}

void print_a(int **a, int r, int c) {
	for (int i=0; i < r; i++) {
		for (int j=0; j < c; j++) {
			printf("%d ", (a[i][j]));
		}
		printf("\n");
	}
	printf("\n");
}

int **map_generator(int r, int c)
{
	srand(time(NULL));

	int ** a = (int **) malloc (sizeof(int *) * r);
	for (int i=0; i < r; i++) {
		a[i] = (int *) malloc (sizeof(int) * c);
		for (int j=0; j < c; j++) {
			a[i][j] = rand() % 100 > 2; 
		}
	}

	return (a);
}