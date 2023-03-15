/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:09:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/15 08:29:08 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	echo_nb_flags(char **str, int i, int *is_n_flag)
{
	while (str[i] && str[i][0] == '-')
	{
		if (ft_strncmp(str[i], "-n", 2))
			break ;
		else
		{
			(*is_n_flag) = 1;
			i++;
		}
	}
	return (i);
}

int	ft_echo(t_data *data, t_cmds *cmds)
{
	int		is_n_flag;
	int		i;

	(void) data;
	is_n_flag = 0;
	i = 1;
	if (ft_array_len(cmds->str) > 2)
		i = echo_nb_flags(cmds->str, i, &is_n_flag);
	while (cmds->str[i])
	{
		ft_putstr_fd(cmds->str[i], 1);
		if (cmds->str[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!is_n_flag)
		ft_putchar_fd('\n', 1);
	return (0);
}
