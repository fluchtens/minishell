/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:29:20 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/18 15:43:23 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	search;
	size_t	i;

	str = (char *)s;
	search = (char)c;
	i = ft_strlen(str) + 1;
	while (i--)
		if (str[i] == search)
			return (&str[i]);
	return (NULL);
}
