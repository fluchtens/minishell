/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 07:33:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 08:09:42 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redirection_add(t_parser *parser, t_lexer *temp)
{
	t_lexer	*new;

	new = lexer_new(ft_strdup(temp->next->str), temp->token);
	if (!new)
		print_parser_error(MSG_MALLOC_ERR, parser->data, parser->lexer);
	lexer_add_back(&parser->redirections, new);
	lexer_delone(&parser->lexer, temp->i);
	lexer_delone(&parser->lexer, temp->next->i);
	parser->num_redirections++;
}

void	remove_redirections(t_parser *parser)
{
	t_lexer	*temp;

	temp = parser->lexer;
	while (temp && !temp->token)
		temp = temp->next;
	if (!temp || temp->token == PIPE)
		return ;
	if (!temp->next)
		print_parser_error(MSG_PARSER_ERR, parser->data, parser->lexer);
	if (temp->next->token)
		print_token_error(parser->data, parser->lexer, temp->next->token);
	if ((temp->token >= GREAT && temp->token <= LESS_LESS))
		redirection_add(parser, temp);
	remove_redirections(parser);
}
