/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:04:10 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:50:08 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_new;
	char const	*src_new;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	dst_new = (char *)dst;
	src_new = (char const *)src;
	i = 0;
	while (i < n)
	{
		dst_new[i] = src_new[i];
		i++;
	}
	return (dst);
}

/* int main (void)
{
	char dest[50] = "Bonjour!";
	char src[50] = "Bonsoir!";

	char dest1[50] = "Bonjour!";
	char src1[50] = "Bonsoir!";

	printf("Before memcpy() = %s\n", dest);
	printf("After memcpy() = %s\n\n", memcpy(dest, src, 50));

	printf("Before ft_memcpy() = %s\n", dest1);
	printf("After ft_memcpy() = %s\n\n", ft_memcpy(dest1, src1, 50));
} */
