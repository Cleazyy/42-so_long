# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 11:25:01 by fluchten          #+#    #+#              #
#    Updated: 2023/01/15 13:00:28 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftgnl.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INC_DIR = includes
SRCS_DIR = srcs

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(addprefix ${SRCS_DIR}/, ${SRCS:%.c=%.o})

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o $@
	
${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re