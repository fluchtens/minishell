/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:58:29 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/03/03 11:14:57 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	remove_quotes_utils(char *str, bool type, int i, char **final)
{
	char	*temp;
	char	*temp2;
	int		j;

	j = i + 1;
	if (type)
		while (str[j] != 34 && str[j])
			j++;
	else
		while (str[j] != 39 && str[j])
			j++;
	temp = ft_substr(str, i + 1, j - i - 1);
	temp2 = ft_strjoin(*final, temp);
	i = j + 1;
	free(temp);
	if (*final)
		free(*final);
	*final = ft_strdup(temp2);
	if (temp2)
		free(temp2);
	return (i);
}

char	*ft_remove_quotes(char *str)
{
	int		i;
	char	*final;

	i = 0;
	final = NULL;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == 34)
			i = remove_quotes_utils(str, 1, i, &final);
		else if (str[i] == 39)
			i = remove_quotes_utils(str, 0, i, &final);
		else
			final = ft_strjoin_char(final, str[i++]);
	}
	// free(str);
	return (final);
}
