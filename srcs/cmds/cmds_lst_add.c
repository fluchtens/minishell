/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_lst_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:54:01 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/09 10:46:19 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmds	*cmds_new(char **str, t_lexer *redirections)
{
	t_cmds	*element;

	element = malloc(sizeof(t_cmds));
	if (!element)
		return (NULL);
	element->str = str;
	element->builtin = builtin_arr(str[0]);
	element->hd_file_name = NULL;
	element->redirections = redirections;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

void	cmds_add_back(t_cmds **cmds, t_cmds *new)
{
	t_cmds	*last;

	if (!cmds || !new)
		return ;
	if (!*cmds)
	{
		*cmds = new;
		return ;
	}
	last = cmds_last(*cmds);
	last->next = new;
	new->prev = last;
}
