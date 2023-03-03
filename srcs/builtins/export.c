/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:45:11 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/03 17:56:48 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**fill_export_envp(char **final, char **envp, char *var)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		final[i] = ft_strdup(envp[i]);
		if (!final[i])
		{
			free_array(final);
			return (NULL);
		}
		free(envp[i]);
		i++;
	}
	final[i] = ft_strdup(var);
	if (!final[i])
	{
		free_array(final);
		return (NULL);
	}
	final[i + 1] = NULL;
	free(envp);
	return (final);
}

static char	**add_var_envp(char **envp, char *var)
{
	char	**final;
	int		array_len;

	array_len = ft_array_len(envp) + 1;
	final = malloc(sizeof(char *) * (array_len + 1));
	if (!final)
		return (NULL);
	final = fill_export_envp(final, envp, var);
	return (final);
}

static int	is_exist_var(t_data *data, char *var)
{
	int	len;
	int	i;

	i = 0;
	while (data->envp[i])
	{
		len = equal_pos(data->envp[i]) + 1;
		if (ft_strncmp(data->envp[i], var, len) == 0)
		{
			free(data->envp[i]);
			data->envp[i] = ft_strdup(var);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_export(t_data *data, t_cmds *cmds)
{
	char	*temp;
	int		i;

	if (!cmds->str[1])
		ft_env(data, cmds);
	if (!var_have_equal(cmds))
		return (0);
	if (!is_correct_export_var(cmds))
		return (1);
	i = 1;
	while (cmds->str[i])
	{
		if (!is_exist_var(data, cmds->str[i]))
		{
			temp = ft_remove_quotes(cmds->str[i]);
			data->envp = add_var_envp(data->envp, temp);
			free(temp);
		}
		i++;
	}
	return (0);
}
