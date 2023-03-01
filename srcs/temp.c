/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:32:40 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/01 10:30:51 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lexer(t_data *data)
{
	t_lexer	*temp;

	temp = data->lexer;
	if (!temp)
		printf("Lexer list is null!\n");
	while (temp)
	{
		printf("[%d] = %s -> [%d]\n", temp->i, temp->str, temp->token);
		temp = temp->next;
	}
}

void	print_cmds(t_data *data)
{
	t_cmds	*temp;
	int		i;

	temp = data->cmds;
	if (!temp)
		printf("Cmds list is null!\n");
	while (temp)
	{
		i = 0;
		while (temp->str[i])
		{
			printf("[%s] ", temp->str[i]);
			i++;
		}
		printf("\n");
		temp = temp->next;
	}
}

void	print_redirections(t_parser *parser)
{
	t_lexer	*temp;

	temp = parser->redirections;
	if (!temp)
		printf("Redirections list is null!\n");
	while (temp)
	{
		printf("[%d] = %s -> [%d]\n", temp->i, temp->str, temp->token);
		temp = temp->next;
	}
}
