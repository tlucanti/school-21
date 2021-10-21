# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/30 18:36:01 by tlucanti          #+#    #+#              #
#    Updated: 2020/08/30 18:36:02 by tlucanti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c

SRCS = parcer.c push.c reallol.c gen_push.c push_out_list.c request.c cleaners.c ft_check_num.c ft_decimals.c ft_number.c
OBJECTS = parcer.o push.o reallol.o gen_push.o push_out_list.o request.o cleaners.o ft_check_num.o ft_decimals.o ft_number.o

NAME = rush-02
RM = rm -rf
LIB_INIT = ar rc
LIB_NAME = rush
RUN_LIB = ranlib
MAIN_SRC = main.c
MAIN_OBJ = main.o
BUILD_FLAGS = -L. -l

${NAME}:
	${COMPILER} ${CFLAGS} ${OPTIONS} ${SRCS}
	${LIB_INIT} lib${LIB_NAME}.a ${OBJECTS}
	${RUN_LIB} lib${LIB_NAME}.a
	${COMPILER} ${CFLAGS} ${OPTIONS} ${MAIN_SRC}
	${COMPILER} ${MAIN_OBJ} ${BUILD_FLAGS} ${LIB_NAME} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJECTS}
	${RM} ${MAIN_OBJ}
	${RM} lib${LIB_NAME}.a

fclean: clean
	${RM} ${NAME}

rs: fclean all
	make clean
