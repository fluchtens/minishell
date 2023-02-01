/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:26:24 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/25 14:04:08 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*final;
	size_t	total_len;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (!len || str_len <= start)
		return (ft_strdup(""));
	total_len = str_len + start;
	if (total_len > len)
		total_len = len;
	final = malloc(sizeof(char) * (total_len + 1));
	if (!final)
		return (NULL);
	ft_strlcpy(final, s + start, total_len + 1);
	return (final);
}

/* int	main(void)
{
	printf("%s\n", ft_substr("Salut a tous, c'est lasalle!", 14, 50));
} */