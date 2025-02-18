# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 12:15:13 by iabasala          #+#    #+#              #
#    Updated: 2025/02/17 13:13:33 by iabasala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = parsing.c utils.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
NAME = fractal
all: ${NAME}

${NAME}: ${OBJS}
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all