/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:09:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/20 11:16:22 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	echo_flags_size(char **str, int *is_n_flag)
{
	int	i;
	int	j;

	i = 1;
	while (str[i] && str[i][0] == '-')
	{
		j = 1;
		while (str[i][j])
		{
			if (str[i][j] == 'n')
			{
				(*is_n_flag) = 1;
				j++;
			}
			else
				return (i);
		}
		i++;
	}
	return (i);
}

static int	echo_skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_iswhitespace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(t_data *data, t_cmds *cmds)
{
	int		is_n_flag;
	int		i;

	(void) data;
	is_n_flag = 0;
	i = echo_flags_size(cmds->str, &is_n_flag);
	while (cmds->str[i])
	{
		while (cmds->str[i + 1] && echo_skip_spaces(cmds->str[i]))
			i++;
		ft_putstr_fd(cmds->str[i], 1);
		if (cmds->str[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!is_n_flag)
		ft_putchar_fd('\n', 1);
	return (0);
}
