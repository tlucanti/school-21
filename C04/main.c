/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:19:34 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/17 18:19:37 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ex00/ft_strlen.c"
#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"
#include "ex03/ft_atoi.c"
#include "ex04/ft_putnbr_base.c"
#include "ex05/ft_atoi_base.c"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// gcc -Wall -Wextra -Werror main.c && ./a.out

int main() {

	// ex00

		printf("\n==================== ex00 ====================\n");
		char a1[4] = "qwe\0";
		char b1[1] = "\0";
		printf("%lu, %lu -> %d, %d\n", strlen(a1), strlen(b1), ft_strlen(a1), ft_strlen(b1));

	// ex01

		printf("\n==================== ex01 ====================\n");
		char a2[4] = "qwe\0";
		char b2[1] = "\0";
		ft_putstr(a2);
		printf(" <- %s\n", a2);
		ft_putstr(b2);
		printf(" <- nothing\n");

	// ex02

		printf("\n==================== ex02 ====================\n");
		ft_putnbr(-2147483648);
		printf(" <- %ld\n", -2147483648);
		ft_putnbr(2147483647);
		printf(" <- %d\n", 2147483647);
		ft_putnbr(0);
		printf(" <- %d\n", 0);
		ft_putnbr(2030);
		printf(" <- %d\n", 2030);
		ft_putnbr(1000000000);
		printf(" <- %d\n", 1000000000);

	// ex03

		printf("\n==================== ex03 ====================\n");
		char a3[] = "   ---+--+12-34ab567";
		char b3[] = "   ---+ks +se-s e___grsg['=r-gs-gr+4grs8srg&sr863w9 sgr80";
		char c3[] = "     -+-+-+-+-+-+-+-+-+-1";
		char d3[] = "       ----++--0";
		char e3[1] = "\0";
		char f3[] = "    +-+-+-+-+-";
		char g3[] = "     ";
		char h3[] = "-2147483648";
		printf("-1234, 0, 1, 0, 0, 0, 0, -2147483648 -> %d, %d, %d, %d, %d, %d, %d, %d\n", ft_atoi(a3), ft_atoi(b3), ft_atoi(c3), ft_atoi(d3), ft_atoi(e3), ft_atoi(f3), ft_atoi(g3), ft_atoi(h3));
	
	// ex04

		printf("\n==================== ex04 ====================\n");

		char a4[] = "01";
		ft_putnbr_base(1024, a4);
		write(1, " <- 10000000000\n", 16);

		char b4[] = "01";
		ft_putnbr_base(1, b4);
		write(1, " <- 1\n", 6);

		char c4[] = "!drw oleH";
		ft_putnbr_base(381367044, c4);
		write(1, " <- Helo wrd!\n", 14);

		char d4[] = "1";
		ft_putnbr_base(123, d4);
		write(1, " <- nothing\n", 12);

		char e4[0] = "";
		ft_putnbr_base(123, e4);
		write(1, " <- nothing\n", 12);

		char f4[] = "-+";
		ft_putnbr_base(123, f4);
		write(1, " <- nothing\n", 12);

		char g4[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_?=><abcdefghijklmnopqrstuvwxyz";
		ft_putnbr_base(2147483647, g4);
		write(1, " <- k6ry1\n", 10);

		char h4[] = "01";
		ft_putnbr_base(-2147483648, h4);
		write(1, " <- -1[31 zeros]\n", 17);

		char j4[] = "01";
		ft_putnbr_base(0, j4);
		write(1, " <- 0\n", 6);

	// ex05

		printf("\n==================== ex05 ====================\n");

		char a5[] = "01";
		char a51[] = "     ----10000000000werewr";
		printf("%d <- 1024\n", ft_atoi_base(a51, a5));
 
		char b5[] = "01";
		char b51[] = "     -+-+-+-+-+-+-+-+-+-1";
		printf("%d <- 1\n", ft_atoi_base(b51, b5));

		char c5[] = "!drw oleH";
		char c51[] = "rrwrww!rd!";
		printf("%d <- 876543210\n", ft_atoi_base(c51, c5));

		char d5[] = "1";
		char d51[] = "  +123";
		printf("%d <- 0\n", ft_atoi_base(d51, d5));

		char e5[0] = "";
		char e51[] = "  +123";
		printf("%d <- 0\n", ft_atoi_base(e51, e5));

		char f5[] = "-+";
		char f51[] = "  +123";
		printf("%d <- 0\n", ft_atoi_base(f51, f5));

		char g5[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_?=><abcdefghijklmnopqrstuvwxyz";
		char g51[] = "   --+-+-2147483647ks +se-s e___grsg['=r-gs-gr+4grs8srg&sr863w9 sgr80";
		printf("%d <- -1458356516\n", ft_atoi_base(g51, g5));

		char h5[] = "01";
		char h51[] = "-10000000000000000000000000000000";
		printf("%d <- -2147483648\n", ft_atoi_base(h51, h5));

		char i5[] = "01";
		char i51[] = "       ----++--0";
		printf("%d <- 0\n", ft_atoi_base(i51, i5));

		char j5[] = "   ---+--+1234ab567";
		char j51[] = "0123456789";
		printf("%d <- -1234\n", ft_atoi_base(j5, j51));

		char k5[] = "   ---+ks +se-s e___grsg['=r-gs-gr+4grs8srg&sr863w9 sgr80";
		char k51[] = "0123456789";
		printf("%d <- 0\n", ft_atoi_base(k5, k51));

		char l5[1] = "\0";
		char l51[] = "0123456789";
		printf("%d <- 0\n", ft_atoi_base(l5, l51));

		char m5[] = "    +-+-+-+-+-";
		char m51[] = "0123456789";
		printf("%d <- 0\n", ft_atoi_base(m5, m51));

		char n5[] = "     ";
		char n51[] = "0123456789";
		printf("%d <- 0\n", ft_atoi_base(n5, n51));

		char o5[] = "-2147483648";
		char o51[] = "0123456789";
		printf("%d <- -2147483648\n", ft_atoi_base(o5, o51));

		char p5[] = "dead";
		char p51[] = "0123456789abcdef";
		printf("%d <- 57005\n", ft_atoi_base(p5, p51));

}

/*

norminette -R CheckForbiddenSourceHeader ex00/ft_strlen.c
norminette -R CheckForbiddenSourceHeader ex01/ft_putstr.c
norminette -R CheckForbiddenSourceHeader ex02/ft_putnbr.c
norminette -R CheckForbiddenSourceHeader ex03/ft_atoi.c
norminette -R CheckForbiddenSourceHeader ex04/ft_putnbr_base.c
norminette -R CheckForbiddenSourceHeader ex05/ft_atoi_base.c

*/




























