# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 12:15:13 by iabasala          #+#    #+#              #
#    Updated: 2025/02/28 07:06:12 by iabasala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = parsing.c utils.c mandelbrot.c  handle_key.c julia.c main.c free.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm
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

.SECONDARY:
.DENY: all clean fclean re
