/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:23:38 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/20 18:52:13 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*lexer_new(char *str, int token)
{
	t_lexer		*element;
	static int	i = 0;

	element = malloc(sizeof(t_lexer));
	if (!element)
		return (NULL);
	element->str = str;
	element->token = token;
	element->i = i++;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

t_lexer	*lexer_last(t_lexer *lexer)
{
	t_lexer	*last;

	if (!lexer)
		return (NULL);
	last = lexer;
	while (last->next)
		last = last->next;
	return (last);
}

void	lexer_add_back(t_lexer **lexer, t_lexer *new)
{
	t_lexer	*last;

	if (!lexer || !new)
		return ;
	if (!*lexer)
	{
		*lexer = new;
		return ;
	}
	last = lexer_last(*lexer);
	last->next = new;
	new->prev = last;
}

int	add_element(char *line, t_tokens token, t_lexer **lexer)
{
	t_lexer	*new;

	new = lexer_new(line, token);
	if (!lexer)
		return (0);
	lexer_add_back(lexer, new);
	return (1);
}
