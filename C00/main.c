/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 19:40:16 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/12 19:53:54 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_putchar.c"
#include "ex01/ft_print_alphabet.c"
#include "ex02/ft_print_reverse_alphabet.c"
 #include "ex03/ft_print_numbers.c"
 #include "ex04/ft_is_negative.c"
 #include "ex05/ft_print_comb.c"
 #include "ex06/ft_print_comb2.c"
 #include "ex07/ft_putnbr.c"
//#include "ex08/ft_print_combn.c"

int main() {
	
	// ex00
	// void void ft_putchar(char c)

		//ft_putchar('g');
		//ft_putchar(' ');

	// ex01
	// void ft_print_alphabet(void)

		//ft_print_alphabet();

	// ex02
	// void ft_print_reverse_alphabet(void)

		//ft_print_reverse_alphabet();

	// ex03
	// void ft_print_numbers(void)

		//ft_print_numbers();

	// ex04
	// void ft_is_negative(int n)

		//ft_is_negative(0);
		//ft_is_negative(-2147483648);
		//ft_is_negative(2147483647);

	// ex05
	// void ft_print_comb(void)

		//ft_print_comb();

	// ex06
	// void ft_print_comb2(void)

		 //ft_print_comb2();
 
	// ex07
	// void ft_putnbr(int nb)

		ft_putnbr(-2147483648);
		write(1, "\n", 1);
		ft_putnbr(2147483647);
		write(1, "\n", 1);
		ft_putnbr(0);
		write(1, "\n", 1);
		ft_putnbr(2030);
		write(1, "\n", 1);
		ft_putnbr(1000000000);

	// ex08
	// void ft_print_combn(int n);
		
		// ft_print_combn(1);
		// write(1, "\n\n", 2);
		// ft_print_combn(2);
		// write(1, "\n\n\nn", 2);
		// ft_print_combn(3);
		// write(1, "\n\n\n\n", 4);
		// ft_print_combn(9);

	return 0;
}

/*

norminette -R CheckForbiddenSourceHeader ex00/ft_putchar.c
norminette -R CheckForbiddenSourceHeader ex01/ft_print_alphabet.c
norminette -R CheckForbiddenSourceHeader ex02/ft_print_reverse_alphabet.c
norminette -R CheckForbiddenSourceHeader ex03/ft_print_numbers.c
norminette -R CheckForbiddenSourceHeader ex04/ft_is_negative.c
norminette -R CheckForbiddenSourceHeader ex05/ft_print_comb.c
norminette -R CheckForbiddenSourceHeader ex06/ft_print_comb2.c
norminette -R CheckForbiddenSourceHeader ex07/ft_putnbr.c
norminette -R CheckForbiddenSourceHeader ex08/ft_print_combn.c

*/












































