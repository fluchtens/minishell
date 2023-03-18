/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:53:59 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/18 19:06:13 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_envp(char **envp, int is_sorted)
{
	int	i;

	i = 0;
	if (!envp)
		return ;
	while (envp[i])
	{
		if (is_sorted)
			ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(envp[i], 1);
		i++;
	}
}

static void	sort_envp(char **envp_sorted, int length)
{
	char	*temp;
	int		len;
	int		i;
	int		j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			len = ft_strlen(envp_sorted[j]);
			if (ft_strncmp(envp_sorted[i], envp_sorted[j], len) > 0)
			{
				temp = ft_strdup(envp_sorted[i]);
				free(envp_sorted[i]);
				envp_sorted[i] = ft_strdup(envp_sorted[j]);
				free(envp_sorted[j]);
				envp_sorted[j] = ft_strdup(temp);
				free(temp);
			}
			j++;
		}
		i++;
	}
}

void	sort_export_envp(t_data *data)
{
	char	**temp;
	int		length;

	temp = ft_array_dup(data->envp);
	length = ft_array_len(data->envp);
	sort_envp(temp, length);
	data->envp_sorted = temp;
}
