/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:17:42 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 07:42:38 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/* int main(void)
{
	char str[50] = "Coucou les amis.";
	char str1[50] = "Coucou les amis.";

	printf("\nBefore bzero(): %s", str);
	bzero(str, 4);
	printf("\nAfter bzero():  %s\n", str);

	printf("\nBefore ft_bzero(): %s", str1);
	ft_bzero(str1, 5);
	printf("\nAfter ft_bzero():  %s\n", str1);
} */