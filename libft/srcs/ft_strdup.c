/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:28:45 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 09:08:39 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*final;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	final = malloc(sizeof(char) * (len + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (i < len)
	{
		final[i] = s1[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}

/* int	main(void)
{
	char	*str_original = "after value";
	char	*str_duplicate = "before value";

    char	*str_original1 = "after value";
	char	*str_duplicate2 = "before value";

	printf("before strdup() = %s : %p\n", str_duplicate, str_duplicate);
	str_duplicate = strdup(str_original);
	printf("after strdup() = %s : %p\n", str_duplicate, str_duplicate);

	printf("before ft_strdup() = %s : %p\n", str_duplicate2, str_duplicate2);
	str_duplicate2 = ft_strdup(str_original1);
	printf("after ft_strdup() = %s : %p\n", str_duplicate2, str_duplicate2);
} */