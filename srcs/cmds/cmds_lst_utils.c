/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_lst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 07:33:28 by fluchten          #+#    #+#             */
/*   Updated: 2024/02/27 19:14:17 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmds	*cmds_first(t_cmds *cmds)
{
	t_cmds	*temp;

	if (!cmds)
		return (NULL);
	temp = cmds;
	while (temp->prev)
	{
		temp = temp->prev;
	}
	return (temp);
}

t_cmds	*cmds_last(t_cmds *cmds)
{
	t_cmds	*last;

	if (!cmds)
		return (NULL);
	last = cmds;
	while (last->next)
		last = last->next;
	return (last);
}
