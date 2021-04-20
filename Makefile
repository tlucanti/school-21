# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kostya <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 12:07:16 by tlucanti          #+#    #+#              #
#    Updated: 2021/03/21 18:28:20 by kostya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
NAME	=	miniRT
CFLAGS	=	-Wall -Wextra -Werror
COPTIONS=	-O3
DEPS	=	ray_traycer.h objects.h
RM		=	rm -f
AR		=	ar rcs
LIBRARY	=	-lmlx -lmlx -Imlx -lXext -lX11 -lm -lz
SRCS	=	\
	camera              circle          clean_scene_1       clean_scene_2       \
	color_1             color_2         compute_lightning   cylinder            \
	keyboard_manager    key_switcher    light               main                \
	math_utils          matrix          multiassignment     plane               \
	point_1             point_2         point_3             scene_parcer_1      \
	scene_parcer_2      scene_parcer_3  scene_parcer_4      screenshot          \
	sphere              square          ternary             trace_ray           \
	triangle            utils_1         utils_2             utils_3             \
	\
	get_next_line/get_next_line         get_next_line/get_next_line_utils

SRCS_BONUS=	\
./bonus/camera_bonus ./bonus/circle_bonus ./bonus/clean_scene_1_bonus ./bonus/clean_scene_2_bonus ./bonus/color_1_bonus ./bonus/color_2_bonus ./bonus/compute_lightning_bonus ./bonus/cylinder_bonus ./bonus/keyboard_manager_bonus ./bonus/key_switcher_bonus ./bonus/light_bonus ./bonus/main_bonus ./bonus/math_utils_bonus ./bonus/matrix_bonus ./bonus/multiassignment_bonus ./bonus/plane_bonus ./bonus/point_1_bonus ./bonus/point_2_bonus ./bonus/point_3_bonus ./bonus/scene_parcer_1_bonus ./bonus/scene_parcer_2_bonus ./bonus/scene_parcer_3_bonus ./bonus/scene_parcer_4_bonus ./bonus/screenshot_bonus ./bonus/sphere_bonus ./bonus/square_bonus ./bonus/ternary_bonus ./bonus/trace_ray_bonus ./bonus/triangle_bonus ./bonus/utils_1_bonus ./bonus/utils_2_bonus ./bonus/utils_3_bonus get_next_line/get_next_line get_next_line/get_next_line_utils
DEPS_BONUS=	ray_traycer_bonus.h objects_bonus.h

OBJS	=	${SRCS:=.o}
OBJS_BONUS=	${SRCS_BONUS:=.o}
LIBFT	=	./libft/libft.a

.c.o:
	${CC} ${CFLAGS} ${COPTIONS} -c $<	-o	${<:.c=.o}

$(NAME):	${DEPS} ${OBJS} ${LIBFT}
	${MAKE} -C libft
	${CC} -o ${NAME} ${CFLAGS} ${COPTIONS} ${OBJS} ${LIBRARY} ${LIBFT}

all:		${NAME}

f:
	${RM} test.c
	${RM} ${NAME}
	cat *.c > test.c
	${CC} ${CFLAGS} ${COPTIONS} -c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
	${CC} ${CFLAGS} ${COPTIONS} -c test.c
	${CC} -o ${NAME} ${CFLAGS} ${COPTIONS} get_next_line.o get_next_line_utils.o test.o \
		${LIBRARY} ${LIBFT}
	${RM} test.c
	${RM} get_next_line.o get_next_line_utils.o test.o	

bonus:		fclean ${OBJS_BONUS}
	${MAKE} -C libft
	${CC} -o ${NAME} ${CFLAGS} ${COPTIONS} ${OBJS_BONUS} ${LIBRARY} ${LIBFT}

clean:
	${RM} ${OBJS}
	${RM} ${OBJS_BONUS}
	${RM} get_next_line.o get_next_line_utils.o test.o

fclean: clean
	${RM} ${NAME}

re:     fclean all

.PHONY: all clean fclean re bonus f
