/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:33:59 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/26 11:34:01 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_foreach.c"
#include "ex01/ft_map.c"
#include "ex02/ft_any.c"
#include "ex03/ft_count_if.c"
#include "ex04/ft_is_sort.c"
#include "ex06/ft_sort_string_tab.c"
#include "ex07/ft_advanced_sort_string_tab.c"

#include <stdio.h>
#include <stdlib.h>

void f(int a) {
	printf("%d ", a);
}
int g(int a) {
	return -a;
}
int h(char *a) {
	return (*a=='a');
}
int i(char *a) {
	return (*a!='a');
}
int j(int a, int b) {
	return ((a < b) - (b < a));
}
int		__str_cmp__(char *s1, char *s2)
{
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			break ;
	return (*--s1 - *--s2);
}


int main() {

	// // ex00

	printf("\n==================== ex00 ====================\n\n");
	int a1[] = {1,2,3,4,5,6,7,8,9,0};
	printf("1 2 ... 9 0 -> ");
	ft_foreach(a1, 10, f);

	// ex01

	printf("\n\n==================== ex01 ====================\n\n");
	int a2[] = {1,2,3,4,5,6,7,8,9,0};
	printf("-1, -2, ..., -9, 0 -> ");
	ft_foreach(ft_map(a2, 10, g), 10, f);

	// // ex02

	printf("\n\n==================== ex02 ====================\n\n");
	char **arr1 = (char **)malloc(sizeof(char*)* 4);
	char ar1[] = "qwe";
	char ar2[] = "rty";
	char ar3[] = "uio";
	arr1[0] = ar1;
	arr1[1] = ar2;
	arr1[2] = ar3;
	arr1[3] = 0;
	printf("0 -> %d\n", ft_any(arr1, h));
	arr1[2][0] = 'a';
	printf("1 -> %d\n", ft_any(arr1, h));

	// ex03

	printf("\n==================== ex03 ====================\n\n");
	char **arr2 = (char **)malloc(sizeof(char*)* 4);
	char ar4[] = "qwe";
	char ar5[] = "rty";
	char ar6[] = "uio";
	arr2[0] = ar4;
	arr2[1] = ar5;
	arr2[2] = ar6;
	arr2[3] = 0;
	printf("3 -> %d\n", ft_count_if(arr2, 3, i));
	arr2[2][0] = 'a';
	printf("2 -> %d\n", ft_count_if(arr2, 3, i));

	// ex04

	printf("\n\n==================== ex04 ====================\n\n");
	int a31[] = {1,2,3,4,5,6,7,8,9,0};
	int a32[] = {9, 8, 7, 6, 5};
	int a33[] = {0, 0, 0, 0, 0, 0};
	printf("0 -> %d\n", ft_is_sort(a31, 10, j));
	a31[9] = 10;
	printf("1 -> %d\n", ft_is_sort(a31, 10, j));
	printf("1 -> %d\n", ft_is_sort(a32, 5, j));
	printf("1 -> %d\n", ft_is_sort(a33, 6, j));

	// ex06

	printf("\n==================== ex06 ====================\n\n");
	char **arr3 = (char **)malloc(sizeof(char*)* 4);
	char ar7[] = "3";
	char ar8[] = "2";
	char ar9[] = "1";
	arr3[0] = ar7;
	arr3[1] = ar8;
	arr3[2] = ar9;
	arr3[3] = 0;
	ft_sort_string_tab(arr3);
	printf("1 2 3 -> ");
	while (*arr3)
		printf("%s ", *arr3++);

	// ex07

	printf("\n\n==================== ex07 ====================\n\n");
	char **arr4 = (char **)malloc(sizeof(char*)* 4);
	char ar10[] = "3";
	char ar11[] = "2";
	char ar12[] = "1";
	arr4[0] = ar10;
	arr4[1] = ar11;
	arr4[2] = ar12;
	arr4[3] = 0;
	ft_advanced_sort_string_tab(arr4, __str_cmp__);
	printf("1 2 3 -> ");
	while (*arr4)
		printf("%s ", *arr4++);


}





























