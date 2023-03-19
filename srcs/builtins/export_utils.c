/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:24:28 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/19 23:00:45 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_export_cmd(char *str)
{
	int	i;

	i = 0;
	if ((!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	while (str[i] && str[i] != '+' && str[i] != '=')
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	if (str[i] == '=')
		return (1);
	else if (str[i] == '+')
	{
		if (str[i + 1] == '=')
			return (1);
	}
	return (0);
}

int	check_export_cmd(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!is_valid_export_cmd(str[i]))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(str[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	more_var_content(char **envp, char *var)
{
	char	*var_name;
	char	*var_name_equal;
	char	*var_content;
	int		var_len;
	int		i;

	var_name = ft_substr(var, 0, more_pos(var));
	var_name_equal = ft_strjoin(var_name, "=");
	var_len = equal_pos(var_name_equal) + 1;
	free(var_name);
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], var_name_equal, var_len) == 0)
		{
			var_content = ft_strjoin(envp[i] + var_len, var + (var_len + 1));
			free(envp[i]);
			envp[i] = ft_strjoin(var_name_equal, var_content);
			free(var_name_equal);
			free(var_content);
			return (1);
		}
	}
	free(var_name_equal);
	return (0);
}

int	is_exist_var(char **envp, char *var)
{
	int	var_len;
	int	i;

	if (var[equal_pos(var) - 1] == '+')
	{
		if (!more_var_content(envp, var))
			return (0);
		return (1);
	}
	var_len = equal_pos(var) + 1;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, var_len) == 0)
		{
			free(envp[i]);
			envp[i] = ft_strdup(var);
			return (1);
		}
		i++;
	}
	return (0);
}
