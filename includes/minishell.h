/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:59:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/09 11:21:05 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdbool.h>

typedef struct s_quote
{
	bool sing;
	bool doub;
}	t_quote;

typedef struct s_data
{
	char	*line;
	t_quote	quote;
}			t_data;

typedef enum s_tokens
{
	R = 1, // > = 1
	L, // < = 2
	RR, // >> = 3
	LL, // < = 4
	P // | = 5
}			t_tokens;


typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i; // str = 0, token = 1;
	struct s_lexer	*next;
}					t_lexer;

/* parsing */
t_lexer	*parser(char **line);
void	print_list(t_lexer *list);
void	parsing(t_data *data);
/* utils */
int		print_error(char *str);

#endif