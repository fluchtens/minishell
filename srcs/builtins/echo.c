/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:09:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/15 09:35:15 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	stop_while(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (EXIT_SUCCESS);
	if (str[i] != '-')
		return (EXIT_FAILURE);
	i++;
	while (str[i] == 'n')
		i++;
	if (!str[i])
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

static int	echo_nb_flags(char **str, int i, int *is_n_flag)
{
	while (str[i] && str[i][0] == '-')
	{
		if (stop_while(str[i]))
			break ;
		else
		{
			(*is_n_flag) = 1;
			i++;
		}
		while (str[i])
		{
			if (!ft_iswhitespace(str[i][0]) && str[i][0])
				break ;
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
	while (cmds->str[i])
	{
		if (!ft_iswhitespace(cmds->str[i][0]) && cmds->str[i][0])
			break ;
		i++;
	}
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
