/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:18:22 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/02 10:30:06 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	allocate_size(char **envp, char *var)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) != 0)
			size++;
		i++;
	}
	return (size);
}

static char	**fill_envp(char **final, char **envp, char *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) != 0)
		{
			final[j] = ft_strdup(envp[i]);
			if (!final[j])
			{
				free_array(final);
				return (NULL);
			}
			j++;
		}
		free(envp[i]);
		i++;
	}
	free(envp);
	final[j] = NULL;
	return (final);
}

static char	**update_envp(char **envp, char *var)
{
	char	**final;

	final = malloc(sizeof(char *) * (allocate_size(envp, var) + 1));
	if (!final)
		return (NULL);
	final = fill_envp(final, envp, var);
	return (final);
}

static int	check_unset_args(t_cmds *cmds)
{
	int	i;

	i = 1;
	while (cmds->str[i])
	{
		if (is_valid_var_name(cmds->str[i]) == false)
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(cmds->str[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_unset(t_data *data, t_cmds *cmds)
{
	char	*temp;
	int		i;

	if (!cmds->str[1])
		return (0);
	if (!check_unset_args(cmds))
		return (1);
	i = 1;
	while (cmds->str[i])
	{
		temp = ft_strjoin(cmds->str[i], "=");
		data->envp = update_envp(data->envp, temp);
		free(temp);
		i++;
	}
	print_envp(data);
	return (0);
}
