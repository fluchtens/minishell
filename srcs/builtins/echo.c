/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:09:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/10 09:59:27 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_data *data, t_cmds *cmds)
{
	int		is_n_flag;
	int		i;

	(void) data;
	if (!cmds->str[1])
	{
		ft_putchar_fd('\n', 1);
		return ;
	}
	is_n_flag = 0;
	i = 1;
	if (cmds->str[1][0] == '-' && cmds->str[1][1] == 'n')
	{
		is_n_flag = 1;
		i = 2;
	}
	while (cmds->str[i])
	{
		ft_putstr_fd(cmds->str[i], 1);
		if (cmds->str[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!is_n_flag)
		ft_putchar_fd('\n', 1);
}
