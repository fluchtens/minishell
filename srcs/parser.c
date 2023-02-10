/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:14:49 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/10 08:41:57 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_token(char c)
{
	if (c == '<')
		return (R);
	else if (c == '>')
		return (L);
	else if (c == '|')
		return (P);
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
	element->token = ft_is_token(line[0]);
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

int	ft_quote_check(t_data *data, char c)
{
	if (c == '"' && data->quote.sing == 0 && data->quote.doub == 0)
		data->quote.doub = 1;
	else if (c == '"' && data->quote.doub == 1)
		data->quote.doub = 0;
	if (c == '\'' && data->quote.sing == 0 && data->quote.doub == 0)
		data->quote.sing = 1;
	else if (c == '\'' && data->quote.sing == 1)
		data->quote.sing = 0;
	if (data->quote.doub == 1 || data->quote.sing == 1)
		return (1);
	return (0);
}

char	*cmd_get_command(t_data *data, char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] && ((ft_quote_check(data, line[i]) && line[i] == '|') || line[i] != '|'))
		i++;
	temp = NULL;
	temp = ft_strdup_size(line, i);
	printf("toute la commande= %s\n", temp);
	return (temp);
}

void	cmd_creation(t_data *data, int i)
{
	char	*cmd;
	data->line = data->line + i;
	cmd = cmd_get_command(data, data->line);
}

void	parsing(t_data *data)
{
	int	i;

	if (!data->line)
		return ;
	i = 0;
	cmd_creation(data, i);
	while (data->line[i])
	{
		if (!ft_quote_check(data, data->line[i]) && data->line[i] == '|')
			cmd_creation(data, i + 1);
		i++;
	}
	printf("fin\n");
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
		printf("[%s][%d]\n", list->str, list->token);
		list = list->next;
	}
}
