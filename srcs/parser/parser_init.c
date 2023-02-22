/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:11:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/22 07:59:23 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_parser_table(t_data *data, t_lexer *lexer, t_parser *parser)
{
	parser->data = data;
	parser->lexer = lexer;
	parser->redirections = NULL;
	parser->num_redirections = 0;
}

int	parser(t_data *data)
{
	t_cmds		*temp;
	t_parser	parser;

	data->pipes_count = lexer_count_pipes(data->lexer);
	if (data->lexer->token == PIPE)
		return (print_token_error(data, data->lexer, data->lexer->token));
	while (data->lexer)
	{
		if (data->lexer && data->lexer->token == PIPE)
			lexer_delone(&data->lexer, data->lexer->i);
		init_parser_table(data, data->lexer, &parser);
		temp = parse_cmds(&parser);
		if (!temp)
			return (print_parser_error(MSG_MALLOC, parser.data, parser.lexer));
		cmds_add_back(&data->cmds, temp);
		data->lexer = parser.lexer;
	}
	return (0);
}
