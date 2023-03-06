/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:04:55 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/06 13:57:37 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	executor_init(t_data *data)
{
	signal(SIGQUIT, sigquit_handler);
	g_global.in_cmd = 1;
	if (!data->pipes_count)
		one_cmd(data, data->cmds);
	else
	{
		data->pid = ft_calloc(sizeof(int), (data->pipes_count + 2));
		if (!data->pid)
			return (print_error(MSG_MALLOC_ERR, data));
		executor(data);
	}
	g_global.in_cmd = 0;
	return (EXIT_SUCCESS);
}
