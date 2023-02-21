/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 07:33:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/21 09:52:27 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_new_redirection(t_lexer *temp, t_parser *parser)
{
	t_lexer	*node;
	int		index_1;
	int		index_2;

	node = lexer_new(ft_strdup(temp->next->str), temp->token);
	if (!node)
		parser_error(1, parser->data, parser->lexer);
	lexer_add_back(&parser->redirections, node);
	index_1 = temp->i;
	index_2 = temp->next->i;
	lexer_delone(&parser->lexer, index_1);
	lexer_delone(&parser->lexer, index_2);
	parser->num_redirections++;
	return (0);
}

void	rm_redirections(t_parser *parser)
{
	t_lexer	*temp;

	temp = parser->lexer;
	while (temp && temp->token == 0)
		temp = temp->next;
	if (!temp || temp->token == PIPE)
		return ;
	if (!temp->next)
		print_parser_error(MSG_PARSER, parser->data, parser->lexer);
	if (temp->next->token)
		print_token_error(parser->data, parser->lexer, temp->next->token);
	if ((temp->token >= GREAT && temp->token <= LESS_LESS))
		add_new_redirection(temp, parser);
	rm_redirections(parser);
}
