
#include <stdio.h>

// ex00

#include "ex00/ft.h"
#include "ex00/ft.h"

// ex01

#include "ex01/ft_boolean.h"
#include "ex01/ft_boolean.h"

void ft_putstr(char *str) {
	while (*str)
		write(1, str++, 1);
}

t_bool ft_is_even(int nbr) {
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

// int main(int argc, char **argv) {
// 	(void)argv;
// 	if (ft_is_even(argc - 1) == TRUE)
// 		ft_putstr(EVEN_MSG);
// 	else
// 		ft_putstr(ODD_MSG);	
// 	return (SUCCESS);
// }

// ex02

#include "ex02/ft_abs.h"
#include "ex02/ft_abs.h"

// int main() {
// 	int Value = 3;
// 	printf("%d, %d\n", ABS(123), ABS(-123));
// 	printf("%d, %d\n", ABS(Value + 3), ABS(Value - 6));
// }

// ex03

#include "ex03/ft_point.h"
#include "ex03/ft_point.h"

void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

// int main(void)
// {
// 	t_point point;
// 	set_point(&point);

// 	printf("%d, %d\n", point.x, point.y);

// 	return (0);
// }

// ex04

#include "ex04/ft_strs_to_tab.c"
#include "ex04/ft_show_tab.c"

int main (int argc, char ** argv) {
	t_stock_str * par = ft_strs_to_tab(argc-1, argv+1);
	ft_show_tab(par);
	// while (par->str)
	// {
	// 	printf("%d %s %s\n", par->size, par->str, par->copy);
	// 	par++;
	// }
}





















