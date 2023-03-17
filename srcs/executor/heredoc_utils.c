/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:38:08 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/17 08:39:17 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expander_heredoc(char **line, t_data *data)
{
	char	*temp;
	char	*str;

	temp = ft_strdup(*line);
	free(*line);
	str = expander_utils(temp, data);
	free(temp);
	return (str);
}

int	ft_have_quotes(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}
