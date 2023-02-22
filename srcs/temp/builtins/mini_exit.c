/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:16:42 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/21 12:22:18 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

void	free_tools(t_data *data)
{
	free_array(data->paths);
	free_array(data->envp);
	free(data->line);
	cmds_clear(&data->cmds);
	free(data->pwd);
	free(data->old_pwd);
	if (data->pipes_count)
		free(data->pid);
}

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	determine_exit_code(char **str)
{
	int	exit_code;

	if (!str[1])
		exit_code = 0;
	else if (is_str_digit(str[1]))
		exit_code = ft_atoi(str[1]);
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit_code = 255;
	}
	free_array(str);
	exit(exit_code);
}

int	mini_exit(t_data *data, t_cmds *cmds)
{
	char	**str;

	ft_putendl_fd("exit", STDERR_FILENO);
	if (cmds->str[1] && cmds->str[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	str = ft_arrdup(cmds->str);
	free_tools(data);
	determine_exit_code(str);
	return (EXIT_SUCCESS);
}
