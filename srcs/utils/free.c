/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:48:34 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/02 07:34:17 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_everythings(t_data *data)
{
	free(data->line);
	free_array(data->paths);
	free_array(data->envp);
	cmds_clear(&data->cmds);
	free(data->pwd);
	free(data->old_pwd);
	if (data->pipes_count)
		free(data->pid);
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
