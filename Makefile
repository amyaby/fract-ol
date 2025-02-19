# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 12:15:13 by iabasala          #+#    #+#              #
#    Updated: 2025/02/19 15:38:09 by iabasala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = parsing.c utils.c mandelbrot.c main.c handle_key.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext
NAME = fractal

all: ${NAME}

${NAME}: ${OBJS}
	cc $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all