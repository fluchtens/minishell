/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:16:52 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 08:49:47 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

/* int main(void)
{
	char str[] = "Coucou les amis.";
	char str1[] = "Coucou les amis.";

	printf("\nBefore memset(): %s", str);
	memset(str, '*', 4);
	printf("\nAfter memset():  %s\n", str);

	printf("\nBefore ft_memset(): %s", str1);
	ft_memset(str1, '*', 4);
	printf("\nAfter ft_memset():  %s\n", str1);
} */