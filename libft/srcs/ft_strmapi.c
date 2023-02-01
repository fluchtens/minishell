/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:26:32 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/25 07:46:33 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* char my_func(unsigned int i, char str)
{
	printf("Pos [%d] = %c\n", i, str);

	if (str >= 'a' && str <= 'z')
		str -= 32;
	return (str);
}

int main()
{
	char s[50] = "Hello World!";
	char *str;

	str = ft_strmapi(s, my_func);
	printf("Before ft_strmapi() = %s\n", s);
	printf("After ft_strmapi() = %s\n", str);
} */