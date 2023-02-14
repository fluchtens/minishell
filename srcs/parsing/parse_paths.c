/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:33:52 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/14 12:00:51 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
		i++;
	}
	return (NULL);
}

int	parse_paths(t_data *data)
{
	char	*path;
	char	*temp;
	int		last;
	int		i;

	path = find_path(data->envp);
	if (!path)
		return (0);
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
