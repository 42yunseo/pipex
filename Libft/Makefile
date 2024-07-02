# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunseo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 13:44:44 by yunseo            #+#    #+#              #
#    Updated: 2024/07/01 13:45:02 by yunseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar

LIBFT_DIR = ./libft/
LIBFT = ${LIBFT_DIR}libft.a

GNL_DIR = ./get_next_line/
GNL = ${GNL_DIR}/gnl.a

PRINTF_DIR = ./ft_printf/
PRINTF = ${PRINTF_DIR}libftprintf.a

all : ${NAME}


libft : ${LIBFT}
	cp ${LIBFT} ${NAME}

gnl : ${GNL}
	cp ${GNL} ${NAME}

printf : ${PRINTF}
	cp ${PRINTF} ${NAME}

LIBFT_SRCS = 	${LIBFT_DIR}ft_atoi.c \
		${LIBFT_DIR}ft_bzero.c \
		${LIBFT_DIR}ft_calloc.c \
		${LIBFT_DIR}ft_isalnum.c \
		${LIBFT_DIR}ft_isalpha.c \
		${LIBFT_DIR}ft_isascii.c \
		${LIBFT_DIR}ft_isdigit.c \
		${LIBFT_DIR}ft_isprint.c \
		${LIBFT_DIR}ft_itoa.c \
		${LIBFT_DIR}ft_memchr.c \
		${LIBFT_DIR}ft_memcmp.c \
		${LIBFT_DIR}ft_memcpy.c \
		${LIBFT_DIR}ft_memmove.c \
		${LIBFT_DIR}ft_memset.c \
		${LIBFT_DIR}ft_putchar_fd.c \
		${LIBFT_DIR}ft_putendl_fd.c \
		${LIBFT_DIR}ft_putnbr_fd.c \
		${LIBFT_DIR}ft_putstr_fd.c \
		${LIBFT_DIR}ft_split.c \
		${LIBFT_DIR}ft_strchr.c \
		${LIBFT_DIR}ft_strdup.c \
		${LIBFT_DIR}ft_striteri.c \
		${LIBFT_DIR}ft_strjoin.c \
		${LIBFT_DIR}ft_strlcat.c \
		${LIBFT_DIR}ft_strlcpy.c \
		${LIBFT_DIR}ft_strlen.c \
		${LIBFT_DIR}ft_strmapi.c \
		${LIBFT_DIR}ft_strncmp.c \
		${LIBFT_DIR}ft_strnstr.c \
		${LIBFT_DIR}ft_strrchr.c \
		${LIBFT_DIR}ft_strtrim.c \
		${LIBFT_DIR}ft_substr.c \
		${LIBFT_DIR}ft_tolower.c \
		${LIBFT_DIR}ft_toupper.c

LIBFT_SRCS_B = ${LIBFT_DIR}ft_lstnew_bonus.c \
		${LIBFT_DIR}ft_lstadd_front_bonus.c \
		${LIBFT_DIR}ft_lstsize_bonus.c \
		${LIBFT_DIR}ft_lstlast_bonus.c \
		${LIBFT_DIR}ft_lstadd_back_bonus.c \
		${LIBFT_DIR}ft_lstdelone_bonus.c \
		${LIBFT_DIR}ft_lstclear_bonus.c \
		${LIBFT_DIR}ft_lstiter_bonus.c \
		${LIBFT_DIR}ft_lstmap_bonus.c


LIBFT_HEADER = ${LIBFT_DIR}libft.h

LIBFT_OBJS = ${LIBFT_SRCS:.c=.o}
LIBFT_OBJS_B = ${LIBFT_SRCS_B:.c=.o}

GNL_SRCS = ${GNL_DIR}get_next_line.c \
			${GNL_DIR}get_next_line_utils.c

GNL_HEADER = ${GNL_DIR}get_next_line.h

GNL_OBJS = ${GNL_SRCS:.c=.o}

PRINTF_SRCS = ${PRINTF_DIR}ft_printf.c \
			${PRINTF_DIR}specifier_func1.c \
			${PRINTF_DIR}specifier_func2.c \
			${PRINTF_DIR}specifier_func_utils.c
PRINTF_OBJS = ${PRINTF_SRCS:.c=.o}

${LIBFT} : ${LIBFT_OBJS} ${LIBFT_OBJS_B} ${LIBFT_HEADER}
	${AR} -rc ${LIBFT} ${LIBFT_OBJS} ${LIBFT_OBJS_B}

${GNL} : ${GNL_OBJS} ${GNL_HEADER}
	${AR} -rc ${GNL} ${GNL_OBJS}

${PRINTF} :
	make -C ${PRINTF_DIR}

${NAME} : ${LIBFT} ${GNL} ${PRINTF}
	cp ${LIBFT} ${NAME}
	${AR} -r ${NAME} ${GNL_OBJS}
	${AR} -r ${NAME} ${PRINTF_OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $^ -o $@

clean :
	@rm -f ${LIBFT_OBJS}
	@rm -f ${LIBFT_OBJS_B}
	@rm -f ${GNL_OBJS}
	@make clean -sC ${PRINTF_DIR}

fclean : clean
	rm -f ${NAME}
	rm -f ${LIBFT}
	rm -f ${GNL}
	rm -f ${PRINTF}

re : fclean all

.PHONY : all clean fclean re libft gnl printf
