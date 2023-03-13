/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:02:05 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/13 12:15:59 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_data *data, t_cmds *cmds)
{
	int		i;

	i = 0;
	(void) cmds;
	while (data->envp[i])
	{
		ft_putendl_fd(data->envp[i], 1);
		i++;
	}
	return (0);
}
