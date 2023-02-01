/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:28:20 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:38:13 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	printf("%d\n", memcmp("test", "test", 0));
	printf("%d\n", ft_memcmp("test", "test", 0));
	printf("\n");
	printf("%d\n", memcmp("dcba", "abcd", 4));
	printf("%d\n", ft_memcmp("dcba", "abcd", 4));
	printf("\n");
	printf("%d\n", memcmp("abcd", "dcba", 4));
	printf("%d\n", ft_memcmp("abcd", "dcba", 4));
	printf("\n");
	printf("%d\n", memcmp("dupont", "dupont", 6));
	printf("%d\n", ft_memcmp("dupont", "dupont", 6));
	printf("\n");
	printf("%d\n", memcmp("dupont", "dupond", 6));
	printf("%d\n", ft_memcmp("dupont", "dupond", 6));
	printf("\n");
	printf("%d\n", memcmp("dupond", "dupont", 6));
	printf("%d\n", ft_memcmp("dupond", "dupont", 6));
} */