/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_lst_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:46:53 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 07:20:53 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmds_clear(t_cmds **cmds)
{
	t_cmds	*current;
	t_lexer	*redirections;
	t_cmds	*temp;

	if (!*cmds)
		return ;
	current = *cmds;
	while (current)
	{
		temp = current->next;
		redirections = current->redirections;
		lexer_clear(&redirections);
		if (current->str)
			free_array(current->str);
		if (current->hd_file_name)
			free(current->hd_file_name);
		free(current);
		current = temp;
	}
	*cmds = NULL;
}
