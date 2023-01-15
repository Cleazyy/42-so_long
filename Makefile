# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 09:46:50 by fluchten          #+#    #+#              #
#    Updated: 2023/01/15 11:06:16 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INC_DIR = -I includes
SRCS_DIR = srcs/mandatory
SRCS_DIR_BONUS = srcs/bonus

SRCS = args.c \
		game_hook.c \
		main.c \
		map_check.c \
		map_init.c \
		map_parsing.c \
		map_utils.c \
		player.c \
		sprites_init.c \
		sprites_set.c \
		utils.c

SRCS_BONUS = args_bonus.c \
			game_hook_bonus.c \
			main_bonus.c \
			map_check_bonus.c \
			map_init_bonus.c \
			map_parsing_bonus.c \
			map_utils_bonus.c \
			player_bonus.c \
			sprites_init_bonus.c \
			sprites_set_bonus.c \
			utils_bonus.c

OBJS = $(addprefix ${SRCS_DIR}/, ${SRCS:%.c=%.o})
OBJS_BONUS = $(addprefix ${SRCS_DIR_BONUS}/, ${SRCS_BONUS:%.c=%.o})

FT_PRINTF_PATH = libs/ft_printf
FT_PRINTF_LIB = ${FT_PRINTF_PATH}/libftprintf.a
FT_PRINTF_INC = -I ${FT_PRINTF_PATH}/includes

GNL_PATH = libs/get_next_line
GNL_LIB = ${GNL_PATH}/libftgnl.a
GNL_INC = -I ${GNL_PATH}/includes

MLX_PATH = libs/mlx
MLX_LIB	= ${MLX_PATH}/libmlx.a ${MLX_FLAGS}
MLX_INC = -I ${MLX_PATH}/
MLX_FLAGS = -framework OpenGL -framework AppKit

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} ${INC_DIR} ${FT_PRINTF_INC} ${GNL_INC} ${MLX_INC} -c $< -o $@

${NAME}: ${OBJS}
	@make -C ${FT_PRINTF_PATH}
	@make -C ${GNL_PATH}
	@make -C ${MLX_PATH}
	${CC} ${CFLAGS} ${OBJS} ${FT_PRINTF_LIB} ${GNL_LIB} ${MLX_LIB} -o ${NAME}

bonus: ${OBJS_BONUS}
	@make -C ${FT_PRINTF_PATH}
	@make -C ${GNL_PATH}
	@make -C ${MLX_PATH}
	${CC} ${CFLAGS} ${OBJS_BONUS} ${FT_PRINTF_LIB} ${GNL_LIB} ${MLX_LIB} -o ${NAME}

clean:
	@make clean -C ${FT_PRINTF_PATH}
	@make clean -C ${GNL_PATH}
	@make clean -C ${MLX_PATH}
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:	clean
	@make fclean -C ${FT_PRINTF_PATH}
	@make fclean -C ${GNL_PATH}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re