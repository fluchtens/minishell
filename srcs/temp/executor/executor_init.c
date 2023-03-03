/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:07:31 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/02 19:40:51 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_executor(t_data *data)
{
	signal(SIGQUIT, sigquit_handler);
	g_global.in_cmd = 1;
	if (data->pipes_count == 0)
		single_cmd(data->cmds, data);
	else
	{
		data->pid = ft_calloc(sizeof(int), data->pipes_count + 2);
		if (!data->pid)
			print_error(MSG_MALLOC_ERR, data);
		executor(data);
	}
	g_global.in_cmd = 0;
	return (EXIT_SUCCESS);
}
