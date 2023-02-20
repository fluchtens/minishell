/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 07:39:02 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/20 09:00:30 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_pwd(t_data *data)
{
	data->pwd = NULL;
	data->old_pwd = NULL;
	return (1);
}

/* int	parse_pwd(t_data *data)
{
	int	i;

	i = 0;
	data->pwd = NULL;
	data->old_pwd = NULL;
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], "PWD=", 4))
			data->pwd = ft_substr(data->envp[i], 4, ft_strlen(data->envp[i]) - 4);
		if (!ft_strncmp(data->envp[i], "OLDPWD=", 7))
			data->old_pwd = ft_substr(data->envp[i], 7, ft_strlen(data->envp[i]) - 7);
		i++;
	}
	return (1);
} */