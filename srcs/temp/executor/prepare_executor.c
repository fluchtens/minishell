/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_executor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:06:58 by fpolycar          #+#    #+#             */
/*   Updated: 2023/02/20 17:24:43 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prepare_executor(t_data *data)
{
	signal(SIGQUIT, sigquit_handler);
	g_global.in_cmd = 1;
	if (data->pipes_count == 0)
		single_cmd(data->simple_cmds, data);
	else
	{
		data->pid = ft_calloc(sizeof(int), data->pipes_count + 2);
		if (!data->pid)
			return (ft_error(1, data));
		executor(data);
	}
	g_global.in_cmd = 0;
	return (EXIT_SUCCESS);
}
