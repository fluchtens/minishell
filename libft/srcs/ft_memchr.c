/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:28:16 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:36:30 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	search;
	size_t			i;

	str = (unsigned char *)s;
	search = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == search)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	str[] = "Hello World!";
	char	str1[] = "Hello World!";

	printf("Before memchr() = %s\n", str);
	printf("After memchr() = %s\n", memchr(str, 'W', 12));

	printf("Before ft_memchr() = %s\n", str1);
	printf("After ft_memchr() = %s\n", ft_memchr(str1, 'W', 12));
} */