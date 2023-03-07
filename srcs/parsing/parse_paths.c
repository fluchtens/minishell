/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:33:52 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/07 09:11:44 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
