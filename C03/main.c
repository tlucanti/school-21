/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 11:47:03 by tlucanti          #+#    #+#             */
/*   Updated: 2020/08/16 11:47:08 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ex00/ft_strcmp.c"
// #include "ex01/ft_strncmp.c"
// #include "ex02/ft_strcat.c"
// #include "ex03/ft_strncat.c"
// #include "ex04/ft_strstr.c"
#include "ex05/ft_strlcat.c"

#include <stdio.h>
#include <string.h>

int main() {

	// ex00 (ft_strcmp)

		// printf("\n========== ex00 ==========\n");
		// char a0[] = "abc\0";
		// char b0[] = "abd\0";
		// char c0[] = "abb\0";
		// char d0[] = "abcd\0";
		// char e0[] = "abc\0";
		// char f0[] = "\0";
		// printf("<0, >0, <0, >0, 0 >0 -> %d, %d, %d, %d, %d, %d\n",ft_strcmp(a0,b0),ft_strcmp(a0,c0),ft_strcmp(a0,d0),ft_strcmp(d0,a0),ft_strcmp(a0,e0),ft_strcmp(a0,f0));
	
	// ex01 (ft_strncmp)

		// printf("\n========== ex01 ==========\n");
		// char a1[] = "abc\0";
		// char b1[] = "abd\0";
		// char c1[] = "abb\0";
		// char d1[] = "abcd\0";
		// char e1[] = "abc\0";
		// char f1[] = "\0";
		// printf("<0, >0, 0, >0, 0 >0 -> %d, %d, %d, %d, %d, %d\n",ft_strncmp(a1,b1,3u),ft_strncmp(a1,c1,4u),ft_strncmp(a1,d1,3u),ft_strncmp(d1,a1,4u),ft_strncmp(a1,e1,4u),ft_strncmp(a1,f1,1u));
	
	// ex02 (ft_strcat)
		
		// printf("\n========== ex02 ==========\n");
		// char a2[15] = "qwe";
		// char b2[4] = "rty";
		// char c2[10] = "abc";
		// char d2[4] = "";
		// char e2[4] = "abc";
		// char f2[1] = "";
		// printf("qwerty\nabc\nabc\nvvv\n%s\n%s\n%s\n",ft_strcat(a2,b2),ft_strcat(d2,c2),ft_strcat(e2,f2));
	
	// ex03 (ft_strncat)
		
		// printf("\n========== ex03 ==========\n");
		// char a3[15] = "qwe";
		// char b3[4] = "rty";
		// char c3[10] = "abcde";
		// char d3[6] = "";
  //   	char e3[4] = "abc";
  //   	char f3[1] = "";
		// printf("qwert\nab\nabc\nvvv\n%s\n%s\n%s\n",ft_strncat(a3,b3,2u),ft_strncat(d3,c3,2u),ft_strncat(e3,f3,1u));
	
	// ex04 (ft_strstr)
		
		// printf("\n========== ex04 ==========\n");
		// char a4[] = "aaaabaaa";
		// char f4[] = "aaabaaa";
		// printf("1: aaabaaa\nvvv\n%d: %s\n", (int)(ft_strstr(a4, f4) - a4), ft_strstr(a4, f4));
	
	// ex05 ft_strlcat
		
		// printf("\n========== ex05 ==========\n");
		// char a5[15] = "qwe";
		// char b5[4] = "rty";
		// char c5[10] = "abcde";
		// char d5[6] = "";
  //   	char e5[4] = "abc";
  //   	char f5[1] = "";
  //   	int a51 = strlcat(a5,b5,7u);
  //   	int b51 = strlcat(d5,c5,3u);
  //   	int c51 = strlcat(e5,f5,4u);
		// printf("6: qwerty\n5: ab\n3: abc\nvvv\n%d: %s\n%d: %s\n%d: %s\n",a51,a5,b51,d5,c51,e5);

char a[10] = "123";
char b[] = "4567";
printf("%d\n", ft_strlcat(a, b, 5));
printf("%s", a);

	}

/*

norminette -R CheckForbiddenSourceHeader ex00/ft_strcmp.c
norminette -R CheckForbiddenSourceHeader ex01/ft_strncmp.c
norminette -R CheckForbiddenSourceHeader ex02/ft_strcat.c
norminette -R CheckForbiddenSourceHeader ex03/ft_strncat.c
norminette -R CheckForbiddenSourceHeader ex04/ft_strstr.c
norminette -R CheckForbiddenSourceHeader ex05/ft_strlcat.c

*/


















