/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:21:44 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/22 07:50:25 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
