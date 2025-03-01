# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 12:15:13 by iabasala          #+#    #+#              #
#    Updated: 2025/03/01 22:09:40 by iabasala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx_Linux -lXext -lX11 -lm
FILES = main.c parsing.c utils.c mandelbrot.c handle_key.c julia.c free.c

FILES_o = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILES_o)
	$(CC) $(CFLAGS) $(FILES_o) -o $(NAME) $(MLXFLAGS)

clean:
	rm -rf $(FILES_o)

fclean: clean
	rm -f $(NAME)

re: fclean all