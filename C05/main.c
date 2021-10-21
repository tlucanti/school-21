
#include "ex00/ft_iterative_factorial.c"
#include "ex01/ft_recursive_factorial.c"
#include "ex02/ft_iterative_power.c"
#include "ex03/ft_recursive_power.c"
#include "ex04/ft_fibonacci.c"
#include "ex05/ft_sqrt.c"
#include "ex06/ft_is_prime.c"
#include "ex07/ft_find_next_prime.c"
#include "ex08/ft_ten_queens_puzzle.c"

#include <stdio.h>

int main() {

	// ex00 (int ft_iterative_factorial(int nb))

		printf("\n==================== ex00 ======================\n");

		printf("0 -> %d\n", ft_iterative_factorial(-1));
		printf("1 -> %d\n", ft_iterative_factorial(0));
		printf("1 -> %d\n", ft_iterative_factorial(1));
		printf("2 -> %d\n", ft_iterative_factorial(2));
		printf("6 -> %d\n", ft_iterative_factorial(3));
		printf("24 -> %d\n", ft_iterative_factorial(4));
		printf("120 -> %d\n", ft_iterative_factorial(5));
		printf("720 -> %d\n", ft_iterative_factorial(6));
		printf("5040 -> %d\n", ft_iterative_factorial(7));
		printf("40320 -> %d\n", ft_iterative_factorial(8));
		printf("362880 -> %d\n", ft_iterative_factorial(9));
		printf("3628800 -> %d\n", ft_iterative_factorial(10));
		printf("39916800 -> %d\n", ft_iterative_factorial(11));

	// ex01 (int ft_recursive_factorial(int nb))

		printf("\n==================== ex01 ======================\n");

		printf("0 -> %d\n", ft_recursive_factorial(-1));
		printf("1 -> %d\n", ft_recursive_factorial(0));
		printf("1 -> %d\n", ft_recursive_factorial(1));
		printf("2 -> %d\n", ft_recursive_factorial(2));
		printf("6 -> %d\n", ft_recursive_factorial(3));
		printf("24 -> %d\n", ft_recursive_factorial(4));
		printf("120 -> %d\n", ft_recursive_factorial(5));
		printf("720 -> %d\n", ft_recursive_factorial(6));
		printf("5040 -> %d\n", ft_recursive_factorial(7));
		printf("40320 -> %d\n", ft_recursive_factorial(8));
		printf("362880 -> %d\n", ft_recursive_factorial(9));
		printf("3628800 -> %d\n", ft_recursive_factorial(10));
		printf("39916800 -> %d\n", ft_recursive_factorial(11));

	// ex02 (int ft_iterative_power(int nb, int power))
	// watch out for timeout

		printf("\n==================== ex02 ======================\n");

		printf("1024 -> %d\n", ft_iterative_power(2, 10));
		printf("-512 -> %d\n", ft_iterative_power(-2, 9));
		printf("1024 -> %d\n", ft_iterative_power(-2, 10));
		printf("1 -> %d\n", ft_iterative_power(-2147483648, 0));
		printf("1 -> %d\n", ft_iterative_power(2147483647, 0));
		printf("0 -> %d\n", ft_iterative_power(123, -5));
		printf("0 -> %d\n", ft_iterative_power(0, 2147483647));
		printf("1 -> %d\n", ft_iterative_power(1, 2147483647));
		printf("1 -> %d\n", ft_iterative_power(0, 0));
		
	// ex03 (int ft_recursive_power(int nb, int power))
	// watch out for timeout

		printf("\n==================== ex03 ======================\n");
	
		printf("1024 -> %d\n", ft_recursive_power(2, 10));
		printf("-512 -> %d\n", ft_recursive_power(-2, 9));
		printf("1024 -> %d\n", ft_recursive_power(-2, 10));
		printf("1 -> %d\n", ft_recursive_power(-2147483648, 0));
		printf("1 -> %d\n", ft_recursive_power(2147483647, 0));
		printf("0 -> %d\n", ft_recursive_power(123, -5));
		printf("0 -> %d\n", ft_recursive_power(0, 2147483647));
		printf("1 -> %d\n", ft_recursive_power(1, 2147483647));

		printf("1 -> %d\n", ft_recursive_power(0, 0));
		printf("1 -> %d\n", ft_recursive_power(1, -1));
		printf("-1 -> %d\n", ft_recursive_power(-1, -1));

	// ex04 (int ft_fibonacci(int index))
	// watch out for timeout

		printf("\n==================== ex04 ======================\n");

		printf("-1 -> %d\n", ft_fibonacci(-1));
		printf("0 -> %d\n", ft_fibonacci(0));
		printf("1 -> %d\n", ft_fibonacci(1));
		printf("1 -> %d\n", ft_fibonacci(2));
		printf("2 -> %d\n", ft_fibonacci(3));
		printf("3 -> %d\n", ft_fibonacci(4));
		printf("6765 -> %d\n", ft_fibonacci(20));
		printf("1836311903 -> %d\n", ft_fibonacci(46));
		// printf("1884755131 -> %d\n", ft_fibonacci(1000000));


	// ex05 (int ft_sqrt(int nb))

		printf("\n==================== ex05 ======================\n");

		printf("0 -> %d\n", ft_sqrt(-1));
		printf("0 -> %d\n", ft_sqrt(0));
		printf("1 -> %d\n", ft_sqrt(1));
		printf("0 -> %d\n", ft_sqrt(2));
		printf("0 -> %d\n", ft_sqrt(3));
		printf("2 -> %d\n", ft_sqrt(4));
		printf("0 -> %d\n", ft_sqrt(-1));
		printf("0 -> %d\n", ft_sqrt(-1));
		printf("12345 -> %d\n", ft_sqrt(152399025));
		printf("0 -> %d\n", ft_sqrt(152399026));
		printf("46340 -> %d\n", ft_sqrt(2147395600));

	// ex06 (int ft_is_prime(int nb))
	// watch out for timeout

		printf("\n==================== ex06 ======================\n");

		printf("0 -> %d\n", ft_is_prime(-1));
		printf("0 -> %d\n", ft_is_prime(0));
		printf("0 -> %d\n", ft_is_prime(1));
		printf("1 -> %d\n", ft_is_prime(2));
		printf("1 -> %d\n", ft_is_prime(3));
		printf("0 -> %d\n", ft_is_prime(4));
		printf("1 -> %d\n", ft_is_prime(5));
		printf("1 -> %d\n", ft_is_prime(80167));
		printf("0 -> %d\n", ft_is_prime(166538989));
		printf("1 -> %d\n", ft_is_prime(2147483629));
		printf("1 -> %d\n", ft_is_prime(2147483647));

	// ex07 (int ft_find_next_prime(int nb))
	// watch out for timeout

		printf("\n==================== ex07 ======================\n");

		printf("2 -> %d\n", ft_find_next_prime(-1));
		printf("2 -> %d\n", ft_find_next_prime(0));
		printf("2 -> %d\n", ft_find_next_prime(1));
		printf("2 -> %d\n", ft_find_next_prime(2));
		printf("3 -> %d\n", ft_find_next_prime(3));
		printf("5 -> %d\n", ft_find_next_prime(4));
		printf("5 -> %d\n", ft_find_next_prime(5));
		printf("80167 -> %d\n", ft_find_next_prime(80167));
		printf("166538993 -> %d\n", ft_find_next_prime(166538989));
		printf("2147483629 -> %d\n", ft_find_next_prime(2147483629));
		printf("2147483647 -> %d\n", ft_find_next_prime(2147483647));

	// ex08 (int ft_ten_queens_puzzle(void))

		printf("\n==================== ex08 ======================\n");

		printf("%d\n", ft_ten_queens_puzzle());

}


/*

norminette -R CheckForbiddenSourceHeader ex00/ft_iterative_factorial.c
norminette -R CheckForbiddenSourceHeader ex01/ft_recursive_factorial.c
norminette -R CheckForbiddenSourceHeader ex02/ft_iterative_power.c
norminette -R CheckForbiddenSourceHeader ex03/ft_recursive_power.c
norminette -R CheckForbiddenSourceHeader ex04/ft_fibonacci.c
norminette -R CheckForbiddenSourceHeader ex05/ft_sqrt.c
norminette -R CheckForbiddenSourceHeader ex06/ft_is_prime.c
norminette -R CheckForbiddenSourceHeader ex07/ft_find_next_prime.c
norminette -R CheckForbiddenSourceHeader ex08/ft_ten_queens_puzzle.c

*/














































