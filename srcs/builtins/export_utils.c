/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:24:28 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/03 18:09:19 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	equal_pos(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] == '=')
			return (pos);
		pos++;
	}
	return (0);
}

bool	export_cmd_have_equal(t_cmds *cmds)
{
	int	i;
	int	j;

	i = 0;
	if (!cmds->str)
		return (false);
	while (cmds->str[i])
	{
		j = 0;
		while (cmds->str[i][j])
		{
			if (cmds->str[i][j] == '=')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	is_valid_export_cmd(char *str)
{
	int	i;

	i = 1;
	if ((!ft_isalpha(str[0]) && str[0] != '_'))
		return (false);
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && !ft_isquote(str[i])
			&& str[i] != '_' && str[i] != '=')
			return (false);
		i++;
	}
	return (true);
}

int	check_export_cmd(t_cmds *cmds)
{
	int	i;

	i = 1;
	while (cmds->str[i])
	{
		if (is_valid_export_cmd(cmds->str[i]) == false)
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(cmds->str[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
