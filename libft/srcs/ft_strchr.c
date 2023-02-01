/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:28:40 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 09:06:18 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	search;
	size_t	i;

	str = (char *)s;
	search = (char)c;
	i = 0;
	while (str[i] && str[i] != search)
		i++;
	if (str[i] == search)
		return ((char *)&str[i]);
	return (NULL);
}

/* int	main(void)
{
	char	str[] = "Hello World!";
	char	str1[] = "Hello World!";

	printf("Before strchr() = %s\n", str);
	printf("After strchr() = %s\n", strchr(str, 'W'));
	printf("\n");
	printf("Before ft_strchr() = %s\n", str1);
	printf("After ft_strchr() = %s\n", ft_strchr(str1, 'W'));
	printf("\n");
	printf("Before strchr() = %s\n", str);
	printf("After strchr() = %s\n", strchr(str, 0));
	printf("\n");
	printf("Before ft_strchr() = %s\n", str1);
	printf("After ft_strchr() = %s\n", ft_strchr(str1, 0));
} */