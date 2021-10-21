/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:36:55 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/20 14:36:57 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		str_cmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	print_params(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		while (*(argv[i]))
			write(1, (argv[i])++, 1);
		write(1, "\n", 1);
		i++;
	}
}

void	swap_array(char **arr, int a, int b)
{
	char *c;

	c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;
}

char	**sort(char **arr, int size)
{
	int i;
	int j;

	i = size;
	while (i)
	{
		j = 0;
		while (j < i - 1)
		{
			if (str_cmp(arr[j], arr[j + 1]) > 0)
				swap_array(arr, j, j + 1);
			j++;
		}
		i--;
	}
	return (arr);
}

int		main(int argc, char **argv)
{
	argv = sort(argv + 1, argc - 1);
	print_params(argc - 1, argv);
}
