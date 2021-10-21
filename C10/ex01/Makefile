# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/25 17:30:06 by tlucanti          #+#    #+#              #
#    Updated: 2020/08/25 17:30:07 by tlucanti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c
SRCS = ft_cat.c print_file.c
OBJECTS = ft_cat.o print_file.o
NAME = ft_cat
RM = rm -rf

${NAME}:
	${COMPILER} ${CFLAGS} ${OPTIONS} ${SRCS}
	${COMPILER} ${OBJECTS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

rs: fclean ${NAME}
