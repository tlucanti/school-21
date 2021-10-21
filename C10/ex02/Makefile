COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c
SRCS = read_file.c funcs.c
OBJECTS = read_file.o funcs.o
NAME = ft_tail
RM = rm -rf
LIB_INIT = ar rc
LIB_NAME = tail
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

fclean: clean
	${RM} ${NAME}

rs: fclean ${NAME} clean