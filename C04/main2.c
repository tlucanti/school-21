/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:21:05 by cstannis          #+#    #+#             */
/*   Updated: 2020/08/17 21:14:33 by cstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ex00/ft_strlen.c"
 #include "ex01/ft_putstr.c"
 #include "ex02/ft_putnbr.c"

#include <stdio.h>
#include <string.h>

void __print_array(int*__a, int n) 
{
	for (int i=0;i<n;i++) 
	{
		printf("%d ", __a[i]);
	}
	printf("\n");
}

void ft_putchar02(char c) {
    write(1, &c, 1);
}

int main()
{

	 // ex00 ft_strlen
	
        printf("\nExcercise 00: ft_strlen.c \n");
     
        int ft_strlen(char *str);

            char * a11 = "0123456789";
            printf("10 символов =  %d\n", ft_strlen(a11));
            char * a12 = "!@#$%^&*(){}[]\'\'\"\"?/|";
            printf("21 символ =  %d\n", ft_strlen(a12));
            char * a13 = "";
            printf("0 символов = %d\n", ft_strlen(a13));
            char * a14 = "\n\a\t";
            printf("tabulation\\a\\t = %d\n", ft_strlen(a14));
            char * a15 = "12355\000456";
            printf(" 12345\\0... = %d\n", ft_strlen(a15));
    
     // ex01 ft_putstr
     
            printf("\nExcercise 01: ft_putstr.c \n");
    
            void ft_putstr(char *str);
            printf("input: hello \\0W0rld\n");
            write(1, "result: ", 8);
            char *a21 = "hello \0W0rld";
            ft_putstr(a21);
            write(1, "\n", 1);
            printf("input: oh, no! Hell, \\0 yeah! gogo\n");
            write(1, "result: ", 8);
            char *a22 = "oh, no!Hell, \0 yeah! gogo";
            ft_putstr(a22);
    
    
     //ex02 ft_putnbr.c
    
      printf("\nExcercise 02: ft_putnbr.c \n");
    
     void ft_putnbr(int nb);
     ft_putnbr(42);
     ft_putchar02('\n');
     ft_putnbr(4242);
     ft_putchar02('\n');
     ft_putnbr(3);
     ft_putchar02('\n');
     ft_putnbr(5000223);
     ft_putchar02('\n');
     ft_putnbr(+2645272);
     ft_putchar02('\n');
     ft_putnbr(-2635651);
     ft_putchar02('\n');
    
//    // ex02 ft_putnbr.c
//
//        printf("\nExcercise 02: ft_putnbr.c \n");
//
//        void ft_putnbr(int nb);
//
//            for (int i = 0; i < number_count; ++i)
//            {
//                int number = numbers[i];
//                printf("number  %d:\n", number);
//                ft_putnbr(number);
//                printf("\n");
//            }
//        printf("\n");


	return 0;
}
