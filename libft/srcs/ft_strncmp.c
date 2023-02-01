/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:29:14 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 09:14:43 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i]) && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* int	main(void)
{
	printf("%d\n", ft_strncmp("", "", 0));
	printf("%d\n", strncmp("", "", 0));
	printf("\n");
	printf("%d\n", ft_strncmp("aa", "aa", 0));
	printf("%d\n", strncmp("aa", "aa", 0));
	printf("\n");
	printf("%d\n", ft_strncmp("", "", 2));
	printf("%d\n", strncmp("", "", 2));
	printf("\n");
	printf("%d\n", ft_strncmp("aa", "", 2));
	printf("%d\n", strncmp("aa", "", 2));
	printf("\n");
	printf("%d\n", ft_strncmp("", "zz", 2));
	printf("%d\n", strncmp("", "zz", 2));
	printf("\n");
    printf("%d\n", ft_strncmp("aa", "aa", 2));
	printf("%d\n", strncmp("aa", "aa", 2));
	printf("\n");
    printf("%d\n", ft_strncmp("zz", "aa", 2));
	printf("%d\n", strncmp("zz", "aa", 2));
	printf("\n");
	printf("%d\n", ft_strncmp("aa", "zz", 2));
	printf("%d\n", strncmp("aa", "zz", 2));
} */