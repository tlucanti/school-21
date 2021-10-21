#include <stdlib.h>
#include <stdio.h>
#include "ft_is_sort.c"

int f(int a, int b)
{
	if (a>b)
		return (1);
	if (a<b)
		return (-1);
	else
		return (0);
}

int str2int(char *str)
{
	int i;
	int s = 1;

	i = 0;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	while (*str)
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	return (i * s);
}

void print_arr(int *arr, int size)
{
	for (int i=0; i < size; i++)
		printf("%d ", arr[i]);
}


int main(int argc, char **argv)
{
	int i;
	int *arr = (int *)malloc(sizeof(int)*(argc-1));

	i = 0;
	while (argv[i+1])
	{
		arr[i] = str2int(argv[i+1]);
		i++;
	}
	print_arr(arr, argc - 1);
	printf("\n%d\n",ft_is_sort(arr, argc - 1, f));

	return(0);
}