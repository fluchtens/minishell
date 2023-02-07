# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 15:02:30 by fluchten          #+#    #+#              #
#    Updated: 2023/02/07 10:13:25 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =	utils/utils.c \
		main.c

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

LIBFT_PATH = libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}/includes

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I ${INC_DIR} -I ${LIBFT_INC} -c $< -o $@

${NAME}: ${OBJS}
	@make -C ${LIBFT_PATH}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} -o ${NAME}

clean:
	@make clean -C ${LIBFT_PATH}
	${RM} ${OBJS_DIR}

fclean:	clean
	@make fclean -C ${LIBFT_PATH}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re