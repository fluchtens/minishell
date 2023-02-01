/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:29:18 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 09:15:19 by fluchten         ###   ########.fr       */
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

/* int	main(void)
{
	char	str[] = "Coucou les amis. Comment ca va ?";

	printf("strchr() = %s\n", strnstr(str, "Comment", 50));
	printf("ft_strchr() = %s\n\n", ft_strnstr(str, "Comment", 50));

	printf("strchr() = %s\n", strnstr(str, "jsp", 50));
	printf("ft_strchr() = %s\n\n", ft_strnstr(str, "jsp", 50));

	printf("strchr() = %s\n", strnstr(str, "Comment", 6));
	printf("ft_strchr() = %s\n\n", ft_strnstr(str, "Comment", 6));

	printf("strchr() = %s\n", strnstr(str, "", 50));
	printf("ft_strchr() = %s\n\n", ft_strnstr(str, "", 50));

	printf("strchr() = %s\n", strnstr(0, "", 0));
	printf("ft_strchr() = %s\n\n", ft_strnstr(0, "", 0));
} */