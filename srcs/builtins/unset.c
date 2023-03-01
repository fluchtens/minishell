/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:18:22 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/01 14:03:26 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_equal_sign(char *str)
{
	if (str[0] && str[0] == '=')
		return (true);
	return (false);
}

static char **remove_var_envp(t_data *data, char *str)
{
	char **final;
	int	array_len;
	int	str_len;
	int	i;
	int	j;
	int	k;

	final = NULL;
	array_len = ft_array_len(data->envp);
	str_len = ft_strlen(str);
	i = 0;
	while (i < array_len)
	{
		if (ft_strncmp(data->envp[i], str, str_len) == 0 && is_equal_sign(data->envp[i] + str_len))
		{
			j = i;
			while (j < array_len - 1)
			{
				data->envp[i] = data->envp[j + 1];
				j++;
			}
			final = malloc(sizeof(char *) * (array_len - 1));
			if (!final)
				return (NULL);
			k = 0;
			while (k < i)
			{
				final[k] = data->envp[k];
				k++;
			}
			j = i;
			while (j < array_len - 1)
			{
				final[j] = data->envp[i + i];
				j++;
			}
			array_len--;
			i--;
		}
		i++;
	}
	print_envp(data);
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
	char **temp = remove_var_envp(data, cmds->str[1]);
	free_array(data->envp);
	data->envp = temp;
	printf("ARRAY LEN AFTER = %d\n", ft_array_len(data->envp));
	return (0);
}
