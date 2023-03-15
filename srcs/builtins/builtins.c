/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:16:34 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/15 08:30:41 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_command(char *builtin, char *str)
{
	int	builtinlen;
	int	strlen;
	int	len;

	builtinlen = ft_strlen(builtin);
	strlen = ft_strlen(str);
	if (strlen < builtinlen)
		len = builtinlen;
	else
		len = strlen;
	if (ft_strncmp(str, builtin, len) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	(*builtin_arr(char *str))(t_data *data, t_cmds *cmds)
{
	static void	*builtins[7][2] = {
	{"echo", ft_echo},
	{"cd", ft_cd},
	{"pwd", ft_pwd},
	{"export", ft_export},
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
			if (!is_valid_command(builtins[i][0], str))
				return (builtins[i][1]);
		}
		i++;
	}
	return (NULL);
}
