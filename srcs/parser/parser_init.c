/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:11:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/21 10:02:39 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_simple_cmds	*init_cmds(t_parser *parser)
{
	t_lexer	*temp;
	char	**str;
	int		args_count;
	int		i;

	rm_redirections(parser);
	args_count = lexer_count_args(parser->lexer);
	str = ft_calloc(sizeof(char *), (args_count + 1));
	if (!str)
		print_parser_error(MSG_MALLOC, parser->data, parser->lexer);
	temp = parser->lexer;
	i = 0;
	while (args_count)
	{
		if (temp->str)
		{
			str[i++] = ft_strdup(temp->str);
			lexer_delone(&parser->lexer, temp->i);
			temp = parser->lexer;
		}
		args_count--;
	}
	return (ft_simple_cmdsnew(str, parser->num_redirections, parser->redirections));
}

int	parser(t_data *data)
{
	t_simple_cmds	*cmds;
	t_parser		parser;

	data->simple_cmds = NULL;
	data->pipes_count = lexer_count_pipes(data->lexer);
	if (data->lexer->token == PIPE)
		return (print_token_error(data, data->lexer, data->lexer->token));
	while (data->lexer)
	{
		if (data->lexer && data->lexer->token == PIPE)
			lexer_delone(&data->lexer, data->lexer->i);
		init_parser_data(data, data->lexer, &parser);
		cmds = init_cmds(&parser);
		if (!cmds)
			print_parser_error(MSG_MALLOC, parser.data, parser.lexer);
		if (!data->simple_cmds)
			data->simple_cmds = cmds;
		else
			ft_simple_cmdsadd_back(&data->simple_cmds, cmds);
		data->lexer = parser.lexer;
	}
	return (EXIT_SUCCESS);
}
