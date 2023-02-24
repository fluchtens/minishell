/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:51:32 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/24 09:57:27 by fluchten         ###   ########.fr       */
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

char	**ft_array_dup(char **array)
{
	char	**final;
	size_t	len;
	size_t	i;

	len = 0;
	while (array[len])
		len++;
	final = ft_calloc(sizeof(char *), (len + 1));
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
