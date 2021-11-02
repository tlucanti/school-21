# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kostya <kostya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 23:21:10 by kostya            #+#    #+#              #
#    Updated: 2021/11/02 16:35:24 by kostya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ compiler options ------------------------------
NAME_SERVER	=	server
NAME_CLIENT	=	client
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
COPTIONS	=	-O3 -ffast-math
# ------------------------------- linker options -------------------------------
LIBRARY		=	
OBJS_DIR	=	obj
INCLUDE_DIR	=	inc
SCRS_DIR	=	src
GNL			=	
LIBFT		=	
# ------------------------------- project sorces -------------------------------
SRCS_SERVER	=	\
				server		\
				utils
# ------------------------------------------------------------------------------
SRCS_CLIENT	=	\
				client
# ------------------------------------------------------------------------------
HDRS		=	\
				color		\
				minitalk

# ======================= UNCHANGEABLE PART OF MAKEFILE ========================
# ------------------------------------------------------------------------------
RM			=	rm -f
OBJS_SERVER	=	$(addprefix ${OBJS_DIR}/,${SRCS_SERVER:=.o})
OBJS_CLIENT	=	$(addprefix ${OBJS_DIR}/,${SRCS_CLIENT:=.o})
DEPS		=	$(addprefix ${INCLUDE_DIR}/,${HDRS:=.h})
INCLUDE		=	-I ${INCLUDE_DIR}

# ------------------------------------------------------------------------------
all:			${OBJS_DIR}
	@$(MAKE)	$(NAME_SERVER) -j
	@$(MAKE)	$(NAME_CLIENT) -j

# ------------------------------------------------------------------------------
${OBJS_DIR}/%.o: ${SCRS_DIR}/%.c ${DEPS} Makefile
	${CC}		${CFLAGS} ${COPTIONS} -c -o $@ $< ${INCLUDE}

# ------------------------------------------------------------------------------
$(NAME_SERVER):	${OBJS_SERVER} ${DEPS} 
	${CC}		-o ${NAME_SERVER} ${CFLAGS} ${COPTIONS} ${OBJS_SERVER}

$(NAME_CLIENT):	${OBJS_SERVER} ${DEPS} 
	${CC}		-o ${NAME_SERVER} ${CFLAGS} ${COPTIONS} ${OBJS_SERVER}

# ------------------------------------------------------------------------------
clean:
	${RM}		${OBJS_SERVER}
	${RM}		${OBJS_CLIENT}

# ------------------------------------------------------------------------------
fclean:			clean
	${RM}		${NAME_SERVER}
	${RM}		${NAME_CLIENT}

# ------------------------------------------------------------------------------
${OBJS_DIR}:
	mkdir		-p ${OBJS_DIR}

# ------------------------------------------------------------------------------
re:				fclean all

# ------------------------------------------------------------------------------
.PHONY:			all clean fclean re
