/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:14:49 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/08 10:44:46 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lexer	*new_element(char *line)
{
	t_lexer	*element;

	element = malloc(sizeof(t_lexer));
	if (!element)
		return (NULL);
	element->str = line;
	element->next = NULL;
	return (element);
}

t_lexer	*parser(char **line)
{
	t_lexer	*list;
	t_lexer	*temp;
	int		i;

	list = new_element(line[0]);
	if (!list)
		return (NULL);
	temp = list;
	i = 1;
	while (line[i])
	{
		temp->next = new_element(line[i]);
		if (!temp->next)
			return (NULL);
		temp = temp->next;
		i++;
	}
	return (list);
}

void	print_list(t_lexer *list)
{
	if (!list)
	{
		printf("The list is empty!\n");
		return ;
	}
	while (list)
	{
		printf("[%s]", list->str);
		list = list->next;
	}
	printf("\n");
}
