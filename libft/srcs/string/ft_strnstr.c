/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:29:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/02/18 15:43:20 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;
	size_t	needle_len;

	needle_len = ft_strlen((char *)needle);
	if (needle_len == 0 || haystack == needle)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while (haystack[i] && i < len)
	{
		x = 0;
		while (haystack[i + x] && haystack[i + x] == needle[x] && i + x < len)
			x++;
		if (needle[x] == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
