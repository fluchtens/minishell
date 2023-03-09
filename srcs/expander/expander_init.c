/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:42:26 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/09 10:52:49 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_return_value(char **final, char **temp)
{
	char	*finaltemp;
	char	*num;

	finaltemp = ft_strdup(*final);
	if (*temp)
		free(*temp);
	if (*final)
		free(*final);
	num = ft_itoa(g_global.error_num);
	*final = ft_strjoin(finaltemp, num);
	free(finaltemp);
	free(num);
	return (2);
}

int	get_env_data(char **str, t_data *data, char **final, int j)
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
	return (j + 1);
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
			while (str[i + 1 + j] != 34 && !ft_iswhitespace(str[i + 1 + j]) \
			&& str[i + 1 + j] != 39 && str[i + 1 + j] && str[i + 1 + j] != 63)
				j++;
			temp = ft_substr(str, i + 1, j);
			if (str[i + 1 + j] == 63 && j == 0)
				i += ft_return_value(&final, &temp);
			else
				i += get_env_data(&temp, data, &final, j);
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
	system("leaks minishell");
	return ;
}
