/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:42:26 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/09 09:42:06 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_env_data(char **str, t_data *data, char **final)
{
	char	*temp;
	char	*path;
	char	*temp2;

	temp = ft_strjoin(*str, "=");
	path = find_path(data, temp);
	temp2 = ft_strdup(*final);
	if (*final)
		free(*final);
	*final = ft_strjoin(temp2, path);
	free(temp2);
	free(path);
	free(temp);
	free(*str);
	return ;
}

static char	*expander_utils(char *str, t_data *data)
{
	int		i;
	int		j;
	char	*temp;
	char	*final;

	i = 0;
	final = ft_strdup("\0");
	while (str[i])
	{
		if (str[i] && str[i] == 36)
		{
			j = 0;
			while (str[i + 1 + j] && !ft_iswhitespace(str[i + 1 + j]) \
			&& str[i + 1 + j] != 39 && str[i + 1 + j] != 34)
				j++;
			temp = ft_substr(str, i + 1, j);
			get_env_data(&temp, data, &final);
			i += j + 1;
		}
		else
			final = ft_strjoin_char(final, str[i++]);
	}
	return (final);
}

void	init_expander(t_data *data, t_cmds *cmds)
{
	char	*temp;
	int		i;

	i = -1;
	while (cmds->str[++i])
	{
		temp = expander_utils(cmds->str[i], data);
		free(cmds->str[i]);
		cmds->str[i] = ft_remove_quotes(temp);
		free(temp);
	}
	return ;
}
