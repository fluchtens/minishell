/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:24:28 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/17 12:46:37 by fluchten         ###   ########.fr       */
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

static int	is_valid_export_cmd(char *str)
{
	int	i;

	i = 0;
	if ((!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i])
			&& str[i] != '_' && str[i] != '=' && str[i] != ' ')
			return (0);
		i++;
	}
	if (!equal_pos(str))
		return (0);
	return (1);
}

int	check_export_cmd(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!is_valid_export_cmd(str[i]))
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(str[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
