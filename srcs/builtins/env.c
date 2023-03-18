/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:02:05 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/18 19:05:29 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_data *data, t_cmds *cmds)
{
	(void) cmds;
	if (!data->envp)
		return (1);
	print_envp(data->envp, 0);
	return (0);
}
