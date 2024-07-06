# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunseo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 18:17:07 by yunseo            #+#    #+#              #
#    Updated: 2024/07/02 20:34:37 by yunseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c \
		path.c \
		cmd.c

SRCS_B = pipex_bonus.c \
		path_bonus.c \
		cmd_bonus.c

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
	make clean -sC ${LIBFT_DIR}

fclean : clean
	make fclean -sC ${LIBFT_DIR}
	rm -f ${NAME}

re : fclean all

bonus : ${NAME}

.PHONY : all clean fclean re bonus
