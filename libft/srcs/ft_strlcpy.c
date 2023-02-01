/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:04:12 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/25 13:12:05 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/* int	main(void)
{
	char	dest[500] = "Salut";
	char	src[500] = "Bonjour";

	printf("%lu\n", strlcpy(dest, src, 0));
	printf("%lu\n\n", ft_strlcpy(dest, src, 0));

	printf("%lu\n", strlcpy(dest, src, 5));
	printf("%lu\n\n", ft_strlcpy(dest, src, 5));

	printf("%lu\n", strlcpy(dest, src, 50));
	printf("%lu\n\n", ft_strlcpy(dest, src, 50));
} */
