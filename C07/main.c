
#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
#include "ex04/ft_convert_base.c"
#include "ex04/ft_convert_base2.c"
#include "ex05/ft_split.c"

#include <stdio.h>


void print_array(int *a, int s) {
	for (int i=0; i<s; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// How to test
// put file on root dir of day (where all ex** dirs)
// run on console:
// gcc -Wall -Wextra -Werror main.c && ./a.out

int main() {

	// ex00

		// printf("\n==================== ex00 ====================\n");

		// char *a01 = 0;
		// char *b01 = 0;
		// char *c01 = 0;
		// char a0[4] = "123\0";
		// char b0[1] = "\0";
		// char c0[] = "\t\n\a";
		// a01 = ft_strdup(a0);
		// b01 = ft_strdup(b0);
		// c01 = ft_strdup(c0);
		// printf("123 -> %p\n", a01);
		// printf("nothing -> %s\n", b01);
		// printf("\\t\\n\\a -> %s\n", c01);
		// free(a01);
		// free(b01);
		// free(c01);

	// ex01

		// printf("\n==================== ex01 ====================\n");

		// int *a11 = 0;
		// int *a12 = 0;
		// int *a13 = 0;
		// int *a14 = 0;
		// a11 = ft_range(-2147483648, 20);
		// a12 = ft_range(-5, 5);
		// a13 = ft_range(0, 0);
		// a14 = ft_range(5, 1);
		// printf("[0 : 9] -> ");
		// print_array(a11, 10);
		// printf("[-5 : 4] -> ");
		// print_array(a12, 10);
		// printf("0x0 -> %p \n", a13);
		// printf("0x0 -> %p \n", a14);
		// free(a11);
		// free(a12);
		// free(a13);
		// free(a14);
		// printf("%p", ft_range(-2147483648, 1));

	// ex02

		// printf("\n==================== ex02 ====================\n");

		// int **a2 = (int **) malloc (sizeof(int *));
		// int **b2 = (int **) malloc (sizeof(int *));
		// int **c2 = (int **) malloc (sizeof(int *));
		// int **d2 = (int **) malloc (sizeof(int *));
		// printf("[0 : 9] -> ");
		// printf("%d", ft_ultimate_range(a2, -2147483648, 1));
		// print_array(*a2, 10);
		// printf("[-5 : 4] -> ");
		// ft_ultimate_range(b2, -5, 5);
		// print_array(*b2, 10);
		// ft_ultimate_range(c2, 0, 0);
		// printf("0x0 -> %p \n", *c2);
		// ft_ultimate_range(d2, 5, 1);
		// printf("0x0 -> %p \n", *d2);
		// free(a2);
		// free(b2);
		// free(c2);

	// ex03

		// printf("\n==================== ex03 ====================\n");

		// char **s3 = (char **) malloc (sizeof(char *) * 2);
		// char a31[] = "123";
		// char a32[] = "456";
		// s3[0] = a31;
		// s3[1] = a32;
		// char *a3;
		// a3 = ft_strjoin(2, s3, "--");
		// printf("%s\n", a3);

		// s3 = (char **) malloc (sizeof(char *) * 2);
		// char b31[] = "";
		// char b32[] = "456";
		// s3[0] = b31;
		// s3[1] = b32;
		// a3 = ft_strjoin(2, s3, "--");
		// printf("%s\n", a3);

		// s3 = (char **) malloc (sizeof(char *) * 2);
		// char c31[] = "123";
		// char c32[] = "456";
		// s3[0] = c31;
		// s3[1] = c32;
		// a3 = ft_strjoin(2, s3, "");
		// printf("%s\n", a3);

		// s3 = (char **) malloc (sizeof(char *) * 2);
		// char d31[] = "123";
		// char d32[] = "";
		// s3[0] = d31;
		// s3[1] = d32;
		// a3 = ft_strjoin(2, s3, "--");
		// printf("%s\n", a3);

		// s3 = (char **) malloc (sizeof(char *) * 4);
		// char e31[] = "1";
		// char e32[] = "2";
		// char e33[] = "3";
		// char e34[] = "4";
		// s3[0] = e31;
		// s3[1] = e32;
		// s3[2] = e33;
		// s3[3] = e34;
		// a3 = ft_strjoin(4, s3, "-");
		// printf("%s\n", a3);

	// ex04

		printf("\n==================== ex04 ====================\n");

		char n[] = "     ---+++-++w";
		// printf("%s\n", ft_atoi_b(n, "0123456789abcdef"));
		// printf("%lld\n", base_to_dec(n, "0123456789abcdef"));
		// printf("%s\n", dec_to_base(255, "01", 1));
		// char nbr[] = "     \t\n\v\f\r-+++-+++-fkkkkk";
		// char n[] = "    +---+232332ffvv";
		// printf("%s\n", ft_atoi_b(n, "0123456789abcdef"));
		// char n[] = "    ---+++--+--2";
		printf("%s\n", ft_convert_base(n, "0123456789abcdef", "g123456789"));

	// ex05

		// printf("\n==================== ex05 ====================\n");

		// char **a51 = ft_split("  a  b  c  ", "  ");
		// for (; *a51; a51++)
		// 	printf("1: %s\n", *a51);
		// printf("\n");

		// char **b51 = ft_split("  abc  ", "  ");
		// for (; *b51; b51++)
		// 	printf("%s\n", *b51);
		// printf("\n");

		// char **c51 = ft_split("    ", "  ");
		// for (; *c51; c51++)
		// 	printf("%s\n", *c51);
		// printf("\n");

		// char **d51 = ft_split("", "  ");
		// for (; *d51; d51++)
		// 	printf("%s\n", *d51);
		// printf("\n");

		// char **e51 = ft_split("abc", "");
		// for (; *e51; e51++)
		// 	printf("1: %s\n", *e51);
		// printf("\n");

}






































