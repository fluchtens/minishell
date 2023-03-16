/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 07:23:30 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/16 07:32:15 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_dollar(char *str, int check)
{
	int	i;

	i = check;
	if (!str[i] || str[i] != 36 || !str[i + 1] || ft_iswhitespace(str[i + 1]))
		return (EXIT_FAILURE);
	if (ft_isquote(str[i + 1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_expander_check(char c)
{
	if (c == 36)
		return (EXIT_FAILURE);
	if (c != 34 && !ft_iswhitespace(c) && c != 39 && c && c != 63)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
