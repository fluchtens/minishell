/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_read_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:25:44 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/24 11:24:27 by fluchten         ###   ########.fr       */
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
