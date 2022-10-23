# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhaukile < jhaukile@student.hive.fi>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 10:36:30 by jhaukile          #+#    #+#              #
#    Updated: 2022/09/27 11:51:01 by jhaukile         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a
LIBFTINCL = libft/
MLXLIB = /usr/local/lib
MLXINCL = /usr/local/include
FRACTOLINCL = ./
SRCS = main.c fractal.c keys1.c tools.c	tools2.c
OBJS = $(SRCS:.c=.o)
MLXLINK = -lmlx -framework OpenGL -framework Appkit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -I $(LIBFTINCL) -I $(MLXINCL) \
	-I $(FRACTOLINCL) $(MLXLINK) -o $(NAME)

$(LIB):
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
