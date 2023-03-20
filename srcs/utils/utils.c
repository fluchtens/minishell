/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 08:47:43 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/20 07:23:34 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialization(t_data *data)
{
	data->lexer = NULL;
	data->cmds = NULL;
	data->pid = NULL;
	data->heredoc = false;
	data->pidindex = 0;
	parse_paths(data);
	init_signals(0);
}

void	increment_shlvl(t_data *data)
{
	char	*temp;
	char	*temp_itoa;
	int		shlvl;

	temp = find_path(data->envp, "SHLVL=");
	shlvl = ft_atoi(temp);
	if (shlvl < 0)
		shlvl = 0;
	else
		shlvl++;
	free(temp);
	temp_itoa = ft_itoa(shlvl);
	temp = ft_strjoin("SHLVL=", temp_itoa);
	free(temp_itoa);
	if (!is_exist_var(data->envp, temp))
		data->envp = add_var_envp(data->envp, temp);
	free(temp);
}

char	*find_path(char **envp, char *var)
{
	int	len;
	int	new_len;
	int	i;

	i = 0;
	while (envp[i])
	{
		len = ft_strlen(var);
		new_len = ft_strlen(envp[i]) - len;
		if (!ft_strncmp(envp[i], var, len))
			return (ft_substr(envp[i], len, new_len));
		i++;
	}
	return (ft_strdup("\0"));
}

int	equal_pos(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] == '=')
			return (pos);
		pos++;
	}
	return (0);
}

int	more_pos(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] == '+')
			return (pos);
		pos++;
	}
	return (0);
}
