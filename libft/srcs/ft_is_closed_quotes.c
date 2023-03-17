/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_closed_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:30:17 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/17 10:32:12 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_closed_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] && str[i] != '"')
				i++;
			if (str[i] != '"')
				return (0);
		}
		else if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (str[i] != '\'')
				return (0);
		}
		i++;
	}
	return (1);
}
