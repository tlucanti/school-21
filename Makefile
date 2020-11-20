COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c -Ofast
SRCS =	  ft_strnlen     ft_minmax     ft_issmth1     ft_issmth2              \
          \
          ft_memset      ft_bzero      ft_memcpy      ft_memccpy  ft_memmove  \
          ft_memchr      ft_memcmp     ft_strlen      ft_strlcpy  ft_strlcat  \
          ft_strchr      ft_strrchr    ft_strnstr     ft_strncmp  ft_atoi     \
          ft_calloc      ft_strdup                                            \
          \
          ft_substr      ft_strjoin    ft_strtrim     ft_split                \
          ft_itoa        ft_strmapi    ft_putchar_fd  ft_putstr_fd            \
          ft_putendl_fd  ft_putnbr_fd
          
BONUS_SRCS = ft_lstnew       ft_lstadd_front  ft_lstsize   ft_lstlast         \
             ft_lstadd_back  ft_lstdelone     ft_lstclear  ft_lstiter         \
             ft_lstmap

NAME = libft
RM = rm -rf
LIB_INIT = ar rc
LIB_NAME = libft
RUN_LIB = ranlib
BUILD_FLAGS = -L. -l

${NAME}:
	${COMPILER} ${CFLAGS} ${OPTIONS} ${SRCS:=.c}
	${LIB_INIT} ${LIB_NAME}.a ${SRCS:=.o}
	${RUN_LIB} ${LIB_NAME}.a

all: ${NAME}

bonus:
	${COMPILER} ${CFLAGS} ${OPTIONS} ${SRCS:=.c} ${BONUS_SRCS:=.c}
	${LIB_INIT} ${LIB_NAME}.a ${SRCS:=.o} ${BONUS_SRCS:=.o}
	${RUN_LIB} ${LIB_NAME}.a

so:
	${COMPILER} -fPIC ${CFLAGS} ${OPTIONS} ${SRCS:=.c} ${BONUS_SRCS:=.c}
	${COMPILER} -shared -o ${NAME}.so ${SRCS:=.o} ${BONUS_SRCS:=.o} ${NAME}.h

clean:
	${RM} ${SRCS:=.o}
	${RM} ${BONUS_SRCS:=.o}
	${RM} ${LIB_NAME}.a

fclean: clean
	${RM} ${LIB_NAME}.h.gch
	${RM} a.out
	${RM}
	${RM} ${NAME}

rs: fclean ${NAME} clean

re: fclen clean all

test:
	./test.sh

speed:
	./speed.sh

f:
	make fclean
	rm -rf libft.h.gch main.o
	g++ -std=c++17 mainpp ${SRCS:=.c} libft.h

  
