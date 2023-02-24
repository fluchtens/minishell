# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 15:02:30 by fluchten          #+#    #+#              #
#    Updated: 2023/02/24 08:02:45 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror #${SANIFLAG}
SANIFLAG = -fsanitize=address -g
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =	temp/builtins/builtins.c \
		temp/builtins/mini_cd.c \
		temp/builtins/mini_echo.c \
		temp/builtins/mini_env.c \
		temp/builtins/mini_exit.c \
		temp/builtins/mini_export.c \
		temp/builtins/mini_pwd.c \
		temp/builtins/mini_unset.c \
		temp/builtins/utils_builtins.c \
		temp/executor/check_redirections.c \
		temp/executor/executor.c \
		temp/executor/handle_cmd.c \
		temp/executor/heredoc.c \
		temp/executor/executor_utils.c \
		temp/executor/prepare_executor.c \
		temp/expander/expander.c \
		temp/expander/expanders_utils.c \
		temp/expander/expanders_utils2.c \
		cmds/cmds_init.c \
		cmds/cmds_lst_add.c \
		cmds/cmds_lst_clear.c \
		cmds/cmds_lst_utils.c \
		initialization/initialization.c \
		initialization/minishell_loop.c \
		lexer/lexer_init.c \
		lexer/lexer_lst_add.c \
		lexer/lexer_lst_clear.c \
		lexer/lexer_lst_utils.c \
		lexer/lexer_read_string.c \
		lexer/lexer_read_token.c \
		lexer/lexer_utils.c \
		parser/parser_init.c \
		parser/redirections.c \
		parsing/parse_paths.c \
		parsing/parse_pwd.c \
		signals/signals.c \
		utils/error.c \
		utils/free.c \
		main.c \
		temp.c

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

LIBFT_PATH = libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}/includes

READLINE_PATH = $(shell brew --prefix readline)
READLINE_LIB = -lreadline -lhistory -L $(READLINE_PATH)/lib
READLINE_INC = -I $(READLINE_PATH)/include 

COLOR_CYAN = \033[1;36m
COLOR_RED = \033[0;31m
COLOR_GREEN	= \033[0;32m
COLOR_RESET = \033[0m

all: ${NAME}

${OBJS_DIR}:
	@echo "${COLOR_CYAN}${NAME} ${COLOR_GREEN}COMPILING ->${COLOR_RESET}"

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	@mkdir -p ${@D}
	@${CC} ${CFLAGS} -I ${INC_DIR} -I ${LIBFT_INC} ${READLINE_INC} -c $< -o $@
	@echo "${COLOR_GREEN}.${COLOR_RESET}\c"

${NAME}: ${OBJS}
	@make -C ${LIBFT_PATH}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${READLINE_LIB} -o ${NAME}
	@echo "${COLOR_CYAN}${NAME} ${COLOR_GREEN}${OBJS_DIR} were created${COLOR_RESET}"
	@echo "${COLOR_CYAN}${NAME} ${COLOR_GREEN}${NAME} was created${COLOR_RESET}"

clean:
	@make clean -C ${LIBFT_PATH}
	@${RM} ${OBJS_DIR}
	@echo "${COLOR_CYAN}${NAME} ${COLOR_RED}${OBJS_DIR} were deleted${COLOR_RESET}"

fclean:	clean
	@make fclean -C ${LIBFT_PATH}
	@${RM} ${NAME}
	@echo "${COLOR_CYAN}${NAME} ${COLOR_RED}${NAME} was deleted${COLOR_RESET}"

re: fclean all

.PHONY: all clean fclean re