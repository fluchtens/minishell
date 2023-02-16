/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:18:01 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/02/15 08:36:08 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count_splits(t_data *data, char const *s)
{
	int		i;
	int		len;
	bool	in_word;

	i = 0;
	len = 0;
	in_word = 0;
	while (s[i])
	{
		if (!is_white_space(s[i]) && !ft_quote_check(data, s[i]))
		{
			if (!in_word)
			{
				len++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	data->quote.sing = 0;
	data->quote.doub = 0;
	return (len);
}

static char	**ft_free(char **split, int i)
{
	while (i)
	{
		free(split[i]);
		i--;
	}
	free(split[i]);
	free(split);
	split = NULL;
	return (split);
}

static int	ft_char_count(const char *str)
{
	int		len;
	t_data	data;

	len = 0;
	data.quote.sing = 0;
	data.quote.doub = 0;
	while (str[len])
	{
		while (str[len] && ft_quote_check(&data, str[len]))
			len++;
		if (str[len] && is_white_space(str[len]) && \
		!ft_quote_check(&data, str[len]))
			break ;
		len++;
	}
	data.quote.sing = 0;
	data.quote.doub = 0;
	return (len);
}

static char	**ft_tab_split(t_data *data, char **split, char const *s)
{
	int		i;
	int		len;
	int		line;

	i = 0;
	line = 0;
	while (line < ft_count_splits(data, s))
	{
		while (s[i] && is_white_space(s[i]))
			i++;
		len = ft_char_count(s + i);
		split[line] = ft_strdup_size(s + i, len + 1);
		if (!split[line])
			return (ft_free(split, line));
		line++;
		i += len;
	}
	split[line] = NULL;
	return (split);
}

char	**ft_split_space(t_data *data, char const *s)
{
	char	**split;
	int		size;

	if (!s || !data)
		return (NULL);
	size = ft_count_splits(data, s);
	split = malloc(sizeof(char *) * (size + 1));
	if (!split)
		exit (EXIT_FAILURE);
	split = ft_tab_split(data, split, s);
	if (!split)
		exit (EXIT_FAILURE);
	data->quote.sing = 0;
	data->quote.doub = 0;
	return (split);
}
