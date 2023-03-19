/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:04:55 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/19 14:16:32 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_executor(t_data *data)
{
	init_signals(1);
	if (data->pipes_count > 0)
	{	
		data->pid = ft_calloc(sizeof(int), (data->pipes_count + 1));
		if (!data->pid)
			print_error(ERR_MALLOC, data);
		execute_multiple_cmd(data);
	}
	else
		execute_one_cmd(data, data->cmds);
	return (0);
}
