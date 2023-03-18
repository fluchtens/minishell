/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:49:35 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/18 20:22:34 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_envp(t_data *data, char **envp)
{
	data->envp = ft_array_dup(envp);
	if (!data->envp)
		return (0);
	return (1);
}

int	parse_pwd(t_data *data)
{
	int	len;
	int	i;

	i = 0;
	data->pwd = NULL;
	data->old_pwd = NULL;
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], "PWD=", 4))
		{
			len = ft_strlen(data->envp[i]) - 4;
			data->pwd = ft_substr(data->envp[i], 4, len);
		}
		if (!ft_strncmp(data->envp[i], "OLDPWD=", 7))
		{
			len = ft_strlen(data->envp[i]) - 7;
			data->old_pwd = ft_substr(data->envp[i], 7, len);
		}
		i++;
	}
	return (1);
}

int	parse_paths(t_data *data)
{
	char	*path;
	char	*temp;
	int		last;
	int		i;

	path = find_path(data, "PATH=");
	data->paths = ft_split(path, ':');
	free(path);
	i = 0;
	while (data->paths[i])
	{
		last = ft_strlen(data->paths[i]) - 1;
		if (ft_strncmp(&data->paths[i][last], "/", 1))
		{
			temp = ft_strjoin(data->paths[i], "/");
			free(data->paths[i]);
			data->paths[i] = temp;
		}
		i++;
	}
	return (1);
}
