# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunseo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 18:17:07 by yunseo            #+#    #+#              #
#    Updated: 2024/07/02 20:26:39 by yunseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c \
		path.c \
		cmd.c

LIBFT_DIR = ./Libft/
LIBFT = ./Libft/Libft.a
LIBFT_HEADER = ./Libft/libft_all.h

all : ${NAME}

${NAME} : ${SRCS} ${LIBFT}
	${CC} ${CFLAGS} ${SRCS} -o ${NAME} ${LIBFT}

${LIBFT} :
	make -sC ${LIBFT_DIR}

%.o : %.c
	${CC} ${CFLAGS} $^ -o $@

clean : 
	make -sC ${LIBFT_DIR}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re bonus
