/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:04:06 by fluchten          #+#    #+#             */
/*   Updated: 2023/03/03 11:04:35 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char *str, char c)
{
	char	*final;
	int		size;

	size = ft_strlen(str);
	final = ft_calloc(sizeof(char), (size + 2));
	if (!final)
		return (NULL);
	size = 0;
	if (str)
	{
		while (str[size])
		{
			final[size] = str[size];
			size++;
		}	
	}
	final[size] = c;
	final[size + 1] = '\0';
	if (str)
		free(str);
	return (final);
}
