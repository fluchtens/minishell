/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:15:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/17 17:39:54 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(t_data *data)
{
	free(data->old_pwd);
	data->old_pwd = ft_strdup(data->pwd);
	free(data->pwd);
	data->pwd = getcwd(NULL, sizeof(NULL));
}

int	ft_pwd(t_data *data, t_cmds *cmds)
{
	char	*temp;

	(void) data;
	(void) cmds;
	temp = getcwd(NULL, sizeof(NULL));
	if (!temp)
		return (1);
	ft_putendl_fd(temp, 1);
	free(temp);
	return (0);
}
