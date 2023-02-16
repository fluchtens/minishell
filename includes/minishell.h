/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:59:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/15 08:48:57 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_cmd
{
	char	**cmd;
	int		in_file;
	int		out_file;
	int		fd_in;
	int		fd_out;
	int		pipe;
	int		pid;
	struct	t_cmd *next;
}	t_cmd;

typedef struct s_quote
{
	bool sing;
	bool doub;
}	t_quote;

typedef struct s_data
{
	char	**envp;
	char	**paths;
	char	*line;
	char	*pwd;
	char	*old_pwd;
	t_cmd	*commands;
	t_quote	quote;
}	t_data;

typedef enum s_tokens
{
	R = 1, // > = 1
	L, // < = 2
	RR, // >> = 3
	LL, // < = 4
	P // | = 5
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i; // str = 0, token = 1;
	struct s_lexer	*next;
}	t_lexer;

/* init */
void	init_everything(t_data *data);
/* parsing */
char	**parse_envp(char **arr);
int		parse_paths(t_data *data);
int		parse_pwd(t_data *data);
/* utils */
int		print_error(char *str);
void	exit_and_free(t_data *data, char *str, int error);
void	free_everything(t_data *data);
void	free_array(char **array);
char	**ft_split_space(t_data *data, char const *s);
bool	ft_quote_check(t_data *data, char c);

#endif