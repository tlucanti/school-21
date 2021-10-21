# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/23 20:42:30 by tlucanti          #+#    #+#              #
#    Updated: 2020/08/23 20:42:50 by tlucanti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
HEAD_LIB =  ./srcs/
HEAD_LIB =  ./includes/
LIB =   ${HEAD_LIB}ft.h
SRCS =  ${HEAD_LIB}ft.h ${HEAD_LIB}ft_putchar.c ${HEAD_LIB}ft_swap.c ${HEAD_LIB}ft_putstr.c ${HEAD_LIB}ft_strlen.c ${HEAD_LIB}ft_strcmp.c
OBJS =  ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
OBJ =   ${SRCS:.c=.o}
OPTIONS =   -c -I{LIB}
CC  =   cc
RM  =   rm -f
CFLAGS  =   -Wall -Wextra -Werror
${NAME}:    {GCC} {FLAGS} {OPTIONS} {SRCS}
            mv ${OBJS} {HEAD_LIB}
            ar rc ${NAME} {OBJ}
            ranlib ${name}
all:        ${NAME}
clean:
            ${RM} ${OBJS}
fclean:     clean
            ${RM} ${NAME}
re:         fclean all
.PHONY:     all clean fclean
