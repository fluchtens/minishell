/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 08:47:43 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/27 17:16:33 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialization(t_data *data)
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
}

void	exit_loop(t_data *data)
{
	ft_putstr_fd("exit\n", 0);
	free_array(data->envp);
	free_array(data->paths);
	free(data->pwd);
	free(data->old_pwd);
	exit(0);
}
