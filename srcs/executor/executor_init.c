/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:04:55 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/08 11:14:12 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_executor(t_data *data)
{
	signal(SIGQUIT, sigquit_handler);
	g_global.in_cmd = 1;
	if (data->pipes_count > 0)
	{	
		data->pid = ft_calloc(sizeof(int), (data->pipes_count + 2));
		if (!data->pid)
			return (print_error(ERR_MALLOC, data));
		executor(data);
	}
	else
		execute_one_cmd(data, data->cmds);
	g_global.in_cmd = 0;
	return (0);
}
