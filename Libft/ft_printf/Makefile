# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 12:45:16 by yunseo            #+#    #+#              #
#    Updated: 2024/04/07 15:59:17 by yunseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -c
AR = ar

SRCS = ft_printf.c \
	   specifier_func1.c \
	   specifier_func2.c \
	   specifier_func_utils.c

OBJS = ${SRCS:.c=.o}

LIBFT_DIR = ../libft/

all : ${NAME}

${LIBFT} :
	make -sC ${LIBFT_DIR}
	cp ${LIBFT} ./libftprintf.a

${NAME} : ${OBJS} ${LIBFT}
	${AR} -r ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} $^ -o $@

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean all
