/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:58:46 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/17 17:25:14 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static long	exit_code(char **str)
{
	long	code;
	int		invalid;

	code = 0;
	if (!str[1])
		code = 0;
	else if (ft_str_isdigits(str[1]))
	{
		code = ft_atol(str[1], &invalid);
		if (invalid == 1)
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(str[1], 2);
			ft_putendl_fd(": numeric argument required", 2);
			code = 255;
		}
	}
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
	long	code;
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
