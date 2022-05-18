# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dguet <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 22:46:17 by dguet             #+#    #+#              #
#    Updated: 2022/05/12 14:32:32 by dguet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	so_long.c move_player.c utils.c load_animations.c

OBJS			=	${addprefix srcs/, ${SRCS:.c=.o}}

#OBJS_BONUS		=	${addprefix srcs/bonus/,${SRCS_BONUS:.c=.o}}

LIB_FLAGS		=	-L libft -L mlx_linux

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes -I libft -I mlx_linux

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -g

RM				=	rm -rf

NAME			=	so_long

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -sC libft
					make -sC mlx_linux
					${CC} ${CFLAGS} ${LIB_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all				:	${NAME}

#bonus			:	${OBJS_BONUS}
#					make -C libft
#					make -C mlx_linux
#					${CC} ${CFLAGS} ${LIB_FLAGS} ${OBJS_BONUS} -o ${NAME} -lft ${MLX_FLAGS}

val				:	${NAME}
					valgrind \
					--leak-check=full --tool=memcheck \
					--show-reachable=yes \
					--track-fds=yes \
					--errors-for-leak-kinds=all \
					--show-leak-kinds=all ./${NAME}

clean			:
					make clean -sC libft
					make clean -sC mlx_linux
					${RM} ${OBJS} ${OBJS_BONUS}

fclean			:	clean
					make fclean -sC libft
					${RM} ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
