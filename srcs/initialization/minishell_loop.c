/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:06:58 by fpolycar          #+#    #+#             */
/*   Updated: 2023/02/21 08:58:14 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	reset_data(t_data *data)
{
	ft_simple_cmdsclear(&data->simple_cmds);
	free(data->line);
	if (data->pid)
		free(data->pid);
	free_array(data->paths);
	initialization(data);
	data->reset = true;
	minishell_loop(data);
	return (1);
}

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
		return (print_error(MSG_QUOTES, data));
	if (!init_lexer(data))
		return (print_error(MSG_MALLOC, data));
	parser(data);
	print_cmds(data);
	prepare_executor(data);
	reset_data(data);
	return (1);
}
