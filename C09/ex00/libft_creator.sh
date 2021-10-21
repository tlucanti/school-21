gcc -o -Wall -Wextra -Werror ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar -r  ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o libft.a
ranlib libft.a
rm ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
