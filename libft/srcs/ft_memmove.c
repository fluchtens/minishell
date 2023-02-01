/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:28:28 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:48:44 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_new;
	const char	*src_new;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	dst_new = (char *)dst;
	src_new = (char const *)src;
	if (src_new < dst_new)
	{
		i = 0;
		while (++i <= len)
			dst_new[len - i] = src_new[len - i];
	}
	else
	{
		i = -1;
		while (++i < len)
			dst_new[i] = src_new[i];
	}
	return (dst);
}

/* int main (void)
{
	char dest[50] = "Allo!";
	char src[50] = "Salut!";

	char dest1[50] = "Allo!";
	char src1[50] = "Salut!";

	printf("Before memmove() = %s\n", dest);
	memmove(dest, src, strlen(src) + 1);
	printf("After memmove() = %s\n\n", dest);

	printf("Before ft_memmove() = %s\n", dest1);
	ft_memmove(dest1, src1, strlen(src) + 1);
	printf("After ft_memmove() = %s\n\n", dest1);

	char str1[50] = "123456";
	char str2[50] = "123456";
 
    ft_memcpy(str1+1, str1, 6);
	ft_memmove(str2+1, str2, 6);
 
    printf("%s\n", str1);
	printf("%s\n", str2);
} */