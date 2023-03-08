/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:42:26 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/08 12:08:38 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_data(char *str, t_data *data)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin(str, "=");
	path = find_path(data, temp);
	return (path);
}

static char	*expander_utils(char *str, t_data *data)
{
	int		i;
	int		j;
	char	*result;
	char	*temp;
	char	*final;

	i = 0;
	final = ft_strdup("\0");
	while (str[i])
	{
		if (str[i] && str[i + 1] && str[i] == 36 && str[i + 1] != 36)
		{
			j = 0;
			while (str[i + 1 + j] && !ft_iswhitespace(str[i + j]) \
			&& str[i] != 39 && str[i] != 34)
				j++;
			temp = ft_substr(str, i + 1, j);
			result = get_env_data(temp, data);
			final = ft_strjoin(final, result);
			i += j + 1;
		}
		else
			final = ft_strjoin_char(final, str[i++]);
	}
	return (final);
}

char	**expander(t_data *data, char **str)
{
	char	*temp;
	int		i;

	i = -1;
	while (str[++i])
	{
		temp = expander_utils(str[i], data);
		str[i] = ft_remove_quotes(temp);
	}
	return (str);
}
