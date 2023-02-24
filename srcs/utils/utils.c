/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 08:47:43 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/24 10:11:27 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	initialization(t_data *data)
{
	data->lexer = NULL;
	data->cmds = NULL;
	data->pid = NULL;
	data->heredoc = false;
	data->reset = false;
	g_global.stop_heredoc = 0;
	g_global.in_cmd = 0;
	g_global.in_heredoc = 0;
	parse_paths(data);
	init_signals();
	return (1);
}

void	reset_data(t_data *data)
{
	cmds_clear(&data->cmds);
	free(data->line);
	free_array(data->paths);
	if (data->pid)
		free(data->pid);
	initialization(data);
	data->reset = true;
}

void	exit_minishell(t_data *data)
{
	ft_putstr_fd("exit\n", 0);
	free_array(data->envp);
	free_array(data->paths);
	free(data->pwd);
	free(data->old_pwd);
	exit(0);
}
