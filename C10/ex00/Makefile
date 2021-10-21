# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/25 17:29:44 by tlucanti          #+#    #+#              #
#    Updated: 2020/08/25 17:29:51 by tlucanti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c
SRCS = ft_display_file.c
OBJECTS = ft_display_file.o
NAME = ft_display_file
RM = rm -rf

${NAME}:
	${COMPILER} ${CFLAGS} ${OPTIONS} ${SRCS}
	${COMPILER} ${OBJECTS} -o ${NAME}

all:
	${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}
