# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 15:03:07 by fluchten          #+#    #+#              #
#    Updated: 2023/02/27 18:11:35 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBFT = libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =	ft_printf/ft_printf_utils1.c \
		ft_printf/ft_printf_utils2.c \
		ft_printf/ft_printf.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		ft_array_dup.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_is_closed_quotes.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_iswhitespace.c \
		ft_itoa.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_print_error.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_str_isdigits.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c 

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

COLOR_PURPLE = \033[1;35m
COLOR_RED = \033[0;31m
COLOR_GREEN	= \033[0;32m
COLOR_RESET = \033[0m

all: ${NAME}

${OBJS_DIR}:
	@echo "\n${COLOR_PURPLE}${LIBFT} ${COLOR_GREEN}COMPILING ->${COLOR_RESET}"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	@mkdir -p ${@D}
	@${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o $@
	@echo "${COLOR_GREEN}.${COLOR_RESET}\c"

${NAME}: ${OBJS}
	@ar -rcs ${NAME} ${OBJS}
	@echo "\n${COLOR_PURPLE}${LIBFT} ${COLOR_GREEN}${OBJS_DIR} were created${COLOR_RESET}"
	@echo "${COLOR_PURPLE}${LIBFT} ${COLOR_GREEN}${NAME} was created${COLOR_RESET}"

clean:
	@${RM} ${OBJS_DIR}
	@echo "${COLOR_PURPLE}${LIBFT} ${COLOR_RED}${OBJS_DIR} were deleted${COLOR_RESET}"

fclean: clean
	@${RM} ${NAME}
	@echo "${COLOR_PURPLE}${LIBFT} ${COLOR_RED}${NAME} was deleted${COLOR_RESET}"

re: fclean all

.PHONY: all clean fclean re