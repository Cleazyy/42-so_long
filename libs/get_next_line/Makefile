# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 11:25:01 by fluchten          #+#    #+#              #
#    Updated: 2023/01/25 19:19:04 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftgnl.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS = get_next_line.c get_next_line_utils.c
SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})
OBJS_BONUS = $(addprefix ${OBJS_DIR}/, ${SRCS_BONUS:%.c=%.o})

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o $@
	
${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

bonus: ${OBJS_BONUS}
	ar -rcs ${NAME} ${OBJS_BONUS}

clean:
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re