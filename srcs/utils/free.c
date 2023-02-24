/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:48:34 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/24 07:42:27 by fluchten         ###   ########.fr       */
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

int	reset_data(t_data *data)
{
	cmds_clear(&data->cmds);
	free(data->line);
	if (data->pid)
		free(data->pid);
	free_array(data->paths);
	initialization(data);
	data->reset = true;
	return (1);
}
