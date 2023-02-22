/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:59:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/22 07:59:23 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

# define MSG_READLINE "\033[1;36mminishell$ \033[0m"
# define MSG_QUOTES "syntax error: quotes are not closed\n"
# define MSG_MALLOC "malloc error: allocation failure\n"
# define MSG_PARSER "parse error near `\\n'\n"

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_data
{
	char					*line;
	char					**paths;
	char					**envp;
	struct s_cmds			*cmds;
	t_lexer					*lexer;
	char					*pwd;
	char					*old_pwd;
	int						pipes_count;
	int						*pid;
	bool					heredoc;
	bool					reset;
}	t_data;

typedef struct s_parser
{
	t_data	*data;
	t_lexer	*lexer;
	t_lexer	*redirections;
	int		num_redirections;
}	t_parser;

typedef struct s_cmds
{
	char			**str;
	int				(*builtin)(t_data *, struct s_cmds *);
	int				num_redirections;
	char			*hd_file_name;
	t_lexer			*redirections;
	struct s_cmds	*next;
	struct s_cmds	*prev;
}	t_cmds;

typedef struct s_global
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;

t_global	g_global;

void		init_stri(int i, int j, t_data *data);
char		**expander(t_data *data, char **str);
char		*expander_str(t_data *data, char *str);
size_t		dollar_sign(char *str);
char		*char_to_str(char c);
int			after_dol_lenght(char *str, int j);
void		free_things(char *tmp2, t_data *data, int i);
char		*delete_quotes_value(char *str);
void		sigint_handler(int sig);
void		sigquit_handler(int sig);
void		init_signals(void);
char		*delete_quotes(char *str, char c);
char		*delete_quotes_export(char *str, char c);
int			question_mark(char **tmp);

/* builtins */
int			(*builtin_arr(char *str))(t_data *data, t_cmds *cmds);
void		change_path(t_data *data);
int			mini_echo(t_data *data, t_cmds *cmds);
int			mini_cd(t_data *data, t_cmds *cmds);
int			mini_pwd(t_data *data, t_cmds *cmds);
int			mini_export(t_data *data, t_cmds *cmds);
int			mini_unset(t_data *data, t_cmds *cmds);
int			mini_env(t_data *data, t_cmds *cmds);
int			mini_exit(t_data *data, t_cmds *cmds);
int			mini_continue(t_data *data, t_cmds *cmds);
size_t		equal_sign(char *str);
int			check_valid_identifier(char c);
/* errors */
void		parser_error(int error, t_data *data, t_lexer *lexer);
void		lexer_error(int error, t_data *data);
int			cmd_not_found(char *str);
int			export_error(char *c);
int			ft_error(int error, t_data *data);
/* executor */
int			check_redirections(t_cmds *cmd);
int			executor(t_data *data);
t_cmds		*call_expander(t_data *data, t_cmds *cmd);
int			pipe_wait(int *pid, int amount);
int			find_cmd(t_cmds *cmd, t_data *data);
void		handle_cmd(t_cmds *cmd, t_data *data);
void		dup_cmd(t_cmds *cmd, t_data *data, int end[2], int fd_in);
void		single_cmd(t_cmds *cmd, t_data *data);
int			send_heredoc(t_data *data, t_cmds *cmd);
int			prepare_executor(t_data *data);
/* parser */
int			handle_heredoc(t_parser *parser, t_lexer *tmp);

/* init */
int			initialization(t_data *data);
int			reset_data(t_data *data);
int			minishell_loop(t_data *data);
/* lexer */
int			init_lexer(t_data *data);
int			read_string(char *str, int i, t_lexer **lexer);
t_tokens	is_token(char c);
int			read_token(char *line, int i, t_lexer **lexer);
t_lexer		*lexer_new(char *str, int token);
t_lexer		*lexer_last(t_lexer *lexer);
void		lexer_add_back(t_lexer **lexer, t_lexer *new);
int			add_element(char *line, t_tokens token, t_lexer **lexer);
void		lexer_delone(t_lexer **lst, int i);
void		lexer_clear(t_lexer **lst);
/* parser */
int			parser(t_data *data);
int			lexer_count_pipes(t_lexer *lexer);
int			lexer_count_args(t_lexer *lexer);
void		remove_redirections(t_parser *parser);
t_cmds		*parse_cmds(t_parser *parser);
t_cmds		*cmds_new(char **str, int num_redirections, t_lexer *redirections);
void		cmds_add_back(t_cmds **lst, t_cmds *new);
void		cmds_clear(t_cmds **lst);
t_cmds		*cmds_first(t_cmds *map);
/* parsing */
int			parse_paths(t_data *data);
int			parse_pwd(t_data *data);
/* utils */
int			print_error(char *str, t_data *data);
int			print_token_error(t_data *data, t_lexer *lexer, t_tokens token);
int			print_parser_error(char *str, t_data *data, t_lexer *lexer);
void		free_array(char **array);
/* temp */
void		print_lexer(t_data *data);
void		print_cmds(t_data *data);
void		print_redirections(t_parser *parser);

#endif