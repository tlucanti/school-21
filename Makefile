# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 12:07:16 by tlucanti          #+#    #+#              #
#    Updated: 2021/01/25 12:07:20 by tlucanti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
NAME	=	libftprintf.a
CFLAGS	=	-Wall -Wextra -Werror
HDRS	=	ft_printf.h
RM		=	rm -f
SRCS	=	ft_format_parcers.c		ft_get_format.c		ft_syms.c			ft_printf.c			ft_putaddressf.c		\
			ft_putcharf.c 			ft_puthexnbrf.c		ft_putnbrf.c		ft_putnstrf.c		ft_putoctnbrf.c			\
			ft_strlen_printf.c		ft_putfloatnbr.c	ft_putfloatnbr_f.c	ft_putfloatnbr_e.c	ft_putfloatnbr_g.c		\
			ft_float_utils1.c		ft_float_utils2.c
OBJS	=	${SRCS:.c=.o}
AR		=	ar	rcs

.c.o:		${HDRS}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


all:		${NAME}

$(NAME):	${OBJS} ${HDRS}
	${AR} ${NAME} ${OBJS}

bonus:		${OBJS} ${HDRS}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

main: ${OBJS} ${HDRS}
	${CC} -c main.c
	${CC} ${CFLAGS} ${OBJS} main.o
	${RM} main.o

re:		fclean all

.PHONY:	all clean fclean re
