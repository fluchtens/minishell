/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:24:28 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/03 18:00:46 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	var_have_equal(t_cmds *cmds)
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
			if (cmds->str[i][j] == 61)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	is_valid_export_var_name(char *str)
{
	int	i;

	i = 1;
	if ((!ft_isalpha(str[0]) && str[0] != 95))
		return (false);
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && !ft_isquote(str[i])
			&& str[i] != 95 && str[i] != 61)
			return (false);
		i++;
	}
	return (true);
}

int	is_correct_export_var(t_cmds *cmds)
{
	int	i;

	i = 1;
	while (cmds->str[i])
	{
		if (is_valid_export_var_name(cmds->str[i]) == false)
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
