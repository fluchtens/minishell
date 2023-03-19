/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 08:47:43 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/19 14:02:07 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialization(t_data *data)
{
	data->lexer = NULL;
	data->cmds = NULL;
	data->pid = NULL;
	data->heredoc = false;
	data->pidindex = 0;
	parse_paths(data);
	init_signals(0);
}

void	increment_shlvl(t_data *data)
{
	char	*temp;
	int		shlvl;

	temp = find_path(data, "SHLVL=");
	shlvl = ft_atoi(temp);
	if (shlvl < 0)
		shlvl = 0;
	else
		shlvl++;
	free(temp);
	temp = ft_strjoin("SHLVL=", ft_itoa(shlvl));
	if (!is_exist_var(data->envp, temp))
		data->envp = add_var_envp(data->envp, temp);
	free(temp);
}

char	*find_path(t_data *data, char *envp)
{
	int	len;
	int	new_len;
	int	i;

	i = 0;
	while (data->envp[i])
	{
		len = ft_strlen(envp);
		new_len = ft_strlen(data->envp[i]) - len;
		if (!ft_strncmp(data->envp[i], envp, len))
			return (ft_substr(data->envp[i], len, new_len));
		i++;
	}
	return (ft_strdup("\0"));
}
