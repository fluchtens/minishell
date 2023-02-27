/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:09:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/27 09:13:10 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_data *data, t_cmds *cmds)
{
	int		n_flag;
	int		i;

	i = 1;
	n_flag = 0;
	(void) data;
	if (cmds->str[1][0] == '-' && cmds->str[1][1] == 'n')
	{
		n_flag = 1;
		i = 2;
	}
	while (cmds->str[i])
	{
		printf("%s", cmds->str[i]);
		if (cmds->str[i + 1])
			printf(" ");
		i++;
	}
	if (!n_flag)
		printf("\n");
}
