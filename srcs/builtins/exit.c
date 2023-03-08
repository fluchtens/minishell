/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:58:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/08 10:24:56 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exit_code(char **str)
{
	int	code;

	code = 0;
	if (!str[1])
		code = 0;
	else if (ft_str_isdigits(str[1]))
		code = ft_atoi(str[1]);
	else if (!ft_str_isdigits(str[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(str[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		code = 255;
	}
	return (code);
}

int	ft_exit(t_data *data, t_cmds *cmds)
{
	int		code;
	int		args;

	args = ft_array_len(cmds->str);
	ft_putendl_fd("exit", 2);
	if (args > 2)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (1);
	}
	else
	{
		code = exit_code(cmds->str);
		free_everythings(data);
		exit(code);
	}
	return (0);
}
