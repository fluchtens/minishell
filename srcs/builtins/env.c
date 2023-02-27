/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:02:05 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/27 12:21:54 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_data *data, t_cmds *cmds)
{
	int		i;

	i = 0;
	(void) cmds;
	while (data->envp[i])
	{
		printf("%s\n", data->envp[i]);
		i++;
	}
}
