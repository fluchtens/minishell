# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 15:02:30 by fluchten          #+#    #+#              #
#    Updated: 2023/03/08 07:38:52 by fluchten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror #${FSANITIZE}
FSANITIZE = -fsanitize=address -g
RM = rm -rf

INC_DIR = includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =	builtins/builtins.c \
		builtins/cd.c \
		builtins/echo.c \
		builtins/env.c \
		builtins/exit.c \
		builtins/export_utils.c \
		builtins/export.c \
		builtins/pwd.c \
		builtins/unset_utils.c \
		builtins/unset.c \
		cmds/cmds_init.c \
		cmds/cmds_lst_add.c \
		cmds/cmds_lst_clear.c \
		cmds/cmds_lst_utils.c \
		executor/executor_init.c \
		executor/executor.c \
		executor/handle_files.c \
		executor/heredoc_init.c \
		executor/one_cmd.c \
		executor/process.c \
		lexer/lexer_init.c \
		lexer/lexer_lst_add.c \
		lexer/lexer_lst_clear.c \
		lexer/lexer_lst_utils.c \
		lexer/lexer_read_string.c \
		lexer/lexer_read_token.c \
		lexer/lexer_utils.c \
		parser/parser_init.c \
		parser/redirections.c \
		parsing/parse_envp.c \
		parsing/parse_paths.c \
		parsing/parse_pwd.c \
		signals/signals.c \
		temp/temp.c \
		utils/error.c \
		utils/free.c \
		utils/remove_quotes.c \
		utils/utils.c \
		main.c

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