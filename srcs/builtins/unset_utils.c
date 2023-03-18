/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:26:16 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/18 19:31:42 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_unset_cmd(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	while (str[i])
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	check_unset_cmd(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!is_valid_unset_cmd(str[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(str[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
