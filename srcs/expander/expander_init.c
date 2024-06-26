/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:42:26 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/19 14:27:56 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_return_value(char **final, char **temp)
{
	char	*finaltemp;
	char	*num;

	finaltemp = ft_strdup(*final);
	if (*temp)
		free(*temp);
	if (*final)
		free(*final);
	num = ft_itoa(g_ret_value);
	*final = ft_strjoin(finaltemp, num);
	free(finaltemp);
	free(num);
	return (2);
}

static int	get_env_data(char **str, t_data *data, char **final, int j)
{
	char	*temp;
	char	*path;
	char	*temp2;

	temp = ft_strjoin(*str, "=");
	path = find_path(data->envp, temp);
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

char	*expander_utils(char *str, t_data *data)
{
	int		i;
	int		j;
	char	*temp;
	char	*final;

	i = 0;
	final = ft_strdup("\0");
	while (str[i])
	{
		if (str[i] && str[i] == 36 && !ft_check_dollar(str, i))
		{
			j = 0;
			while (!ft_expander_check(str[i + 1 + j]))
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
	return ;
}
