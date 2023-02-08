/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:14:49 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/08 11:37:43 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_token(char c)
{
	if (c == '<')
		return (1);
	return (0);
}

int	ft_check_index(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_is_token(line[i]))
			return (1);
		i++;
	}
	return (0);
}

static t_lexer	*new_element(char *line)
{
	t_lexer	*element;

	element = malloc(sizeof(t_lexer));
	if (!element)
		return (NULL);
	element->str = line;
	element->i = ft_check_index(line);
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
		printf("[%s][%d]\n", list->str, list->i);
		list = list->next;
	}
}
