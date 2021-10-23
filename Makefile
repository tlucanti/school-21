# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kostya <kostya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 23:21:10 by kostya            #+#    #+#              #
#    Updated: 2021/10/22 23:24:39 by kostya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang
NAME_SERVER	=	server
NAME_CLIENT	=	client
CFLAGS		=	-Wall -Wextra 
COPTIONS	=	-O3 -ffast-math
RM			=	rm -f
LIBRARY		=	
INCLUDE_DIR	=	include
OBJS_DIR	=	objects
LIBFT		=	
MAKE_OPTS	=	-j
# ------------------------------------------------------------------------------
SRCS_SERVER	=	\
				server
SRCS_CLIENT	=	\
				client
# ------------------------------------------------------------------------------
HDRS		=	\
				minitalk	\
				color
# ------------------------------------------------------------------------------
OBJS_SERVER	=	$(addprefix ${OBJS_DIR}/,${SRCS_SERVER:=.o})
OBJS_CLIENT	=	$(addprefix ${OBJS_DIR}/,${SRCS_CLIENT:=.o})
DEPS		=	$(addprefix ${INCLUDE_DIR}/,${HDRS:=.h})
INCLUDE		=	$(addprefix -I ,${DEPS})
LIBRARY		=	
LIBFT		=	
SCRIPT_ST	=	script --flush --quiet --command '
SCRIPT_END	=	' #>/dev/null 2>&1'
# ------------------------------------------------------------------------------
${OBJS_DIR}/%.o: %.c ${DEPS} Makefile
	${CC}		${CFLAGS}  ${COPTIONS} -c -o $@ $< ${INCLUDE}

# ------------------------------------------------------------------------------
all:
	$(MAKE)		${NAME_CLIENT} ${MAKE_OPTS}
	$(MAKE)		${NAME_SERVER} ${MAKE_OPTS}

# ------------------------------------------------------------------------------
$(NAME_SERVER):	${OBJS_DIR} ${OBJS_SERVER} ${DEPS}
	${CC}		-o ${NAME_SERVER} ${CFLAGS} ${COPTIONS} ${OBJS_SERVER} ${LIBRARY} ${LIBFT}

$(NAME_CLIENT):	${OBJS_DIR} ${OBJS_CLIENT} ${DEPS}
	${CC}		-o ${NAME_CLIENT} ${CFLAGS} ${COPTIONS} ${OBJS_CLIENT} ${LIBRARY} ${LIBFT}

# ------------------------------------------------------------------------------
less:
	@script --flush --quiet --command "$(MAKE)" > /dev/null
	@less typescript
	@${RM} typescript

# ------------------------------------------------------------------------------
clean:
	${RM}		${OBJS}

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
.PHONY:			all clean fclean re ${SERVER} ${CLIENT}
