/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:26:27 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/25 13:42:14 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start < end && ft_strchr(set, s1[start]))
		start++;
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	final = malloc(sizeof(char) * (end - start + 2));
	if (!final)
		return (NULL);
	ft_strlcpy(final, &s1[start], end - start + 2);
	return (final);
}

/* int	main(void)
{
	char	str[] = "Coucou les amis. Comment ca va ?";

	printf("%s\n", ft_strtrim(str, "Cou"));
	printf("%s\n", ft_strtrim(str, "Coucou "));
	printf("%s\n", ft_strtrim(str, "ca va ?"));
} */
