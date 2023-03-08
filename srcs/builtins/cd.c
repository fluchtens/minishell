/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:06:58 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/08 10:44:45 by fluchten         ###   ########.fr       */
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

static int	path_perror(char *path)
{
	ft_putstr_fd("minishell: cd: ", 2);
	perror(path);
	free(path);
	return (1);
}

int	ft_cd(t_data *data, t_cmds *cmds)
{
	char	*path;
	int		ret;

	if (!cmds->str[1])
	{
		path = find_path(data, "HOME=");
		if (!path[0])
			return (print_error("minishell: cd: HOME not set", data));
	}
	else if (ft_strncmp(cmds->str[1], "-", 1) == 0)
	{
		path = find_path(data, "OLDPWD=");
		if (!path[0])
			return (print_error("minishell: cd: OLDPWD not set", data));
		ft_putendl_fd(path, 1);
	}
	else
		path = ft_strdup(cmds->str[1]);
	ret = chdir(path);
	if (ret == -1)
		return (path_perror(path));
	free(path);
	update_pwd(data);
	update_pwd_envp(data);
	return (0);
}
