# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 08:04:05 by fluchten          #+#    #+#              #
#    Updated: 2023/01/09 10:46:18 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INC_DIR = includes
SRCS_DIR = srcs

SRCS = ft_printf.c ft_printf_utils1.c ft_printf_utils2.c
OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS:%.c=%.o))

all: $(NAME)

%.o: %.c
	${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o $@
	
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re