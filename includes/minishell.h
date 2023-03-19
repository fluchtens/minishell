/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:59:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/19 14:28:57 by fluchten         ###   ########.fr       */
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
# include <sys/errno.h>
# include <termios.h>
# include "libft.h"

# define MSG_READLINE "\033[1;36mminishell$ \033[0m"
# define MSG_HEREDOC "\033[1;32m> \033[0m"
# define ERR_MALLOC "malloc() failed"
# define ERR_QUOTES "syntax error: near unexpected token `quote'"
# define ERR_TOKEN "syntax error near unexpected token `newline'"
# define ERR_HOME_NOT_SET "minishell: cd: HOME not set"
# define ERR_OLDPWD_NOT_SET "minishell: cd: OLDPWD not set"
# define ERR_FORK "fork() failed"
# define ERR_DUP2 "dup2() failed"

typedef enum e_tokens
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
	enum e_tokens	token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_parser
{
	struct s_data	*data;
	struct s_lexer	*lexer;
	struct s_lexer	*redirections;
}	t_parser;

typedef struct s_cmds
{
	char			**str;
	int				(*builtin)(struct s_data *, struct s_cmds *);
	char			*hd_file_name;
	struct s_lexer	*redirections;
	struct s_cmds	*next;
	struct s_cmds	*prev;
}	t_cmds;

typedef struct s_data
{
	char			*line;
	char			**envp;
	char			**envp_sorted;
	char			**paths;
	char			*pwd;
	char			*old_pwd;
	struct s_lexer	*lexer;
	struct s_cmds	*cmds;
	int				*pid;
	int				pipes_count;
	bool			heredoc;
	int				pidindex;
	int				heredocindex;
}	t_data;

int	g_ret_value;

/* main */
void		loop(t_data *data);
/* builtins */
int			(*get_builtin(char *str))(t_data *data, t_cmds *cmds);
int			ft_cd(t_data *data, t_cmds *cmds);
int			ft_echo(t_data *data, t_cmds *cmds);
int			ft_env(t_data *data, t_cmds *cmds);
int			ft_exit(t_data *data, t_cmds *cmds);
int			equal_pos(char *str);
int			check_export_cmd(char **str);
char		**add_var_envp(char **envp, char *var);
int			is_exist_var(char **envp, char *var);
int			ft_export(t_data *data, t_cmds *cmds);
void		update_pwd(t_data *data);
int			ft_pwd(t_data *data, t_cmds *cmds);
int			check_unset_cmd(char **str);
int			ft_unset(t_data *data, t_cmds *cmds);
/* cmds */
t_cmds		*init_cmds(t_parser *parser);
t_cmds		*cmds_new(char **str, t_lexer *redirections);
void		cmds_add_back(t_cmds **lst, t_cmds *new);
void		cmds_clear(t_cmds **lst);
t_cmds		*cmds_first(t_cmds *cmds);
t_cmds		*cmds_last(t_cmds *cmds);
/* executor */
int			init_executor(t_data *data);
int			execution(t_data *data, t_cmds *cmd);
void		execute_multiple_cmd(t_data *data);
int			handle_files(t_lexer *redirections, t_cmds *cmd);
void		heredoc_init(t_data *data, t_cmds *cmd, t_lexer *redirection);
char		*ft_expander_heredoc(char **line, t_data *data);
int			ft_have_quotes(const char *str);
int			heredoc_ver(t_data *data, int pipefd[2], char *filename);
void		execute_one_cmd(t_data *data, t_cmds *cmd);
void		child_process(t_data *data, t_cmds *cmd);
void		process(t_data *data, int pipefd[2], int fd_in, t_cmds *cmd);
/* expander */
void		init_expander(t_data *data, t_cmds *cmds);
int			ft_check_dollar(char *str, int check);
int			ft_expander_check(char c);
char		*expander_utils(char *str, t_data *data);
/* lexer */
void		init_lexer(t_data *data);
t_lexer		*lexer_new(char *str, int token);
void		lexer_add_back(t_lexer **lexer, t_lexer *new);
void		lexer_delone(t_lexer **lst, int i);
void		lexer_clear(t_lexer **lexer);
t_lexer		*lexer_last(t_lexer *lexer);
t_tokens	is_token(char c);
int			read_token(char *line, int i, t_lexer **lexer);
int			read_string(char *str, int i, t_lexer **lexer);
int			lexer_add_element(t_lexer **lexer, char *str, t_tokens token);
int			lexer_count_pipes(t_lexer *lexer);
int			lexer_count_args(t_lexer *lexer);
/* parser */
void		init_parser(t_data *data);
/* envp */
void		print_envp(char **envp, int is_sorted);
void		sort_export_envp(t_data *data);
/* error */
void		print_error(char *str, t_data *data);
void		print_token_error(t_data *data, t_lexer *lexer, t_tokens token);
void		print_parser_error(char *str, t_data *data, t_lexer *lexer);
/* free */
void		free_array(char **array);
void		free_everythings(t_data *data);
void		exit_loop(t_data *data);
void		reset_data(t_data *data);
/* parse */
int			parse_pwd(t_data *data);
int			parse_paths(t_data *data);
/* removes quotes */
char		*ft_remove_quotes(char *str);
/* signals */
void		init_signals(int value);
/* utils */
void		initialization(t_data *data);
void		increment_shlvl(t_data *data);
char		*find_path(char **envp, char *var);

#endif
