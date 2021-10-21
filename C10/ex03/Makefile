COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c
SRCS = dec2hex.c file_cat.c err.c put_np_char.c
OBJECTS = dec2hex.o file_cat.o err.o put_np_char.o
NAME = ft_hexdump
RM = rm -rf
LIB_INIT = ar rc
LIB_NAME = hexdump
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