/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:06:58 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/28 12:06:42 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_pwd(t_data *data)
{
	free(data->old_pwd);
	data->old_pwd = ft_strdup(data->pwd);
	free(data->pwd);
	data->pwd = getcwd(NULL, sizeof(NULL));
}

static void	update_pwd_envp(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], "PWD=", 4))
		{
			free(data->envp[i]);
			data->envp[i] = ft_strjoin("PWD=", data->pwd);
		}
		if (!ft_strncmp(data->envp[i], "OLDPWD=", 7))
		{
			free(data->envp[i]);
			data->envp[i] = ft_strjoin("OLDPWD=", data->old_pwd);
		}
		i++;
	}
}

static char	*get_path(t_data *data, t_cmds *cmds)
{
	char	*path;

	path = NULL;
	if (!cmds->str[1])
		path = find_path(data, "HOME=");
	else if (ft_strncmp(cmds->str[1], "-", 1) == 0)
		path = find_path(data, "OLDPWD=");
	else
		path = ft_strdup(cmds->str[1]);
	return (path);
}

int	ft_cd(t_data *data, t_cmds *cmds)
{
	char	*path;
	int		ret;

	path = get_path(data, cmds);
	if (!path)
		return (1);
	ret = chdir(path);
	if (ret == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		perror(path);
		free(path);
		return (1);
	}
	free(path);
	update_pwd(data);
	update_pwd_envp(data);
	return (0);
}
