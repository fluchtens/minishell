/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:58:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/27 12:53:59 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_everythings(t_data *data)
{
	free(data->line);
	free(data->pwd);
	free(data->old_pwd);
	if (data->pipes_count)
		free(data->pid);
	free_array(data->paths);
	free_array(data->envp);
	cmds_clear(&data->cmds);
}

static int	str_is_digits(char *str)
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

static void	exit_code(char **array)
{
	int	code;

	if (!array[1])
		code = 0;
	else if (str_is_digits(array[1]))
		code = ft_atoi(array[1]);
	else
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(array[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		code = 255;
	}
	free_array(array);
	exit(code);
}

int	ft_exit(t_data *data, t_cmds *cmds)
{
	char	**array;
	int		i;

	i = 0;
	while (cmds->str[i])
		i++;
	ft_putendl_fd("exit", 2);
	if (i > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	array = ft_array_dup(cmds->str);
	free_everythings(data);
	exit_code(array);
	return (0);
}
