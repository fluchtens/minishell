/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:51:32 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/18 16:39:07 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_arrdup(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_arrdup(char **array)
{
	char	**final;
	size_t	len;
	size_t	i;

	len = 0;
	while (array[len])
		len++;
	final = malloc(sizeof(char *) * (len + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (array[i])
	{
		final[i] = ft_strdup(array[i]);
		if (!final[i])
		{
			free_arrdup(final);
			return (NULL);
		}
		i++;
	}
	return (final);
}
