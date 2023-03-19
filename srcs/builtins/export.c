/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:45:11 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/19 23:08:39 by fluchten         ###   ########.fr       */
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

char	**add_var_envp(char **envp, char *var)
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

static char	*rename_more_equal_var(char *var)
{
	char	*var_name;
	char	*var_name_equal;
	char	*var_final;
	int		var_len;

	var_name = ft_substr(var, 0, more_pos(var));
	var_name_equal = ft_strjoin(var_name, "=");
	var_len = equal_pos(var_name_equal) + 1;
	var_final = ft_strjoin(var_name_equal, var + (var_len + 1));
	free(var_name);
	free(var_name_equal);
	return (var_final);
}

static int	export_have_args(t_data *data, t_cmds *cmds)
{
	if (!cmds->str[1])
	{
		sort_export_envp(data);
		print_envp(data->envp_sorted, 1);
		free_array(data->envp_sorted);
		return (0);
	}
	return (1);
}

int	ft_export(t_data *data, t_cmds *cmds)
{
	char	*temp;
	int		i;

	if (!export_have_args(data, cmds))
		return (0);
	if (!check_export_cmd(cmds->str))
		return (1);
	i = 1;
	while (cmds->str[i])
	{
		if (!is_exist_var(data->envp, cmds->str[i]))
		{
			if (cmds->str[i][equal_pos(cmds->str[i]) - 1] == '+')
			{
				temp = rename_more_equal_var(cmds->str[i]);
				data->envp = add_var_envp(data->envp, temp);
				free(temp);
			}
			else
				data->envp = add_var_envp(data->envp, cmds->str[i]);
		}
		i++;
	}
	return (0);
}
