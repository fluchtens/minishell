/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lst_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:23:38 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/24 07:35:41 by fluchten         ###   ########.fr       */
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
