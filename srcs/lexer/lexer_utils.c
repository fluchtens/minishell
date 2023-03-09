/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:21:44 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/09 09:27:56 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer_add_element(t_lexer **lexer, char *str, t_tokens token)
{
	t_lexer	*new;

	new = lexer_new(str, token);
	if (!lexer)
		return (0);
	lexer_add_back(lexer, new);
	return (1);
}

int	lexer_count_pipes(t_lexer *lexer)
{
	t_lexer	*temp;
	int		count;

	temp = lexer;
	count = 0;
	while (temp)
	{
		if (temp->token == PIPE)
			count++;
		temp = temp->next;
	}
	return (count);
}

int	lexer_count_args(t_lexer *lexer)
{
	t_lexer	*temp;
	int		count;

	temp = lexer;
	count = 0;
	while (temp && temp->token != PIPE)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
