# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 09:46:50 by fluchten          #+#    #+#              #
#    Updated: 2023/01/13 14:40:19 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = args.c \
		game_hook.c \
		main.c \
		map_init.c \
		map_parsing.c \
		map_size.c \
		player.c \
		sprites_init.c \
		sprites_set.c \
		utils.c
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

FT_PRINTF_PATH = libs/ft_printf
FT_PRINTF_LIB = ${FT_PRINTF_PATH}/libftprintf.a
FT_PRINTF_INC = ${FT_PRINTF_PATH}/includes

GNL_PATH = libs/get_next_line
GNL_LIB = ${GNL_PATH}/libftgnl.a
GNL_INC = ${GNL_PATH}/includes

all: $(NAME)

$(OBJS_DIR)/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${OBJS_DIR}
	${CC} ${CFLAGS} -I ${INC_DIR} -I ${FT_PRINTF_INC} -I ${GNL_INC} -c $< -o $@

$(NAME): $(OBJS)
	@make -C ${FT_PRINTF_PATH}
	@make -C ${GNL_PATH}
	$(CC) $(CFLAGS) $(OBJS) ${FT_PRINTF_LIB} ${GNL_LIB} $(MLX) -o $(NAME)

clean:
	@make clean -C ${FT_PRINTF_PATH}
	@make clean -C ${GNL_PATH}
	${RM} ${OBJS_DIR}

fclean:	clean
	@make fclean -C ${FT_PRINTF_PATH}
	@make fclean -C ${GNL_PATH}
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re