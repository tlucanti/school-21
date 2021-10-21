# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 16:21:50 by tlucanti          #+#    #+#              #
#    Updated: 2020/08/26 16:21:53 by tlucanti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c
SRCS = atoi.c operators.c print_int.c
OBJECTS = atoi.o operators.o print_int.o
NAME = do-op
RM = rm -rf
LIB_INIT = ar rc
LIB_NAME = do_op
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

test:
	${COMPILER} ${OPTIONS} ${SRCS}
	${LIB_INIT} lib${LIB_NAME}.a ${OBJECTS}
	${RUN_LIB} lib${LIB_NAME}.a
	${COMPILER} ${OPTIONS} ${MAIN_SRC}
	${COMPILER} ${MAIN_OBJ} ${BUILD_FLAGS} ${LIB_NAME} -o ${NAME}
