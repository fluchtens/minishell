/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:18:22 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/28 15:04:01 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**whileloop_del_var(char **arr, char **rtn, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i] != NULL)
	{
		if (!(ft_strncmp(arr[i], str, equal_sign(arr[i]) - 1) == 0
				&& str[equal_sign(arr[i])] == '\0'
				&& arr[i][ft_strlen(str)] == '='))
		{
			rtn[j] = ft_strdup(arr[i]);
			if (rtn[j] == NULL)
			{
				free_array(rtn);
				return (rtn);
			}
			j++;
		}	
		i++;
	}
	return (rtn);
}

static char	**del_var(char **arr, char *str)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	rtn = whileloop_del_var(arr, rtn, str);
	return (rtn);
}

static int	is_valid_var_name(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(str[0]) && str[0] != 95)
		return (0);
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != 95)
			return (0);
		i++;
	}
	return (1);
}

static int	check_unset(t_cmds *cmds)
{
	int	i;

	if (!cmds->str[1])
		return (0);
	i = 0;
	while (cmds->str[1][i])
	{
		if (!is_valid_var_name(&cmds->str[1][i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(cmds->str[1], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_unset(t_data *data, t_cmds *cmds)
{
	char	**tmp;

	if (!check_unset(cmds))
		return (1);
	else
	{
		tmp = del_var(data->envp, cmds->str[1]);
		free_array(data->envp);
		data->envp = tmp;
	}
	return (0);
}
