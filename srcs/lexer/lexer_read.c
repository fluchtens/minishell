/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:25:44 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/08 07:40:12 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	is_token(char c)
{
	if (c == '|')
		return (PIPE);
	else if (c == '>')
		return (GREAT);
	else if (c == '<')
		return (LESS);
	return (0);
}

int	read_token(char *line, int i, t_lexer **lexer)
{
	t_tokens	token;
	int			len;

	token = is_token(line[i]);
	len = 0;
	if (token == GREAT && is_token(line[i + 1]) == GREAT)
	{
		token = GREAT_GREAT;
		len = 2;
	}
	else if (token == LESS && is_token(line[i + 1]) == LESS)
	{
		token = LESS_LESS;
		len = 2;
	}
	else if (token)
		len = 1;
	if (!lexer_add_element(NULL, token, lexer))
		return (-1);
	return (len);
}

static int	str_quotes_len(char *str, int i, char c)
{
	int	len;

	len = 0;
	if (str[i] == c)
	{
		len++;
		while (str[i + len] && str[i + len] != c)
			len++;
	}
	if (str[i + len] == c)
		len++;
	return (len);
}

int	read_string(char *str, int i, t_lexer **lexer)
{
	int	j;

	j = 0;
	while (str[i + j] && !is_token(str[i + j]))
	{
		if (str[i + j] == 34 || str[i + j] == 39)
		{
			j += str_quotes_len(str, i + j, str[i + j]);
			continue ;
		}
		if (ft_iswhitespace(str[i + j]))
			break ;
		j++;
	}
	if (!lexer_add_element(ft_substr(str, i, j), 0, lexer))
		return (-1);
	return (j);
}
