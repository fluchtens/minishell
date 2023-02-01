/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:29:20 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 09:16:35 by fluchten         ###   ########.fr       */
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

/* int	main(void)
{
	char	str[] = "Hello World!";
	char	str1[] = "Hello World!";

	printf("Before strrchr() = %s\n", str);
	printf("After strrchr() = %s\n", strrchr(str, 'o'));
	printf("\n");
	printf("Before ft_strrchr() = %s\n", str1);
	printf("After ft_strrchr() = %s\n", ft_strrchr(str1, 'o'));
	printf("\n");
	printf("Before strrchr() = %s\n", str);
	printf("After strrchr() = %s\n", strrchr(str, 0));
	printf("\n");
	printf("Before ft_strrchr() = %s\n", str1);
	printf("After ft_strrchr() = %s\n", ft_strrchr(str1, 0));
} */