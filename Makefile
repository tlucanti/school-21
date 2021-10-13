# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kostya <kostya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 23:21:10 by kostya            #+#    #+#              #
#    Updated: 2021/10/13 13:47:34 by kostya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
NAME		=	philo
CFLAGS		=	-Wall -Wextra -Werror
COPTIONS	=	-O3
RM			=	rm -f
LIBRARY		=	
INCLUDE_DIR	=	include
OBJS_DIR	=	objects
# ------------------------------------------------------------------------------
SRCS		=	\
				main	\
				ft_atoi
# ------------------------------------------------------------------------------
HDRS		=	\
				philo
# ------------------------------------------------------------------------------
OBJS		=	$(addprefix ${OBJS_DIR}/,${SRCS:=.o})
DEPS		=	$(addprefix ${INCLUDE_DIR}/${HDRS:=.h})
LIBRARY		=	-pthread
LIBFT		=	

# ------------------------------------------------------------------------------
${OBJS_DIR}/%.o: %.c
	${CC}		${CFLAGS}  ${COPTIONS} -c -o $@ $<

# ------------------------------------------------------------------------------
$(NAME):		install ${OBJS}
	${CC}		-o ${NAME} ${CFLAGS} ${COPTIONS} ${OBJS} ${LIBRARY} ${LIBFT}

all:			install ${NAME}

# ------------------------------------------------------------------------------
clean:
	${MAKE}		-C ${LIBFT_DIR} clean
	${RM}		${OBJS}

# ------------------------------------------------------------------------------
fclean:			clean
	${MAKE}		-C ${LIBFT_DIR} fclean
	${RM}		${NAME}

# ------------------------------------------------------------------------------
install:
	mkdir		-p ${OBJS_DIR}

# ------------------------------------------------------------------------------
re:			fclean all

# ------------------------------------------------------------------------------
.PHONY:			all clean fclean re install
