CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c

SRCS = alg print_out parcer checkers find_max

NAME = BSQ
RM = rm -rf
LIB_INIT = ar rc
LIB_NAME = bsq
RUN_LIB = ranlib
MAIN_SRC = main
BUILD_FLAGS = -L. -l

${NAME}:
	${CC} ${CFLAGS} ${OPTIONS} ${SRCS:=.c}
	${LIB_INIT} lib${LIB_NAME}.a ${SRCS:=.o}
	${RUN_LIB} lib${LIB_NAME}.a
	${CC} ${CFLAGS} ${OPTIONS} ${MAIN_SRC}.c
	${CC} ${MAIN_SRC}.c ${BUILD_FLAGS} ${LIB_NAME} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${SRCS:=.o}
	${RM} ${MAIN_SRC:=.o}
	${RM} lib${LIB_NAME}.a

fclean: clean
	${RM} ${NAME}

rs: fclean all
	./map_gen.pl 100 100 10 > map
	make clean
