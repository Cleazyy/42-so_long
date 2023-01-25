# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 09:46:50 by fluchten          #+#    #+#              #
#    Updated: 2023/01/25 19:40:02 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC_DIR = -I includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = mandatory/args/args.c \
		mandatory/game/game_hook.c \
		mandatory/map/map_check.c \
		mandatory/map/map_init.c \
		mandatory/map/map_parsing.c \
		mandatory/map/map_utils.c \
		mandatory/player/player.c \
		mandatory/sprites/sprites_init.c \
		mandatory/sprites/sprites_set.c \
		mandatory/utils/utils.c \
		mandatory/main.c

SRCS_BONUS = bonus/args/args_bonus.c \
			bonus/game/game_hook_bonus.c \
			bonus/map/map_check_bonus.c \
			bonus/map/map_init_bonus.c \
			bonus/map/map_parsing_bonus.c \
			bonus/map/map_utils_bonus.c \
			bonus/player/player_bonus.c \
			bonus/sprites/sprites_init_bonus.c \
			bonus/sprites/sprites_set_bonus.c \
			bonus/sprites/sprites_set2_bonus.c \
			bonus/utils/utils_bonus.c \
			bonus/main_bonus.c

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})
OBJS_BONUS = $(addprefix ${OBJS_DIR}/, ${SRCS_BONUS:%.c=%.o})

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

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
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
	${RM} ${OBJS_DIR}

fclean:	clean
	@make fclean -C ${FT_PRINTF_PATH}
	@make fclean -C ${GNL_PATH}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re