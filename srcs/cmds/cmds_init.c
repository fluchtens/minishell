/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:48:24 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/06 08:09:59 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	return (cmds_new(final, parser->num_redirections, parser->redirections));
}
