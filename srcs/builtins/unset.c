/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:18:22 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/01 15:03:47 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_equal_sign(char *str)
{
	if (str[0] && str[0] == '=')
		return (true);
	return (false);
}

static char **remove_var_envp(char **envp, char *var)
{
	char	**final;
	int		array_len;
	int		var_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	var_len = ft_strlen(var);
	array_len = ft_array_len(envp);
	final = ft_calloc(sizeof(char *), array_len + 1);
	if (!final)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, var_len) && !is_equal_sign(envp[i] + var_len))
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
	final[i] = NULL;
	return (final);
}

static int	check_unset_args(t_cmds *cmds)
{
	int	i;
	int	j;

	i = 1;
	while (cmds->str[i])
	{
		j = 0;
		while (cmds->str[i][j])
		{
			if (!is_valid_var_name(&cmds->str[i][j]))
			{
				ft_putstr_fd("minishell: unset: `", 2);
				ft_putstr_fd(cmds->str[i], 2);
				ft_putendl_fd("': not a valid identifier", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_unset(t_data *data, t_cmds *cmds)
{
	if (!cmds->str[1])
		return (0);
	if (!check_unset_args(cmds))
		return (1);
	printf("ARRAY LEN BEFORE = %d\n", ft_array_len(data->envp));

	// free_array(data->envp);
	data->envp = remove_var_envp(data->envp, cmds->str[1]);;

	printf("ARRAY LEN AFTER = %d\n", ft_array_len(data->envp));
	print_envp(data);
	return (0);
}
