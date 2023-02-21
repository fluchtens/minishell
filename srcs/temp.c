/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:32:40 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/21 10:04:35 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lexer(t_data *data)
{
	t_lexer	*current;

	current = data->lexer;
	if (!current)
		printf("Lexer list is null!\n");
	while (current)
	{
		printf("[%d] = %s -> [%d]\n", current->i, current->str, current->token);
		current = current->next;
	}
}

void	print_cmds(t_data *data)
{
	t_simple_cmds	*current;
	int	i;

	current = data->simple_cmds;
	if (!current)
		printf("Cmds list is null!\n");
	while (current)
	{
		i = 0;
		while (current->str[i])
		{
			printf("[%s] ", current->str[i]);
			i++;
		}
		printf("\n");
		current = current->next;
	}
}
