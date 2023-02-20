/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:59:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/20 08:33:12 by fluchten         ###   ########.fr       */
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
	char					**envp;
	char					**paths;
	char					*line;
	char					*pwd;
	char					*old_pwd;
	t_lexer					*lexer;
}	t_data;

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
/* parsing */
int			parse_paths(t_data *data);
int			parse_pwd(t_data *data);
/* utils */
int			print_error(char *str);
int			print_shell_error(char *str, t_data *data);
void		free_array(char **array);
/* temp */
void		print_lexer(t_data *data);

#endif