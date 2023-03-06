/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lst_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:52:43 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 08:22:22 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lexer	*lexer_clear_one_element(t_lexer **lst)
{
	if ((*lst)->str)
	{
		free((*lst)->str);
		(*lst)->str = NULL;
	}
	free(*lst);
	*lst = NULL;
	return (NULL);
}

static void	lexer_clear_first_element(t_lexer **lst)
{
	t_lexer	*current;

	current = *lst;
	*lst = current->next;
	lexer_clear_one_element(&current);
	if (*lst)
		(*lst)->prev = NULL;
}

void	lexer_delone(t_lexer **lst, int index)
{
	t_lexer	*current;
	t_lexer	*prev;
	t_lexer	*start;

	start = *lst;
	current = start;
	if (current->i == index)
	{
		lexer_clear_first_element(lst);
		return ;
	}
	while (current && current->i < index)
	{
		prev = current;
		current = current->next;
	}
	if (current)
		prev->next = current->next;
	else
		prev->next = NULL;
	if (prev->next)
		prev->next->prev = prev;
	lexer_clear_one_element(&current);
	*lst = start;
}

void	lexer_clear(t_lexer **lexer)
{
	t_lexer	*current;
	t_lexer	*temp;

	if (!*lexer)
		return ;
	current = *lexer;
	while (current)
	{
		temp = current->next;
		if (current->str)
			free(current->str);
		free(current);
		current = temp;
	}
	*lexer = NULL;
}
