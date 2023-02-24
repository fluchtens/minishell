/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:24:39 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/24 08:02:04 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell_loop(t_data *data)
{
	char	*temp;

	data->line = readline(MSG_READLINE);
	temp = ft_strtrim(data->line, " ");
	free(data->line);
	data->line = temp;
	if (!data->line)
	{
		ft_putstr_fd("exit\n", 0);
		exit(EXIT_SUCCESS);
	}
	if (!data->line[0])
		return (reset_data(data));
	add_history(data->line);
	if (!ft_is_closed_quotes(data->line))
		return (print_error(MSG_QUOTES_ERR, data));
	if (!init_lexer(data))
		return (print_error(MSG_MALLOC_ERR, data));
	parser(data);
	prepare_executor(data);
	reset_data(data);
	return (1);
}
