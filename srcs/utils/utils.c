/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:09:53 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/10 12:02:09 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_arrdup(char **arr)
{
	char	**final;
	size_t	len;
	size_t	i;

	len = 0;
	while (arr[len])
		len++;
	final = malloc(sizeof(char *) * (len + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		final[i] = ft_strdup(arr[i]);
		if (!final[i])
		{
			free_arr(final);
			return (NULL);
		}
		i++;
	}
	return (final);
}
