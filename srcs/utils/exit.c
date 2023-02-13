/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:37:38 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/13 12:07:10 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_everything(t_data *data)
{
	if (data->line)
		free(data->line);
	if (data->envp)
		free_arr(data->envp);
	if (data->paths)
		free_arr(data->paths);
}

void	exit_error(t_data *data, char *str, int error)
{
	free_everything(data);
	if (error == 1)
	{
		ft_putendl_fd(str, 2);
		exit(EXIT_FAILURE);
	}
	else if (error == 0)
	{
		ft_putendl_fd(str, 1);
		exit(EXIT_SUCCESS);
	}
}
