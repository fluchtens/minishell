/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:16:34 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/28 13:20:00 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	(*builtin_arr(char *str))(t_data *data, t_cmds *cmds)
{
	static void	*builtins[7][2] = {
	{"echo", ft_echo},
	{"cd", ft_cd},
	{"pwd", ft_pwd},
	{"export", mini_export},
	{"unset", ft_unset},
	{"env", ft_env},
	{"exit", ft_exit}
	};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(builtins[i][0], str, ft_strlen((builtins[i][0]))))
				return (builtins[i][1]);
		}
		i++;
	}
	return (NULL);
}
