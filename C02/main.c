/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 11:38:53 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/15 11:38:55 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ex00/ft_strcpy.c"
// #include "ex01/ft_strncpy.c"
// #include "ex02/ft_str_is_alpha.c"
// #include "ex03/ft_str_is_numeric.c"
// #include "ex04/ft_str_is_lowercase.c"
// #include "ex05/ft_str_is_uppercase.c"
// #include "ex06/ft_str_is_printable.c"
// #include "ex07/ft_strupcase.c"
// #include "ex08/ft_strlowcase.c"
// #include "ex09/ft_strcapitalize.c"
// #include "ex10/ft_strlcpy.c"
// #include "ex11/ft_putstr_non_printable.c"
# include "ex12/ft_print_memory.c"

#include <stdio.h>

int main () {

	/* ex00
	 * char *ft_strcpy(char *dest, char *src)
	 */

		// char a0[] = "abcd\0";
		// char b0[4];
		// printf("%s -> %s", a0, ft_strcpy(b0, a0));

	/* ex01
	 * char *ft_strncpy(char *dest, char *src, unsigned int n)
	 */

		// char a1[] = "abcdef\0";
		// char b1[7] = {0};
		// printf("%s\n", ft_strncpy(b1, a1, 3));
		// char c1[] = "abcdef\0";
		// char d1[20] = {0};
		// printf("%s\n", ft_strncpy(c1, d1, 20));


	/* ex02
	 * int ft_str_is_alpha(char *str)
	 */

		// printf("%d %d\n", ft_str_is_alpha("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\0"), ft_str_is_alpha("\0"));
		// char a2[2] = {0};
		// for (int  i=1; i<128; i++) {
		// 	a2[0] = i;
		// 	printf("%d - %c: %d\n", i, *a2, ft_str_is_alpha(a2));
		// }
		// printf("\n");

	/* ex03
	 * int ft_str_is_numeric(char *str)
	 */

		// printf("%d %d\n", ft_str_is_numeric("0123456789\0"), ft_str_is_numeric("\0"));
		// char a3[2] = {0};
		// for (int  i=1; i<128; i++) {
		// 	a3[0] = i;
		// 	printf("%d - %c: %d\n", i, *a3, ft_str_is_numeric(a3));
		// }
		// printf("\n");

	/* ex04
	 * int ft_str_is_lowercase(char *str)
	 */

		// printf("%d %d\n", ft_str_is_lowercase("abcdefghijklmnopqrstuvwxyz"), ft_str_is_lowercase("\0"));
		// char a4[1] = {0};
		// for (int i=1; i<128; i++) {
		// 	a4[0] = i;
		// 	printf("%d-%c: %d\n", i, a4[0], ft_str_is_lowercase(a4));
		// }
		// printf("\n");

	/* ex05
	 * int ft_str_is_uppercase(char *str)
	 */

		// printf("%d %d\n", ft_str_is_uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), ft_str_is_uppercase("\0"));
		// char a5[1] = {0};
		// for (int i=1; i<128; i++) {
		// 	a5[0] = i;
		// 	printf("%d-%c: %d\n", i, a5[0], ft_str_is_uppercase(a5));
		// }
		// printf("\n");

	/* ex06
	 * int ft_str_is_printable(char *str)
	 */

		// printf("%d %d\n", ft_str_is_printable(" ~"), ft_str_is_printable("\0"));
		// char a6[1] = {0};
		// for (int i=1; i<128; i++) {
		// 	a6[0] = i;
		// 	printf("%d-%c: %d\n", i, a6[0], ft_str_is_printable(a6));
		// }
		// printf("\n");


	/* ex07
	 * char *ft_strupcase(char *str)
	 */
		
		// char b7[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
		// printf("%s\n", ft_strupcase(b7));
		// char a7[1] = {0};
		// for (int i=0; i<128; i++) {
		// 	a7[0] = i;
		// 	printf("%d-%c: %s\n", i, a7[0], ft_strupcase(a7));
		// }
		// printf("\n");

	/* ex08
	 * char *ft_strlowcase(char *str)
	 */

		// char b8[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
		// printf("%s\n", ft_strlowcase(b8));
		// char a8[1] = {0};
		// for (int i=0; i<128; i++) {
		// 	a8[0] = i;
		// 	printf("%d-%c: %s\n", i, a8[0], ft_strlowcase(a8));
		// }
		// printf("\n");

	/* ex09
	 * char *ft_strcapitalize(char *str)
	 */

		//char a9[] = "sALut, cOmMenT Tu vAS ? 42MoTs qUAranTe-DEUX; ciNquaNtE+et+uN\0";
		//printf("%s\n", ft_strcapitalize(a9));
		// char b9[] = "a a a\0";
		// printf("%s\n", ft_strcapitalize(b9));

	/* ex10
	 * unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
	 */

		// char a10[] = "12345";
		// char b10[6];
		// printf("%d, %s -> %s\n", ft_strlcpy(b10, a10, 5), a10, b10);
		// char e10[] = "123\0";
		// char f10[20];
		// printf("%d, %s -> %s\n", ft_strlcpy(b10, a10, 20), a10, b10);
		// char c10[] = "123";
		// char d10[1];
		// printf("%d, %s -> %s\n", ft_strlcpy(c10, d10, 0), c10, d10);

	/* ex11
	 * void ft_putstr_non_printable(char *str)
	 */

		// char a11[] = "Coucou\ntu vas bien ?";
		// ft_putstr_non_printable(a11);
		// write(1, "\n", 1);
		// char b11[] = "\n\t\e\r\t\a\f\v\b";
		// ft_putstr_non_printable(b11);
		// write(1, "\n", 1);
		// char c11[] = "";
		// ft_putstr_non_printable(c11);
		// write(1, "\n", 1);

	/* ex12
	 * void *ft_print_memory(void *addr, unsigned int size)
	 */

		// char a[] = "123";

		// ft_print_memory((void *) a, 1);

}	


/*

norminette -R CheckForbiddenSourceHeader ex00/ft_strcpy.c
norminette -R CheckForbiddenSourceHeader ex01/ft_strncpy.c
norminette -R CheckForbiddenSourceHeader ex02/ft_str_is_alpha.c
norminette -R CheckForbiddenSourceHeader ex03/ft_str_is_numeric.c
norminette -R CheckForbiddenSourceHeader ex04/ft_str_is_lowercase.c
norminette -R CheckForbiddenSourceHeader ex05/ft_str_is_uppercase.c
norminette -R CheckForbiddenSourceHeader ex06/ft_str_is_printable.c
norminette -R CheckForbiddenSourceHeader ex07/ft_strupcase.c
norminette -R CheckForbiddenSourceHeader ex08/ft_strlowcase.c
norminette -R CheckForbiddenSourceHeader ex09/ft_strcapitalize.c
norminette -R CheckForbiddenSourceHeader ex10/ft_strlcpy.c
norminette -R CheckForbiddenSourceHeader ex11/ft_putstr_non_printable.c
norminette -R CheckForbiddenSourceHeader ex12/ft_print_memory.c

*/












































