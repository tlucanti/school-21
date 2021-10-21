/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 19:31:07 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/13 19:31:09 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ex00/ft_ft.c"
// #include "ex01/ft_ultimate_ft.c"
// #include "ex02/ft_swap.c"
// #include "ex03/ft_div_mod.c"
// #include "ex04/ft_ultimate_div_mod.c"
// #include "ex05/ft_putstr.c"
#include "ex06/ft_strlen.c"
// #include "ex07/ft_rev_int_tab.c"
// #include "ex08/ft_sort_int_tab.c"

#include <stdio.h>

void __print_array(int*__a, int n) {
	for (int i=0;i<n;i++) {
		printf("%d ", __a[i]);
	}
	printf("\n");
}

int main() {

	// ex 00
	// void ft_ft(int *nbr)

		// int f = 0;
		// ft_ft(&f);
		// printf("%d\n", f);
		// f = -2147483648;
		// ft_ft(&f);
		// printf("%d\n", f);

	// ex01
	// void ft_ultimate_ft(int *********nbr)

		// int f0 = 123;
		// int * f1 = &f0;
		// int ** f2 = &f1;
		// int *** f3 = &f2;
		// int **** f4 = &f3;
		// int ***** f5 = &f4;
		// int ****** f6 = &f5;
		// int ******* f7 = &f6;
		// int ******** f8 = &f7;
		// int ********* f = &f8;
		// ft_ultimate_ft(f);
		// printf("%d\n", *********f);
		// f0 = -2147483648;
		// ft_ultimate_ft(f);
		// printf("%d\n", *********f);

	// ex02
	// void ft_swap(int *a, int *b)

		// int a = 2;
		// int b = 3;
		// printf("%d %d -> ", a, b);
		// ft_swap(&a, &b);
		// printf("%d %d\n", a, b);
		// a = 2147483647;
		// b = -2147483648;
		// printf("%d %d -> ", a, b);
		// ft_swap(&a, &b);
		// printf("%d %d\n", a, b);

	// ex03
	// void ft_div_mod(int a, int b, int *div, int *mod)

		// int a = 10;
		// int b = 5;
		// int d = 0;
		// int m = -322;
		// ft_div_mod(a, b, &d, &m);
		// printf("%d %d -> %d %d\n", a, b, d, m);
		// a = -5;
		// b = 4;
		// d = 228;
		// m = 1337;
		// ft_div_mod(a, b, &d, &m);
		// printf("%d %d -> %d %d\n", a, b, d, m);

	// ex04
	// ft_ultimate_div_mod(int *a, int *b)

		// int a = 10;
		// int b = 5;
		// int d = 0;
		// int m = 0;
		// printf("%d %d -> ", a, b);
		// ft_ultimate_div_mod(&a, &b);
		// printf("%d %d\n", a, b);
		// a = -5;
		// b = 4;
		// d = 228;
		// m = 1337;
		// printf("%d %d -> ", a, b);		
		// ft_ultimate_div_mod(&a, &b);
		// printf("%d %d\n", a, b);

	// ex05
	// void ft_putstr(char *str)

		// char * a1 = "1234567890";
		// ft_putstr(a1);
		// write(1, "$\n", 2);
		// char * a2 = "!@#$%^&*(){}[]\'\'\"\"?/|";
		// ft_putstr(a2);
		// write(1, "$\n", 2);
		// char * a3 = "";
		// ft_putstr(a3);
		// write(1, "$\n", 2);
		// char * a4 = "\n\a\t";
		// ft_putstr(a4);
		// write(1, "$\n", 2);
		// char * a5 = "123\000456";
		// ft_putstr(a5);
		// write(1, "$\n", 2);


	// ex06
	// int ft_strlen(char *str)

		char * a1 = "1234567890";
		printf("10 -> %d\n", ft_strlen(a1));
		char * a2 = "!@#$%^&*(){}[]\'\'\"\"?/|";
		printf("21 -> %d\n", ft_strlen(a2));
		char * a3 = "";
		printf("0 -> %d\n", ft_strlen(a3));
		char * a4 = "\n\a\t";
		printf("3 -> %d\n", ft_strlen(a4));
		char * a5 = "123\000456";
		printf("3 -> %d\n", ft_strlen(a5));

	// ex07
	// void ft_rev_int_tab(int *tab, int size)

		// int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
		// ft_rev_int_tab(a, 8);
		// __print_array(a, 8);
		// int b[] = {1, 2, 3};
		// ft_rev_int_tab(b, 3);
		// __print_array(b, 3);
		// int c[] = {};
		// ft_rev_int_tab(c, 0);
		// __print_array(c, 0);

	// ex08
	// void ft_sort_int_tab(int *tab, int size)

		// int a[] = {8, 4, 3, 1, 5, 6, 5, 3, 0, -333, 2342, 3, 3, 3, 3, 3, 3, 3, 98};
		// ft_sort_int_tab(a, 19);
		// __print_array(a, 19);
		// int b[] = {3, 2, 1};
		// ft_sort_int_tab(b, 3);
		// __print_array(b, 3);
		// int c[] = {};
		// ft_sort_int_tab(c, 0);
		// __print_array(c, 0);

	return 0;
}


/*

norminette -R CheckForbiddenSourceHeader ex00/ft_ft.c
norminette -R CheckForbiddenSourceHeader ex01/ft_ultimate_ft.c
norminette -R CheckForbiddenSourceHeader ex02/ft_swap.c
norminette -R CheckForbiddenSourceHeader ex03/ft_div_mod.c
norminette -R CheckForbiddenSourceHeader ex04/ft_ultimate_div_mod.c
norminette -R CheckForbiddenSourceHeader ex05/ft_putstr.c
norminette -R CheckForbiddenSourceHeader ex06/ft_strlen.c
norminette -R CheckForbiddenSourceHeader ex07/ft_rev_int_tab.c
norminette -R CheckForbiddenSourceHeader ex08/ft_sort_int_tab.c

*/










































