# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunseo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 18:17:07 by yunseo            #+#    #+#              #
#    Updated: 2024/05/15 18:20:00 by yunseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c

all : ${NAME}

${NAME} : ${SRCS}
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re bonus
