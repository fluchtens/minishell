/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:54:01 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/22 07:59:23 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmds	*parse_cmds(t_parser *parser)
{
	t_lexer	*temp;
	char	**final;
	int		args_count;
	int		i;

	remove_redirections(parser);
	temp = parser->lexer;
	args_count = lexer_count_args(temp);
	final = ft_calloc(sizeof(char *), (args_count + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (i < args_count)
	{
		final[i] = ft_strdup(temp->str);
		lexer_delone(&parser->lexer, temp->i);
		temp = temp->next;
		i++;
	}
	return (cmds_new(final, parser->num_redirections, parser->redirections));
}

t_cmds	*cmds_new(char **str, int num_redirections, t_lexer *redirections)
{
	t_cmds	*element;

	element = malloc(sizeof(t_cmds));
	if (!element)
		return (NULL);
	element->str = str;
	element->builtin = builtin_arr(str[0]);
	element->hd_file_name = NULL;
	element->num_redirections = num_redirections;
	element->redirections = redirections;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

void	cmds_add_back(t_cmds **lst, t_cmds *new)
{
	t_cmds	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	cmds_clear(t_cmds **lst)
{
	t_cmds	*tmp;
	t_lexer	*redirections_tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		redirections_tmp = (*lst)->redirections;
		lexer_clear(&redirections_tmp);
		if ((*lst)->str)
			free_array((*lst)->str);
		if ((*lst)->hd_file_name)
			free((*lst)->hd_file_name);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_cmds	*cmds_first(t_cmds *map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map->prev != NULL)
	{
		map = map->prev;
		i++;
	}
	return (map);
}
