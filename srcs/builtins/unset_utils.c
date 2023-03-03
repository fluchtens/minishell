/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:26:16 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/03 11:30:11 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_valid_unset_var_name(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(str[0]) && str[0] != 95)
		return (false);
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != 95)
			return (false);
		i++;
	}
	return (true);
}

int	is_correct_unset_var(t_cmds *cmds)
{
	int	i;

	i = 1;
	while (cmds->str[i])
	{
		if (is_valid_unset_var_name(cmds->str[i]) == false)
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(cmds->str[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
