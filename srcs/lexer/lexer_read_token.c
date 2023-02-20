/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_read_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:25:44 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/19 16:09:56 by fluchten         ###   ########.fr       */
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
	else
		return (0);
}

int	read_token(char *line, int i, t_lexer **lexer)
{
	t_tokens	token;

	token = is_token(line[i]);
	if (token == GREAT && is_token(line[i + 1]) == GREAT)
	{
		if (!add_element(NULL, GREAT_GREAT, lexer))
			return (-1);
		return (2);
	}
	else if (token == LESS && is_token(line[i + 1]) == LESS)
	{
		if (!add_element(NULL, LESS_LESS, lexer))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!add_element(NULL, token, lexer))
			return (-1);
		return (1);
	}	
	return (0);
}
