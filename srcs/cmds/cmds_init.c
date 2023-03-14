/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:48:24 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/14 10:04:03 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_element(t_parser *parser, t_lexer *temp, int i, int j)
{
	t_lexer	*new;

	new = lexer_new(ft_strdup(temp->next->str), temp->token);
	if (!new)
		print_parser_error(ERR_MALLOC, parser->data, parser->lexer);
	lexer_add_back(&parser->redirections, new);
	lexer_delone(&parser->lexer, i);
	lexer_delone(&parser->lexer, j);
}

static void	remove_redirections(t_parser *parser)
{
	t_lexer	*temp;

	temp = parser->lexer;
	while (temp && !temp->token)
		temp = temp->next;
	if (!temp || (temp->token == PIPE && temp->next))
		return ;
	if (!temp->next)
		print_parser_error(ERR_TOKEN, parser->data, parser->lexer);
	if (temp->next->token)
		print_token_error(parser->data, parser->lexer, temp->next->token);
	if ((temp->token >= GREAT && temp->token <= LESS_LESS))
		add_element(parser, temp, temp->i, temp->next->i);
	remove_redirections(parser);
}

t_cmds	*init_cmds(t_parser *parser)
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
		temp = parser->lexer;
		i++;
	}
	return (cmds_new(final, parser->redirections));
}
