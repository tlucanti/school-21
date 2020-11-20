NAME = libft
DIR = .
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror -I${DIR}
OPTIONS = -c
SRCS =	  ft_strnlen     ft_minmax     ft_issmth1                             \
          \
          ft_memset      ft_bzero      ft_memcpy      ft_memccpy  ft_memmove  \
          ft_memchr      ft_memcmp     ft_strlen      ft_strlcpy  ft_strlcat  \
          ft_strchr      ft_strrchr    ft_strnstr     ft_strncmp  ft_atoi     \
          ft_calloc      ft_strdup     ft_isalpha     ft_isdigit  ft_isalnum  \
          ft_isascii     ft_isprint    ft_toupper     ft_tolower              \
          \
          ft_substr      ft_strjoin    ft_strtrim     ft_split                \
          ft_itoa        ft_strmapi    ft_putchar_fd  ft_putstr_fd            \
          ft_putendl_fd  ft_putnbr_fd
          
BONUS_SRCS = ft_lstnew       ft_lstadd_front  ft_lstsize   ft_lstlast         \
             ft_lstadd_back  ft_lstdelone     ft_lstclear  ft_lstiter         \
             ft_lstmap

OBJECTS = ${SRCS:=.o}
BONUS_OBJECTS = ${BONUS_SRCS:=.o}

LIBFT_A = libft.a
DEPS = libft.h
RM = rm -rf
LIB_INIT = ar rc
LIB_NAME = libft
BUILD_FLAGS = -L. -l


.c.o: ${DEPS}
	${COMPILER} ${CFLAGS} ${OPTIONS} $< -o ${<:.c=.o}

$(NAME): ${OBJECTS}
	${LIB_INIT} ${NAME}.a ${OBJECTS}

all: ${NAME}


bonus: ${BONUS_OBJECTS}
	${LIB_INIT} ${NAME}.a ${BONUS_OBJECTS}

so:
	${COMPILER} -fPIC ${CFLAGS} ${OPTIONS} ${OBJECTS} ${BONUS_OBJECTS}
	${COMPILER} -shared -o ${NAME}.so ${OBJECTS} ${BONUS_OBJECTS} ${DEPS}

clean:
	${RM} ${OBJECTS}
	${RM} ${BONUS_OBJECTS}
	${RM} ${NAME}.a

fclean: clean
	${RM} ${LIB_NAME}.h.gch
	${RM} a.out
	${RM} ${NAME}.a

rs: fclean ${NAME} clean

re: fclean all

test:
	./test.sh

speed:
	./speed.sh

f:
	make fclean
	rm -rf libft.h.gch main.o
	g++ -std=c++17 mainpp ${SRCS:=.c} libft.h

.PHONY: all bonus clean fclean re


