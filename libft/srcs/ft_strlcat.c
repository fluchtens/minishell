/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:26:07 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/25 13:12:18 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	if (size < dst_len)
		src_len += size;
	else
		src_len += dst_len;
	i = 0;
	while (src[i] && (dst_len + i) < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len);
}

/* int	main(void)
{
	char	dst[25] = "Boul et ";
	char	src[25] = "Bill";

	printf("strlat = %zu\n", strlcat(dst, src, 0));
    printf("ft_strlcat = %zu\n\n", ft_strlcat(dst, src, 0));

	printf("strlat = %zu\n", strlcat(dst, src, 4));
    printf("ft_strlcat = %zu\n\n", ft_strlcat(dst, src, 4));

	printf("strlat = %zu\n", strlcat(dst, src, 8));
    printf("ft_strlcat = %zu\n\n", ft_strlcat(dst, src, 8));

	printf("strlat = %zu\n", strlcat(dst, src, 9));
    printf("ft_strlcat = %zu\n\n", ft_strlcat(dst, src, 9));

	printf("strlat = %zu\n", strlcat(dst, src, 15));
    printf("ft_strlcat = %zu\n\n", ft_strlcat(dst, src, 15));

	printf("strlat = %zu\n", strlcat(dst, src, 20));
    printf("ft_strlcat = %zu\n\n", ft_strlcat(dst, src, 20));

	printf("strlat = %zu\n", strlcat(dst, src, 25));
    printf("ft_strlcat = %zu\n\n", ft_strlcat(dst, src, 25));

	printf("strlat = %zu\n", strlcat(0, src, 0));
    printf("ft_strlcat = %zu\n\n", ft_strlcat(0, src, 0));
} */